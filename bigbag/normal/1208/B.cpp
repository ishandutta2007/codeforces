#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int n, a[max_n], cnt[max_n];
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() == n) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < i; ++j) {
            ++cnt[a[j]];
            if (cnt[a[j]] > 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int j = n - 1; j >= i; --j) {
                ans = min(ans, j - i + 1);
                ++cnt[a[j]];
                if (cnt[a[j]] > 1) {
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}