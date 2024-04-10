#pragma GCC optimize("Ofast")
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
int MOD = 1000000007;

int binom[405][405];
int qpow(int b, int e) {
	int ans = 1;
	while(e) {
		if(e & 1) ans = 1ll * ans * b % MOD;
		b = 1ll * b * b % MOD;
		e >>= 1;
	}
	return ans;
}
int fac[405],ifac[405];

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
    ull b, m;
    FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
    ull reduce(ull a) {
        ull q = (ull)((L(m) * a) >> 64);
        ull r = a - q * b; // can be proven that 0 <= r < 2*b
        return r >= b ? r - b : r;
    }
};
FastMod F(2);
int n;
struct val {
    ll ans[405];
    int mx=1;
    val(){rep(i,402)ans[i]=0;}
    void operator+=(const val& o){
        rep(i,n+1){
            ans[i]+=o.ans[i];
            ans[i]-=(ans[i]>=MOD?MOD:0);
        }
        mx=max(mx,o.mx);
    }
    val operator*(const val&o)const {
        val res;
        rep(i,mx+1){
            rep(j,o.mx+1)
                res.ans[i+j]=(res.ans[i+j]+ans[i]*o.ans[j]);
            if(i%9==0)rep(j,i+o.mx+1)res.ans[j]=F.reduce(res.ans[j]);
        }
        res.mx=mx+o.mx;
        rep(j,res.mx+1)res.ans[j]%=MOD;
        return res;
    }
    void shif(){
        for(int i=mx+1;i>=1;i--)ans[i]=1ll*ans[i-1]*fac[i-1]%MOD*ifac[i]%MOD;
        ans[0]=0;mx++;
    }
};

val dp[2][405];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>MOD;
    F=FastMod(MOD);
    fac[0]=ifac[0]=1;
    rep1(i,n){
        fac[i]=1ll*fac[i-1]*i%MOD;
        ifac[i]=qpow(fac[i],MOD-2);
    }
    binom[0][0]=1;
    rep1(i,n){
        rep(j,i+1){
            binom[i][j]=binom[i-1][j];
            if(j)(binom[i][j]+=binom[i-1][j-1])%=MOD;
        }
    }
    dp[0][1].ans[0]=1;
    iter(L,2,n+1){
        auto&x=dp[0][L];
        rep(m,L){
            if(m*2+1>=L)break;
            if(m==0)x+=dp[0][L-m-1];
            else if(m==L-1)x+=dp[0][m];
            else x+=dp[0][m]*dp[0][L-m-1];
        }
        x+=x;
        if(L%2)x+=dp[0][L/2]*dp[0][L-L/2-1];
        x.shif();
    }
    dp[1][1].ans[1]=1;
    iter(L,2,n+1){
        auto&x=dp[1][L];
        rep(m,L){
            if(m==0)x+=dp[1][L-m-1];
            else if(m==L-1)x+=dp[0][m];
            else x+=dp[0][m]*dp[1][L-m-1];
        }
        x.shif();
        // cout<<L<<endl;
    }
    auto&x=dp[0][n+1];
    int L=n;
    rep(m,L){
        if(m==0)x+=dp[1][L-m-1];
        else if(m==L-1)x+=dp[1][m];
        else x+=dp[1][m]*dp[1][L-m-1];
    }
    x.shif();
    int s=0;
    rep(i,n+1)x.ans[i]=1ll*x.ans[i]*fac[i]%MOD;
    rep(i,n+1)(s+=x.ans[i])%=MOD;
    cout<<s<<endl;
    // cout<<dfs(n,0,0)<<endl;
}