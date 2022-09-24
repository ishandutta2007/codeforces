#include "bits/stdc++.h"
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x...)
#endif
///////////////////////////////////////////
const int nax = 2.1e3;
int dp[nax][nax][2][2]; // dp[digits_formed][mod of formed no with m][careful lo][careful hi]

const int mod = 1e9 + 7;  //998244353;
void addTo(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
signed main(){  ios_base::sync_with_stdio(0); cin.tie(0);

    int m, d;
    cin >> m >> d;

    string lo, hi;
    cin >> lo >> hi;

    int n = lo.length();

    dp[0][0][1][1] = 1;

    for(int len{}; len < n; ++len){
        for(int mod{}; mod < m; ++mod){
            for(int clo: {0, 1}){
                for(int chi: {0, 1}) if (dp[len][mod][clo][chi]) {
                    int from = (clo? lo[len] - '0': 0), upto = (chi? hi[len] - '0': 9);
                    if(len & 1){
                        if(d < from || d > upto) continue;
                        from = upto = d;
                    }
                    for(int dgt{from}; dgt <= upto; ++dgt){
                        if((!(len & 1)) && dgt == d) continue;
                        int new_mod = (mod * 10 + dgt) % m;
                        int new_clo = (dgt > lo[len] - '0'? 0: clo), new_chi = (dgt < hi[len] - '0'? 0: chi);
                        addTo(dp[len + 1][new_mod][new_clo][new_chi], dp[len][mod][clo][chi]);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int clo: {0, 1}){
        for(int chi: {0, 1}){
            db(clo, chi, dp[n][0][clo][chi]);
            ans += dp[n][0][clo][chi];
        }
    }

    cout << ans << '\n';

    return 0;
}