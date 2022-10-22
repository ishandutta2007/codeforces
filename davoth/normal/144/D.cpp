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
    ll res=pow(x,y/2);
    return (y%2==0 ? res*res%mod : (res*res%mod)*x%mod);
}
vector<pair<ll,ll> > adj[N];
ll n,m,s,l;
int main() {
    fast_io;
    cin >> n >> m >> s;
    pair<pair<ll,ll>,ll> M[m];
    for(int i=0; i<m; i++){
        int v,u,w;
        cin >> v >> u >> w;
        adj[v].push_back({u,w});
        adj[u].push_back({v,w});
        M[i]={{v,u},w};
    }
    cin >> l;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
    ll dist[N];
    ll par[N];
    memset(dist,63,sizeof dist);
    q.push({0,s});
    dist[s]=0;
    par[s]=-1;
    while(!q.empty()){
        auto p=q.top();
        q.pop();
        for(auto u : adj[p.S]){
            if(dist[u.F]<=p.F+u.S) continue;
            dist[u.F]=p.F+u.S;
            par[u.F]=p.S;
            q.push({dist[u.F],u.F});
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        if(dist[i]==l){
            ans++;
        }
    }
    for(int i=0; i<m; i++){
        int V=dist[M[i].F.F],U=dist[M[i].F.S],k=M[i].S;
        for(int j=1; j<k; j++){
            if(min(V+j,U+k-j)==l) ans++;
        }
    }
    cout << ans;
    return 0;
}