#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
ll arr[MN];
vector<pii> adj[MN];
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    if(sz(adj[bp])>sz(adj[ap]))swap(adj[bp],adj[ap]);
    for(auto x:adj[bp])adj[ap].push_back(x);
    dsu[bp].first=ap;
    dsu[ap].second+=dsu[bp].second;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    ll cost,sum=0;
    cin>>n>>m>>cost;
    set<pair<ll,int>> q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        q.insert({arr[i],i});
        sum+=arr[i];
        dsu[i]={i,1};
    }
    if(sum<(n-1)*cost){
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    printf("YES\n");
    vector<int> edges;
    while(sz(edges)!=n-1){
        auto cur=*q.rbegin();
        q.erase(cur);
        while(sz(adj[cur.second])){
            pii x=adj[cur.second].back();
            adj[cur.second].pop_back();
            if(find(cur.second)!=find(x.first)&&arr[find(cur.second)]+arr[find(x.first)]>=cost){
                q.erase({arr[find(x.first)],find(x.first)});
                ll add=arr[find(cur.second)]+arr[find(x.first)]-cost;
                uni(cur.second,x.first);
                arr[find(cur.second)]=add;
                edges.push_back(x.second);
                q.insert({arr[find(cur.second)],find(cur.second)});
                break;
            }
        }
    }
    for(auto x:edges)printf("%d\n",x);
    return 0;
}