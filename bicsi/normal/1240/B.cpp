#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        
        vector<int> all = v;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        for (int i = 0; i < n; ++i) 
            v[i] = lower_bound(all.begin(), all.end(), v[i]) - all.begin();
        

        vector<int> first(all.size(), -1), last(all.size(), -1);
        for (int i = 0; i < n; ++i) {
            if (first[v[i]] == -1) 
                first[v[i]] = i;
            last[v[i]] = i;
        }
        /*
        cout << "DEBUG" << endl;
        for (int i = 0; i < (int)all.size(); ++i) {
            cout << first[i] << " " << last[i] << endl;
        }
        */
        int j = 0;
        int ans = 0;
        for (int i = 0; i < (int)all.size(); ++i) {
            j = max(j, i + 1);
            while (j < (int)all.size() && first[j] > last[j - 1])
                ++j;
            // cerr << i << ": " << j << endl;
            ans = max(ans, j - i);
        }
        cout << all.size() - ans << '\n';
    }

    return 0;
}