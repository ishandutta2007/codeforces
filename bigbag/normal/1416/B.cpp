#include <bits/stdc++.h>

using namespace std;

const int max_n = 10111, inf = 1000111222;

int t, n, a[max_n];
vector<pair<pair<int, int>, int>> ans;

void op(int i, int j, int x) {
    a[i] -= x * i;
    a[j] += x * i;
    ans.push_back({{i, j}, x});
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (sum % n) {
            puts("-1");
            continue;
        }
        sum /= n;
        ans.clear();
        for (int i = n; i >= 2; --i) {
            if (a[i] >= i) {
                op(i, 1, a[i] / i);
                break;
            }
        }
        vector<pair<int, int>> d;
        for (int i = 2; i <= n; ++i) {
            d.push_back({(i - a[i] % i) % i, i});
        }
        sort(d.begin(), d.end());
        bool ok = 1;
        for (auto p : d) {
            if (a[1] < p.first) {
                ok = 0;
                break;
            }
            op(1, p.second, p.first);
            op(p.second, 1, a[p.second] / p.second);
        }
        if (!ok) {
            puts("-1");
        } else {
            for (int i = 2; i <= n; ++i) {
                op(1, i, sum);
            }
            printf("%d\n", ans.size());
            for (auto p : ans) {
                printf("%d %d %d\n", p.first.first, p.first.second, p.second);
            }
        }
    }
    return 0;
}