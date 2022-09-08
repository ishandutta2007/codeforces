#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, a[max_n], cnt[max_n];
vector<pair<int, int>> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l;
        scanf("%d", &l);
        for (int j = 0; j < l; ++j) {
            scanf("%d", &a[j]);
        }
        bool ok = true;
        for (int j = 0; j + 1 < l; ++j) {
            if (a[j] < a[j + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            v.push_back({a[0], a[l - 1]});
            ++cnt[a[0]];
        }
    }
    long long ans = 1LL * n * n;
    for (int i = 1; i < max_n; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (const auto &p : v) {
        ans -= cnt[p.second];
    }
    printf("%I64d\n", ans);
    return 0;
}