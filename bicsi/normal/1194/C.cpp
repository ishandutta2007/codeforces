#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q; cin >> q;
    while (q--) {
        auto ans = [&]() {
        string s, t, p; cin >> s >> t >> p;
        map<char, int> need;

        int j = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            while (true) {
                if (j == t.size()) {
                    return false;
                }
                if (s[i] == t[j]) {
                    ++j; break;
                }
                need[t[j]] += 1;
                ++j;
            }
        }

        while (j < t.size()) {
            need[t[j]] += 1;
            ++j;
        }

        for (auto x : p) {
            need[x] -= 1;
        }

        for (auto p : need) {
            if (p.second > 0) 
                return false;
        }

        return true;
        }();

        if (ans) cout << "YES\n";
        else cout << "NO\n";

    }


    return 0;
}