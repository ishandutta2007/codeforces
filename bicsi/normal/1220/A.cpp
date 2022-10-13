#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> cnt;
    for (auto& c : s) {
        cnt[c] += 1;
    }

    int z = cnt['z'];
    int o = cnt['n'];
    
    for (int i = 0; i < o; ++i) cout << 1 << " ";
    for (int i = 0; i < z; ++i) cout << 0 << " ";


    return 0;
}