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
int n, k, d;
vector<int> p;
vector<pair<int,int> > adj[N];
int main() {
    fast_io;
    cin >> n >> k >> d;
    for(int i=0; i<k; i++){
        int x;
        cin >> x;
        p.push_back(x);
    }
    for(int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }
    queue<int> q;
    int dist[N];
    set<int> ans;
    for(int i=1; i<n; i++) ans.insert(i);
    memset(dist,-1,sizeof dist);
    for(int i : p) q.push(i),dist[i]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v : adj[u]){
            int lp=v.F;
            if(dist[lp]!=-1) continue;
            dist[lp]=dist[u]+1;
            q.push(lp);
            ans.erase(v.S);
        }
    }
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << ' ';
    return 0;
}