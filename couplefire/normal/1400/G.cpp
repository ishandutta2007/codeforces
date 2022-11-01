#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define MOD 998244353

int binpow(int a, int b) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = 1ll*res * a % MOD;
        a = 1ll*a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a){
    return binpow(a, MOD-2);
}

int dp[2][1<<20][41] = {{{0}}};
int n, m;
int li[MAXN], ri[MAXN];
pair<int, int> ed[20];
int fac[MAXN];
int arrl[MAXN] = {0};
int arrr[MAXN] = {0};
int invfac[MAXN];

int comb(int a, int b){
    if(b < 0) return 0;
    if(b > a) return 0;
    return 1ll*fac[a]*invfac[b]%MOD*invfac[a-b]%MOD;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fac[0] = 1;
    for(int i = 1; i<MAXN; i++) fac[i] = (1ll*fac[i-1]*i)%MOD;
    for(int i = 0; i<MAXN; i++) invfac[i] = inv(fac[i]);
    for(int i = 0; i<n; i++){
        cin >> li[i] >> ri[i];
        arrl[li[i]]++;
        arrr[ri[i]]++;
    }
    for(int i = 0; i<m; i++){
        cin >> ed[i].first >> ed[i].second;
        --ed[i].first; --ed[i].second;
    }
    dp[0][0][0] = 1;
    int len = 1<<m;
    for(int mask = 1; mask < len; ++mask){
        dp[0][mask][0] = 1;
        for(int num = 1; num<=2*m; num++){
            for(int q = 0; q<2; q++){
                int bb = 0;
                while(!(mask&(1<<bb)))++bb;
                int tmask = mask^(1<<bb);
                dp[q][mask][num] += dp[q][tmask][num];
                int a = ed[bb].first, b = ed[bb].second;
                int ttab = 0;
                int tta = 0;
                int ttb = 0;
                for(int i = 0; i<m; i++){
                    if(!(tmask&(1<<i))) continue;
                    if((ed[i].first != a && ed[i].first != b && ed[i].second != a && ed[i].second != b)) ttab ^= (1<<i);
                    if((ed[i].first != a && ed[i].second != a)) tta ^= (1<<i);
                    if((ed[i].first != b && ed[i].second != b)) ttb ^= (1<<i);
                }
                if(num >= 2){
                    dp[q][mask][num] += dp[1-q][ttab][num-2];
                    if(dp[q][mask][num] >= MOD) dp[q][mask][num] -= MOD;
                }
                dp[q][mask][num] += dp[1-q][tta][num-1]-dp[1-q][ttab][num-1];
                if(dp[q][mask][num] < 0) dp[q][mask][num] += MOD;
                if(dp[q][mask][num] >= MOD) dp[q][mask][num] -= MOD;
                dp[q][mask][num] += dp[1-q][ttb][num-1]-dp[1-q][ttab][num-1];
                if(dp[q][mask][num] < 0) dp[q][mask][num] += MOD;
                if(dp[q][mask][num] >= MOD) dp[q][mask][num] -= MOD;
                dp[q][mask][num] += (0ll+dp[1-q][tmask][num]-dp[1-q][tta][num]-dp[1-q][ttb][num]+dp[1-q][ttab][num])%MOD;
                if(dp[q][mask][num] < 0) dp[q][mask][num] += MOD;
                if(dp[q][mask][num] >= MOD) dp[q][mask][num] -= MOD;
            }
        }
    }
    int ans = 0;
    int tot = 0;
    for(int siz = 1; siz <= n; siz++){
        int mask = 0;
        tot += arrl[siz];
        tot -= arrr[siz-1];
        if(tot < siz) continue;
        for(int i = 0; i<m; i++){
            if(li[ed[i].first] <= siz && ri[ed[i].first] >= siz && li[ed[i].second] <= siz && ri[ed[i].second] >= siz) mask ^= (1<<i);
        }
        for(int i = 0; i<=2*m; i++){
            ans += 1ll*dp[0][mask][i]*comb(tot-i,siz-i)%MOD;
            if(ans >= MOD) ans -= MOD;
            ans -= 1ll*dp[1][mask][i]*comb(tot-i, siz-i)%MOD;
            if(ans < 0) ans += MOD;
        }
    }
    cout << ans << endl;
}