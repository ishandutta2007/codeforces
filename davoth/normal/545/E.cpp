#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10;
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
vector<pair<pair<int,ll>,int> > adj[N];
int n,m;
int main() {
    fast_io;
    cin >> n >> m;
    int W[m+1];
    for(int i=1; i<=m; i++){
        int v,u,w;
        cin >> v >> u >> w;
        adj[v].push_back({{u,w},i});
        adj[u].push_back({{v,w},i});
        W[i]=w;
    }
    int x;
    cin >> x;
    ll dist[n+2];
    memset(dist,63,sizeof dist);
    dist[x]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
    int par[n+2];
    memset(par,-1,sizeof par);
    q.push({0,x});
    while(!q.empty()){
        auto p=q.top();
        q.pop();
        if(dist[p.S]<p.F) continue;
        for(auto u : adj[p.S]){
            if(dist[u.F.F]>p.F+u.F.S){
                dist[u.F.F]=p.F+u.F.S;
                par[u.F.F]=u.S;
                q.push({dist[u.F.F],u.F.F});
            }else if(dist[u.F.F]==p.F+u.F.S && W[par[u.F.F]]>u.F.S) par[u.F.F]=u.S;
        }
    }
    ll sum=0;
    for(int i=1; i<=n; i++) if(i!=x) sum+=W[par[i]];
    cout << sum << '\n';
    for(int i=1; i<=n; i++) if(i!=x) cout << par[i] << ' ';
    return 0;
}