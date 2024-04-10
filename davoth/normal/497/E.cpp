#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,k,f,p[62],ans,g;
template<ll sz>
struct Mat{
    ll n,mat[sz][sz];
    Mat(){
        ll x;
    }
    Mat(ll n){
        this->n=n;
        memset(mat,0,sizeof mat);
    }
    friend Mat operator*(Mat x, Mat y){
        Mat ans(x.n);
        for(ll i=0; i<x.n; i++){
            for(ll j=0; j<x.n; j++){
                for(ll k=0; k<x.n; k++){
                    ans.mat[i][j]=(ans.mat[i][j]+x.mat[i][k]*y.mat[k][j])%MOD;
                }
            }
        }
        return ans;
    }
    friend Mat nxt(Mat x, ll y){
        Mat ans(x.n);
        for(ll i=0; i<=k; i++){
            ll t=(i+y)%k;
            if(i==k) t=k;
            for(ll j=0; j<=k; j++){
                ll z=(j+y)%k;
                if(j==k) z=k;
                ans.mat[t][z]=x.mat[i][j];
            }
        }
        return ans;
    }
};
int main(){
    fast_io;
    cin >> n >> k;
    p[0]=1;
    while(n>=p[f]){
        f++;
        p[f]=p[f-1]*k;
    }
    Mat<31> tp(k+1);
    for(ll j=0; j<=k; j++) tp.mat[j][j]=tp.mat[j][0]=1;
    Mat<31> dp[f][k+1];
    dp[0][1]=tp;
    for(ll i=2; i<=k; i++){
        tp=nxt(tp,1);
        dp[0][i]=dp[0][i-1]*tp;
    }
    for(ll i=1; i<f; i++){
        dp[i][1]=tp=dp[i-1][k];
        for(ll j=2; j<=k; j++){
            tp=nxt(tp,1);
            dp[i][j]=dp[i][j-1]*tp;
        }
    }
    ll x=0;
    Mat<31> an;
    for(ll i=f; i--;){
        ll t=n/p[i];
        n%=p[i];
        if(!t) continue;
        if(!g) an=dp[i][t],g=1;
        else{
            an=an*nxt(dp[i][t],x);
        }
        x=(x+t)%MOD;
    }
    for(ll i=0; i<=k; i++) ans=(ans+an.mat[k][i])%MOD;
    cout << ans << '\n';
    return 0;
}