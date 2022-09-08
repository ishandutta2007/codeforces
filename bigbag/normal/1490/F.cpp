/**
 *  created: 16/02/2021, 16:48:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        map<int, int> cnt;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++cnt[a[i]];
        }
        vector<int> v;
        for (auto p : cnt) {
            v.push_back(p.second);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            ans = max(ans, (i + 1) * v[i]);
        }
        ans = n - ans;
        printf("%d\n", ans);
    }
    return 0;
}