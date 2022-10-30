#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
const int MOD = 1000000007;
const int I3 = (MOD+1)/3;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    for(; b; grow(a, a), b>>=1)
        if(b&1) grow(res, a);
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int n, q, fact[3*N], ifact[3*N], dp[2][3*N];

int comb(int a, int b){
    return mul(fact[a], mul(ifact[b], ifact[a-b]));
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    fact[0] = 1;
    for(int i = 1; i<3*N; ++i)
        fact[i] = mul(fact[i-1], i);
    ifact[3*N-1] = inv(fact[3*N-1]);
    for(int i = 3*N-2; i>=0; --i)
        ifact[i] = mul(ifact[i+1], i+1);
    dp[0][0] = dp[1][0] = n;
    for(int i = 1; i<=3*n; ++i){
        dp[0][i] = sub(comb(3*n+2, i+1), add(mul(2, dp[0][i-1]), dp[1][i-1]));
        dp[1][i] = sub(add(comb(3*n+2, i+1), dp[0][i-1]), dp[1][i-1]);
        if(i==1) dec(dp[1][i], 1), dec(dp[0][i], 1);
        grow(dp[0][i], I3);
        grow(dp[1][i], I3);
    }
    while(q--){
        int a; cin >> a;
        cout << dp[1][a] << '\n';
    }
}