/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=1e3+10,LN=60,M=4e6+10,SQ=500,BS=737,inf=1.05e9,NSQ=N/SQ+1;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,a[N],b[N][N],c[10],k,sz[N],p[N],q[N],dp[N][N],ans,d[11],cur[10],an;
string s;
int main(){
    fast_io;
    cin >> s >> n;
    k=s.size();
    reverse(s.begin(),s.end());
    for(ll i=0; i<k; i++){
        if(s[i]=='?') a[i+1]=-1;
        else a[i+1]=s[i]-'0';
    }
    for(ll i=1; i<=n; i++){
        cin >> s;
        reverse(s.begin(),s.end());
        sz[i]=s.size();
        for(ll j=0; j<sz[i]; j++) b[i][j+1]=s[j]-'0';
        p[i]=q[i]=i;
    }
    for(ll i=0; i<10; i++) cin >> c[i];
    memset(dp,-1,sizeof dp);
    dp[0][n+1]=0;
    for(ll i=1; i<=k; i++){
        memset(d,0,sizeof d);
        memset(cur,0,sizeof cur);
        for(ll j=1; j<=n; j++){
            d[b[j][i]]++;
            for(ll x=0; x<10; x++){
                cur[x]+=c[(b[j][i]+x)%10];
            }
        }
        for(ll j=1; j<=10; j++) d[j]+=d[j-1];
        for(ll j=n+1; j; j--){
            if(j<=n){
                d[b[p[j]][i]]--;
                for(ll x=0; x<10; x++){
                    cur[x]-=c[(b[p[j]][i]+x)%10];
                    cur[x]+=c[(b[p[j]][i]+x+1)%10];
                }
            }
            if(dp[i-1][j]==-1) continue;
            for(ll x=0; x<10; x++){
                if((a[i]!=-1 && x!=a[i]) || (i==k && x==0)) continue;
                ll k=n+1-d[10]+d[10-x-1];
                dp[i][k]=max(dp[i][k],dp[i-1][j]+cur[x]);
            }
        }
        sort(p+1,p+n+1,[&](ll &x, ll &y){return (b[x][i]<b[y][i] || (b[x][i]==b[y][i] && q[x]<q[y]));});
        for(ll j=1; j<=n; j++) q[p[j]]=j;
    }
    for(ll i=1; i<=n; i++) for(ll j=k+1; j<=sz[i]; j++) an+=c[b[i][j]];
    for(ll i=n+1; i; i--){
        if(i<=n){
            if(k+1<=sz[p[i]]) an-=c[b[p[i]][k+1]];
            b[p[i]][k+1]++;
            ll ptr=k+1;
            while(b[p[i]][ptr]==10){
                an+=c[0];
                ptr++;
                if(ptr<=sz[p[i]]) an-=c[b[p[i]][ptr]];
                b[p[i]][ptr]++;
            }
            an+=c[b[p[i]][ptr]];
        }
        if(dp[k][i]>-1) ans=max(ans,an+dp[k][i]);
    }
    cout << ans << '\n';
    return 0;
}