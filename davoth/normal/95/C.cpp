#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e3+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
/*ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=y/2;
    b+=y%2;
    return (pow(x,a,mod)*pow(x,b,mod))%mod;
}
ll gcd(ll a,ll b){
    if(a==b) return a;
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b,a%b);
    else return gcd(a,b%a);
}*/
int n,m,x,y,T[N],C[N];
vector<pair<int,int> > adj[N],A[N];
int main() {
    fast_io;
    cin >> n >> m >> x >> y;
    for(int i=0; i<m; i++){
        int q,w,e;
        cin >> q >> w >> e;
        adj[q].emplace_back(w,e);
        adj[w].emplace_back(q,e);
    }
    for(int i=1; i<=n; i++) cin >> T[i] >> C[i];
    ll dist[n+1][n+1];
    memset(dist,63,sizeof dist);
    for(int i=1; i<=n; i++){
        dist[i][i]=0;
        priority_queue<pair<ll,int> > q;
        q.emplace(0,i);
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(p.F>dist[i][p.S]) continue;
            for(auto u : adj[p.S]){
                if(dist[i][u.F]<=T[i] || dist[i][p.S]+u.S>min((ll)T[i],dist[i][u.F]-1)) continue;
                dist[i][u.F]=dist[i][p.S]+u.S;
                q.emplace(dist[i][u.F],u.F);
                A[i].emplace_back(u.F,C[i]);
            }
        }
    }
    priority_queue<pair<ll,int> > q;
    q.emplace(0,x);
    dist[0][x]=0;
    while(!q.empty()){
        auto v=q.top();
        q.pop();
        if(v.F>dist[0][v.S]) continue;
        for(auto u : A[v.S]){
            if(dist[0][v.S]+u.S<dist[0][u.F]) q.emplace(dist[0][v.S]+u.S,u.F),dist[0][u.F]=dist[0][v.S]+u.S;
        }
    }
    if(dist[0][y]>1e14) cout << -1;
    else cout << dist[0][y];
    return 0;
}