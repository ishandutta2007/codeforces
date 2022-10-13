#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    int minn = 2e9, maxx = -2e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);   
    }

    if (minn * 2 >= maxx) {
        for (int i = 0; i < n; ++i) {
            cout << -1 << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < 2 * n; ++i) {
            a.push_back(a[i]);
        }

        vector<int> stk;
        vector<pair<int, int>> stk2;
        vector<int> dp(4 * n, 2e9);
        for (int i = 4 * n - 1; i >= 0; --i) {
            while (stk.size() && a[stk.back()] <= a[i]) 
                stk.pop_back();
            auto it = lower_bound(
                    stk2.begin(), stk2.end(), make_pair(a[i], -1));
            /* 
            cerr << "i: " << i + 1 << endl;
            for (int j = i; j < 2 * n; ++j) {
                cerr << a[j] << " ";
            }
            cerr << endl;
            cerr << "stk: "; for (auto x : stk) cerr << a[x] << " "; cerr << endl;
            cerr << "stk2: "; for (auto x : stk2) cerr << x.first << " "; cerr << endl;
            */
            if (it != stk2.begin()) {
                --it;
                assert(it->first < a[i]);

                if (stk.empty() || it->second < stk.back())
                    dp[i] = it->second;
                else if (stk.size())
                    dp[i] = dp[stk.back()];
            } else if (stk.size())
                dp[i] = dp[stk.back()];
            
            stk.push_back(i);
            
            // cerr << "> " << dp[i] << endl;

            while (stk2.size() && stk2.back().first >= 2 * a[i])
                stk2.pop_back();
            stk2.emplace_back(2 * a[i], i);
        }

        for (int i = 0; i < n; ++i) {
            cout << dp[i] - i << " ";
        }
        cout << endl;
    }

    return 0;
}