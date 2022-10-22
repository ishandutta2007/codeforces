#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=y/2;
    b+=y%2;
    return (pow(x,a,mod)*pow(x,b,mod))%mod;
}
ll n,m,k;
vector<pair<int,int> > adj[N];
vector<pair<pair<int,int>,int> > A[N];
int main() {
    fast_io;
    int n;
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    for(int i=0; i<k; i++){
        int u,w;
        cin >> u >> w;
        A[1].push_back({{u,w},i});
        A[u].push_back({{1,w},i});
    }
    ll dist[N];
    ll mark[N];
    memset(dist,63,sizeof dist);
    memset(mark,-1,sizeof mark);
    dist[1]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >,greater< > > q;
    q.push({0,1});
    while(!q.empty()){
        ll v=q.top().S,w=q.top().F;
        q.pop();
        if(dist[v]<w) continue;
        for(auto p : adj[v]){
            ll u=p.F,wp=p.S;
            if(wp+dist[v]<dist[u]){
                dist[u]=wp+dist[v];
                mark[u]=-1;
                q.push({dist[u],u});
            }else if(wp+dist[v]==dist[u] && mark[u]!=-1){
                mark[u]=-1;
            }
        }
        for(auto p : A[v]){
            ll u=p.F.F,wp=p.F.S;
            if(dist[u]<=dist[v]+wp) continue;
            dist[u]=dist[v]+wp;
            mark[u]=p.S;
            q.push({dist[u],u});
        }
    }
    int cnt=0;
    bool flag[k];
    memset(flag,0,sizeof flag);
    for(int i=1; i<=n; i++) if(mark[i]!=-1) flag[mark[i]]=true;
    for(int i=0; i<k; i++) if(flag[i]) cnt++;
    cout << k-cnt << '\n';
    return 0;
}