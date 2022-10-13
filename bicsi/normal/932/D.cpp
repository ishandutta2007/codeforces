#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q; cin >> q;
    vector<vector<int>> link1, link2;
    vector<vector<long long>> dp1, dp2;

    auto Add = [&](int par, int w) {
        int node = link1.size();

        link1.push_back(vector<int>(20, -1));
        link2.push_back(vector<int>(20, -1));
        dp1.push_back(vector<long long>(20, -1));
        dp2.push_back(vector<long long>(20, -1));

        // Remake link1, dp1
        link1[node][0] = par;
        dp1[node][0] = w;
        for (int i = 1; i < 20; ++i) {
            int anc = link1[node][i - 1];
            dp1[node][i] = dp1[node][i - 1];

            if (anc != -1) {
               link1[node][i] = link1[anc][i - 1];
               dp1[node][i] = max(dp1[node][i], dp1[anc][i - 1]); 
            }
        }
        
        // Find link2
        int anc = par;
        for (int i = 19; i >= 0; --i) {
            if (anc != -1 && dp1[anc][i] < w) 
                anc = link1[anc][i];    
        }
        link2[node][0] = anc;
        dp2[node][0] = w;

        // Remake link2, dp2
        for (int i = 1; i < 20; ++i) {
            int anc = link2[node][i - 1];
            dp2[node][i] = dp2[node][i - 1];
            
            if (anc != -1) {
                link2[node][i] = link2[anc][i - 1];
                dp2[node][i] += dp2[anc][i - 1];
            }
        }
    };

    auto Query = [&](int node, long long x) {
        int ans = 0;
        for (int i = 19; i >= 0; --i) {
            if (link2[node][i] != -1 && dp2[node][i] <= x) {
                ans += (1 << i);
                x -= dp2[node][i];
                node = link2[node][i];
            }
        }
        if (dp2[node][0] <= x)
            ans += 1;
        return ans;
    };

    Add(-1, 0);
    long long last = 0;
    while (q--) {
        int t;
        long long p, q; 
        cin >> t >> p >> q;
        if (t == 1) {
            int R = (p ^ last);
            int W = (q ^ last);
            Add(R - 1, W);
        } else {
            int R = (p ^ last);
            long long X = (q ^ last);
            last = Query(R - 1, X);
            cout << last << '\n';
        }
//        cerr << "OK\n";
    }


    return 0;
}