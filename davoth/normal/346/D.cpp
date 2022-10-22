#include <bits/stdc++.h>
using namespace std;

using ll=long long int;
#define F first
#define S second
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
const int N=1e6+2;
vector<ll> adj1[N],adj2[N];
ll cnt[N],dis[N];
set<pll> q;
vector<ll> y[N];
int main()
{
    ll n,m,s,t;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        ll u,v;
        cin >> u >> v;
        adj1[u].push_back(v);
        cnt[u]++;
        adj2[v].push_back(u);
    }
    cin >> s >> t;
    memset(dis,63,sizeof dis);
    dis[t]=0;
    ll k=0;
    q.insert({0,t});
    y[0].push_back(t);
    bool c=1;
    while(c){
        while(!q.empty()){
             ll d=q.begin()->F,v=q.begin()->S;
             if(v==s) c=0;
             q.erase({d,v});
             for(int u : adj2[v]){
                cnt[u]--;
                if(cnt[u]==0) q.insert({d,u}),y[d].push_back(u),dis[u]=d;
             }
        }
        k++;
        if(y[k-1].empty() && c) return cout<<-1,0;
        else if(y[k-1].empty()) break;
        for(int v : y[k-1]){
            for(int u : adj2[v]){
                if(dis[u]>1e9) q.insert({k,u}),y[k].push_back(u),dis[u]=k,cnt[u]=0;
            }
        }
    }
    cout << dis[s];
	return 0;
}