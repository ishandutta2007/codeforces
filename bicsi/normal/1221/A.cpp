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
        bool ok = false;
        while (v.size()) {
            sort(v.rbegin(), v.rend());
            int last = v.back();
            v.pop_back();
            if (last == 2048) {
                ok = true;
                break;
            }
            if (last > 2048) break;
            if (v.empty()) break;
            if (last == v.back())
                v.back() *= 2;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}