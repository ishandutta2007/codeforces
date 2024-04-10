#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=19,M=1.1e7+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=/*1000000007*/ 998244353;
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
ll n,a[11][11],dx[]={1,-1,2,2,1,-1,-2,-2},dy[]={2,2,1,-1,-2,-2,1,-1};
pll dp[120][120][3][3],pd[120][3];
pll b[120];
vector<ll> adj[120][3];
priority_queue<pair<pll,pll>,vector<pair<pll,pll>>,greater<pair<pll,pll>>> pq;
int main(){
    fast_io;
    cin >> n;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            cin >> a[i][j];
            b[a[i][j]]={i,j};
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            for(ll k=1; k<=n; k++){
                ll ni,nj;
                adj[a[i][j]][0].pb(a[i][k]);
                adj[a[i][j]][0].pb(a[k][j]);
                ni=i+k;
                nj=j+k;
                if(ni>=1 && nj>=1 && ni<=n && nj<=n) adj[a[i][j]][2].pb(a[ni][nj]);
                ni=i+k;
                nj=j-k;
                if(ni>=1 && nj>=1 && ni<=n && nj<=n) adj[a[i][j]][2].pb(a[ni][nj]);
                ni=i-k;
                nj=j+k;
                if(ni>=1 && nj>=1 && ni<=n && nj<=n) adj[a[i][j]][2].pb(a[ni][nj]);
                ni=i-k;
                nj=j-k;
                if(ni>=1 && nj>=1 && ni<=n && nj<=n) adj[a[i][j]][2].pb(a[ni][nj]);
            }
            for(ll k=0; k<8; k++){
                ll ni=i+dx[k],nj=j+dy[k];
                if(ni<1 || nj<1 || ni>n || nj>n) continue;
                adj[a[i][j]][1].pb(a[ni][nj]);
            }
        }
    }
    for(ll j=1; j<=n*n; j++){
        for(ll i=1; i<=n*n; i++) for(ll k=0; k<3; k++) dp[j][i][k][0]=dp[j][i][k][1]=dp[j][i][k][2]={INF,INF};
        pd[j][0]=pd[j][1]=pd[j][2]={INF,INF};
    }
    for(ll q=1; q<=n*n; q++){
        for(ll g=0; g<3; g++){
            dp[q][q][g][g]={0,0};
            pq.push({{0,0},{q,g}});
            while(!pq.empty()){
                auto [t,p]=pq.top();
                pq.pop();
                auto [v,c]=p;
                if(t!=dp[q][v][g][c]) continue;
                for(ll u : adj[v][c]){
                    pll p=t;
                    p.F++;
                    if(p<dp[q][u][g][c]){
                        dp[q][u][g][c]=p;
                        pq.push({p,{u,c}});
                    }
                }
                for(ll i=1; i<3; i++){
                    ll d=(c+i)%3;
                    pll p=t;
                    p.S++;
                    p.F++;
                    if(dp[q][v][g][d]>p){
                        dp[q][v][g][d]=p;
                        pq.push({p,{v,d}});
                    }
                }
            }
        }
    }
    pd[1][2]=pd[1][1]=pd[1][0]={0,0};
    for(ll i=2; i<=n*n; i++){
        for(ll j=0; j<3; j++){
            for(ll k=0; k<3; k++){
                pll p=dp[i-1][i][j][k];
                //cout << i-1 << ' ' << i << ' ' << j << ' ' << k << ' ' << p.F << ' ' << p.S << '\n';
                p.F+=pd[i-1][j].F;
                p.S+=pd[i-1][j].S;
                pd[i][k]=min(pd[i][k],p);
            }
        }
    }
    pll p=min({pd[n*n][0],pd[n*n][1],pd[n*n][2]});
    cout << p.F << ' ' << p.S << '\n';
    return 0;
}