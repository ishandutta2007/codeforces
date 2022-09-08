/**
 *  created: 24/08/2021, 18:03:31
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 2222, inf = 1000111222;

int t, n, a[max_n];

pair<int, int> get_pos(int n) {
    int pos_n, pos_n1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == n) {
            pos_n = i;
        }
        if (a[i] == n - 1) {
            pos_n1 = i;
        }
    }
    return {pos_n, pos_n1};
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 != i % 2) {
            puts("-1");
            return;
        }
    }
    vector<int> ans;
    for (int x = n; x > 1; x -= 2) {
        {
            auto [pos_n, pos_n1] = get_pos(x);
            ans.push_back(pos_n);
            reverse(a + 1, a + ans.back() + 1);
        }
        auto [pos_n, pos_n1] = get_pos(x);
        assert(pos_n == 1);
        if (pos_n1 != 2) {
            ans.push_back(pos_n1 - 1);
            reverse(a + 1, a + ans.back() + 1);
            {
                auto [pos_n, pos_n1] = get_pos(x);
                assert(pos_n + 1 == pos_n1);
                assert(pos_n1 + 1 <= x);
                ans.push_back(pos_n1 + 1);
                reverse(a + 1, a + ans.back() + 1);

                ans.push_back(3);
                reverse(a + 1, a + ans.back() + 1);
            }
        }
        assert(a[1] == x && a[2] == x - 1);
        ans.push_back(x);
        reverse(a + 1, a + ans.back() + 1);
    }
    for (int i = 1; i <= n; ++i) {
        assert(a[i] == i);
    }
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        if (0) {
            n = rnd(1, 10) * 2 + 1;
            for (int i = 1; i <= n; ++i) {
                a[i] = i;
            }
            shuffle(a + 1, a + n + 1, generator);
            cout << "in" << endl;
            cout << n << endl;
            for (int i = 1; i <= n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            scanf("%d", &n);
            for (int i = 1; i <= n; ++i) {
                scanf("%d", &a[i]);
            }
        }
        solve();

    }
    return 0;
}