#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=8e1+10,LN=20,M=2e4+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
int n,L[N],R[N];
ld ans[N][N],dp[8][N][N];
vector<int> vec;
void solve(int l, int r, int k, int d){
    if(r-l==1){
        ld p=0;
        if(k>=L[l] && k<=R[l]){
            p=1.0*(vec[k]-vec[k-1])/(vec[R[l]]-vec[L[l]-1]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; i+j<n; j++){
                ans[l][i+1]+=dp[d][i][j]*p/(j+1);
                ans[l][i+j+2]-=dp[d][i][j]*p/(j+1);
            }
        }
        return;
    }
    int m=(l+r)>>1;
    for(int i=0; i<n; i++){
        for(int j=0; i+j<n; j++){
            dp[d+1][i][j]=dp[d][i][j];
        }
    }
    for(int t=m; t<r; t++){
        for(int i=n-1; i>=0; i--){
            for(int j=n-1-i; j>=0; j--){
                ld p=0,q=0;
                if(L[t]<k){
                    p=1.0*(vec[min(k-1,R[t])]-vec[L[t]-1])/(vec[R[t]]-vec[L[t]-1]);
                }
                if(k>=L[t] && k<=R[t]) q=1.0*(vec[k]-vec[k-1])/(vec[R[t]]-vec[L[t]-1]);
                dp[d+1][i][j]*=1-p-q;
                if(i) dp[d+1][i][j]+=dp[d+1][i-1][j]*p;
                if(j) dp[d+1][i][j]+=dp[d+1][i][j-1]*q;
            }
        }
    }
    solve(l,m,k,d+1);
    for(int i=0; i<n; i++){
        for(int j=0; i+j<n; j++){
            dp[d+1][i][j]=dp[d][i][j];
        }
    }
    for(int t=l; t<m; t++){
        for(int i=n-1; i>=0; i--){
            for(int j=n-1-i; j>=0; j--){
                ld p=0,q=0;
                if(L[t]<k){
                    p=1.0*(vec[min(k-1,R[t])]-vec[L[t]-1])/(vec[R[t]]-vec[L[t]-1]);
                }
                if(k>=L[t] && k<=R[t]) q=1.0*(vec[k]-vec[k-1])/(vec[R[t]]-vec[L[t]-1]);
                dp[d+1][i][j]*=1-p-q;
                if(i) dp[d+1][i][j]+=dp[d+1][i-1][j]*p;
                if(j) dp[d+1][i][j]+=dp[d+1][i][j-1]*q;
            }
        }
    }
    solve(m,r,k,d+1);
}
int main(){
    fast_io;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> L[i] >> R[i];
        vec.pb(L[i]);
        vec.pb(R[i]);
    }
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    for(int i=1; i<=n; i++){
        L[i]=lower_bound(vec.begin(),vec.end(),L[i])-vec.begin()+1;
        R[i]=lower_bound(vec.begin(),vec.end(),R[i])-vec.begin();
    }
    dp[0][0][0]=1;
    for(int i=1; i<vec.size(); i++){
        solve(1,n+1,i,0);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans[i][j]+=ans[i][j-1];
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}