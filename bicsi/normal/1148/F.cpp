#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    

    while (true) { 
        
        int n; cin >> n;
        vector<pair<int, int>> v;
        int csum = 0;
        for (int i = 0; i < n; ++i) {
            int val, msk; cin >> val >> msk;
            v.emplace_back(msk, val);
            csum += val;
        }
        //cerr << "csum: " << csum << endl;
        /*
        int n = 100;     
        vector<pair<int, int>> v;
        int csum = 0;
        for (int i = 0; i < n; ++i) {
            int val = rand() % 100000 - 50000, msk = rand() % 100000 + 1;
            v.emplace_back(msk, val);
            csum += val;
        }
        if (csum == 0) continue;
        */
        sort(v.begin(), v.end());
        int at = 0;
        int s = 0;
        for (int bit = 0; at < n; ++bit) {
            int lim = (1LL << (bit + 1));
            s |= (1LL << bit);
            int add = 0;
            while (at < n && v[at].first < lim) {
                int now = s & v[at].first;
                if (__builtin_popcountll(now) % 2) add -= v[at].second;
                else add += v[at].second;
                ++at;
            }
            if (csum > 0 && add > 0 || csum < 0 && add < 0) {
                s ^= (1LL << bit);
            }
        }
        
        int chk = 0;
        for (int i = 0; i < n; ++i) {
            int now = s & v[i].first;
            if (__builtin_popcountll(now) % 2) chk -= v[i].second;
            else chk += v[i].second;
        }
        // cerr << "chk: " << chk << endl;
        //assert(chk < 0);
        cout << s << endl;
        break;
    }

    return 0;
}