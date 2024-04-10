#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
const int MOD = 1000000007;

inline int add(int x, int y){return x+y>=MOD?x+y-MOD:x+y;}
inline int sub(int x, int y){return x-y<0?x-y+MOD:x-y;}
inline int mul(int x, int y){return 1ll*x*y%MOD;}
inline void inc(int &x, int y){x = add(x, y);}
inline void dec(int &x, int y){x = sub(x, y);}
inline void grow(int &x, int y){x = mul(x, y);}

int bpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) grow(res, a);
        grow(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x){return bpow(x, MOD-2);}

int n, m, p, k;
int f[N], dp[N][N], sdp[N][N], sf[N], sfdp[N], fact[100005];

int comb(int a, int b){
    return mul(fact[a], mul(inv(fact[b]), inv(fact[a-b])));
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int _a, _b; cin >> _a >> _b;
    p = mul(_a, inv(_b));
    cin >> k;
    fact[0] = 1; for(int i = 1; i<=k; i++) fact[i] = mul(fact[i-1], i);
    for(int i = 0; i<=min(k, m); i++)
        f[i] = mul(comb(k, i), mul(bpow(p, i), bpow(sub(1, p), k-i)));
    sf[0] = f[0];
    for(int i = 1; i<=m; i++)
        sf[i] = add(sf[i-1], f[i]);
    dp[0][m] = sdp[0][m] = 1;
    for(int i = 1; i<=n; i++){
        memset(sfdp, 0, sizeof sfdp);
        for(int r = 1; r<=m; r++)
            sfdp[r] = add(sfdp[r-1], mul(f[r], sdp[i-1][r]));
        for(int r = 1; r<=m; r++)
            dp[i][r] = mul(f[m-r], sub(mul(sf[r-1], sub(sdp[i-1][m], sdp[i-1][m-r])), sfdp[r-1]));
        for(int r = 1; r<=m; r++)
            sdp[i][r] = add(sdp[i][r-1], dp[i][r]);
    }
    cout << sdp[n][m] << endl;
}