#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e2+10,LN=50,M=1e5+10,SQ=350,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll C[N][26],F[N],ts,Q[N],R,L,a[N],A[N],dp[LN][N][N],ans[2][N][N],n,tl;
string S[N];
void AddTrie(ll i){
    int v=0;
    for (char ch:S[i]){
        if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
        v=C[v][ch-'a'];
    }
    a[v]+=A[i];
}
void BuildAho(){
    for (int i=0; i<26; i++) if (C[0][i]) Q[R++]=C[0][i];
    while (L<R){
        int v=Q[L++];
        a[v]+=a[F[v]];
        for (int i=0; i<26; i++){
            if (!C[v][i]) C[v][i]=C[F[v]][i];
            else{
                F[C[v][i]]=C[F[v]][i];
                Q[R++]=C[v][i];
            }
        }
    }
}
int main(){
    fast_io;
    cin >> n >> tl;
    for(ll i=1; i<=n; i++) cin >> A[i];
    for(ll i=1; i<=n; i++){
        cin >> S[i];
        AddTrie(i);
    }
    BuildAho();
    memset(dp,-1,sizeof dp);
    for(ll i=0; i<=ts; i++){
        for(ll j=0; j<26; j++){
            dp[0][i][C[i][j]]=a[C[i][j]];
        }
    }
    for(ll l=1; l<LN; l++){
        for(ll i=0; i<=ts; i++){
            for(ll j=0; j<=ts; j++){
                for(ll k=0; k<=ts; k++){
                    if(dp[l-1][i][k]!=-1 && dp[l-1][k][j]!=-1) dp[l][i][j]=max(dp[l][i][j],dp[l-1][i][k]+dp[l-1][k][j]);
                }
            }
        }
    }
    bool f=0;
    for(ll l=0; l<LN; l++){
        if((1ll<<l)&tl){
            if(!f){
                f=1;
                for(ll i=0; i<=ts; i++){
                    for(ll j=0; j<=ts; j++) ans[0][i][j]=dp[l][i][j];
                }
            }else{
                for(ll i=0; i<=ts; i++){
                    for(ll j=0; j<=ts; j++){
                        ans[1][i][j]=-1;
                        for(ll k=0; k<=ts; k++){
                            if(ans[0][i][k]!=-1 && dp[l][k][j]!=-1) ans[1][i][j]=max(ans[1][i][j],ans[0][i][k]+dp[l][k][j]);
                        }
                    }
                }
                for(ll i=0; i<=ts; i++){
                    for(ll j=0; j<=ts; j++){
                        ans[0][i][j]=ans[1][i][j];
                    }
                }
            }
        }
    }
    ll an=0;
    for(ll i=0; i<=ts; i++) an=max(an,ans[0][0][i]);
    cout << an << '\n';
    return 0;
}