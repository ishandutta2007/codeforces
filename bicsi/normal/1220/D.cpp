#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<long long>> cnt(100);
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        long long xx = x;
        int pw = 0;
        while (x % 2 == 0) pw += 1, x /= 2;
        cnt[pw].push_back(xx);
    }

    int ans = -1, choose = -1;
    for (int i = 0; i < 100; ++i) {
        if (ans < (int)cnt[i].size()) {
            ans = cnt[i].size();
            choose = i;
        }
        ans = max(ans, (int)cnt[i].size());
    }
    cout << n - ans << endl;
    if (n - ans == 0) return 0;
    for (int i = 0; i < 100; ++i) {
        if (i == choose) continue;
        for (auto x : cnt[i])
                cout << x << " ";
    }
    cout << endl;
    return 0;
}