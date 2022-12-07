
#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 


ll n,m;
const ll INF = INT64_MAX;
vector<vector<pair<ll, ll>>> adj;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    adj.resize(2*n+1);
    for(ll i = 0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v+n].push_back({u+n,w});
    }
    for(ll i = 1;i<=n;i++){
        adj[i].push_back({i+n,0});
    }
    vector<ll> d(2*n+1);
    vector<ll> p(2*n+1);
    dijkstra(1, d,p);
    for(ll i = 2;i<=n;i++){
        cout<<(d[i+n]==INF?-1:d[i+n])<<" ";
    }
    cout<<endl;

    return 0;
}