#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int N = 105;

struct FastMOD{
    typedef unsigned long long ull;
    typedef __uint128_t L;
    ull b, m;
	FastMOD(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b;
		return r >= b ? r - b : r;
	}
}; FastMOD F(2);

int MOD;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return F.reduce(1ll*a*b);}
inline void grow(int &a, int b){a = mul(a, b);}

int nn, mm, kk, fac[N], comb[N][N], dp[N][N][N];

int dfs(int n, int m, int k){
    if(dp[n][m][k]>=0) return dp[n][m][k];
    if(k>n) return dp[n][m][k] = 0;
    if(n==0) return dp[n][m][k] = 1;
    if(m==1) return dp[n][m][k] = (k==1?fac[n]:0);
    dp[n][m][k] = 0;
    for(int i = 1; i<=n; ++i){
        int tmp = 0;
        for(int j = 0; j<=k; ++j)
            inc(tmp, mul(dfs(i-1, m-1, j), dfs(n-i, m-1, k-j)));
        inc(dp[n][m][k], mul(tmp, comb[n-1][i-1]));
    }
    return dp[n][m][k];
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> nn >> mm >> kk >> MOD; F = FastMOD(MOD);
    memset(dp, -1, sizeof dp);
    fac[0] = 1;
    for(int i = 1; i<=nn; ++i)
        fac[i] = mul(fac[i-1], i);
    comb[0][0] = 1;
    for(int i = 1; i<=nn; ++i){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j<i; ++j)
            comb[i][j] = add(comb[i-1][j-1], comb[i-1][j]);
    } cout << dfs(nn, mm, kk) << '\n';
}