#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, a[max_n], pos[max_n];
vector<int> x, y;

void make_swap(int p1, int p2) {
    assert(abs(p1 - p2) >= n / 2);
    swap(pos[a[p1]], pos[a[p2]]);
    swap(a[p1], a[p2]);
    x.push_back(p1 + 1);
    y.push_back(p2 + 1);
}

void write() {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (pos[i] == i) {
            continue;
        }
        if (pos[i] < n / 2) {
            make_swap(pos[i], n - 1);
            make_swap(n - 1, i);
        } else {
            if (i == 0) {
                make_swap(pos[i], 0);
                continue;
            }
            if (pos[i] + 1 == n) {
                make_swap(pos[i], i);
                continue;
            }
            make_swap(pos[i], 0);
            make_swap(0, n - 1);
            make_swap(i, n - 1);
            make_swap(pos[0], 0);
        }
    }
    for (int i = n / 2; i < n; ++i) {
        if (pos[i] == i) {
            continue;
        }
        make_swap(pos[i], 0);
        make_swap(0, i);
        make_swap(pos[0], 0);
    }
    for (int i = 0; i < n; ++i) {
        assert(a[i] == i);
    }
    printf("%d\n", x.size());
    for (int i = 0; i < x.size(); ++i) {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}