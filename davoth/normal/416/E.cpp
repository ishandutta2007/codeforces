#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=505;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll= pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=y/2;
    b+=y%2;
    return (pow(x,a,mod)*pow(x,b,mod))%mod;
}
int n,m;
pair<ll,pll> edge[N*N/2];
ll dist[N][N];
ll upd[N][N];
int main() {
    fast_io;
    cin >> n >> m;
    memset(dist,63,sizeof dist);
    for(int i=1; i<=n; i++) dist[i][i]=0;
    for(int i=0; i<m; i++){
        ll v,u,w;
        cin >> v >> u >> w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=dist[u][v];
        edge[i]={w,{v,u}};
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    for(int i=0; i<m; i++){
        ll u1=edge[i].S.F,u2=edge[i].S.S,w=edge[i].F;
        for(int v=1; v<=n; v++){
            if(dist[v][u2]==dist[v][u1]+w) upd[v][u2]++;
            if(dist[v][u1]==dist[v][u2]+w) upd[v][u1]++;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ll cnt=0;
            for(int k=1; k<=n; k++){
                if(dist[i][k]+dist[k][j]==dist[i][j]) cnt+=upd[i][k];
            }
            cout << cnt << ' ';
        }
    }
    return 0;
}