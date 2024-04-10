#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<pair<int,ll>> adj[MN];
set<int> cnt[MN];
vector<pair<ll,pii>> edges;
vector<pair<ll,pii>> useful;
vector<pii> added;
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
set<int> notvisited;
void dfs(int loc){
    notvisited.erase(loc);
    int prev=1;
    while(1){
        auto it=notvisited.lower_bound(prev);
        if(it==notvisited.end())return;
        int cur=*it;
        if(!cnt[loc].count(cur)){
            uni(loc,cur);
            dfs(cur);
        }
        prev=cur+1;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    ll c,xorval=0;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        xorval^=c;
        edges.push_back({c,{a,b}});
        cnt[a].insert(b),cnt[b].insert(a);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    bool extra=false;
    if(ll(n)*ll(n-1)/ll(2)-ll(m)>ll(n-1))extra=true;
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!cnt[i].count(j)){
                    if(!uni(i,j))extra=true;
                }
            }
        }
    }
    if(extra){
        for(int i=1;i<=n;i++)notvisited.insert(i),dsu[i]={i,1};
        for(int i=1;i<=n;i++)if(notvisited.count(i))dfs(i);
        sort(edges.begin(),edges.end());
        ll ans=0;
        for(auto x:edges){
            if(uni(x.second.first,x.second.second))ans+=x.first;
        }
        printf("%lli\n",ans);
    }
    else{
        sort(edges.begin(),edges.end());
        for(int i=1;i<=n;i++)dsu[i]={i,1};
        for(auto x:edges){
            if(uni(x.second.first,x.second.second))useful.push_back(x);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!cnt[i].count(j)){
                    added.push_back({i,j});
                }
            }
        }
        ll best=LLONG_MAX;
        for(int i=0;i<sz(added);i++){
            for(int j=1;j<=n;j++)dsu[j]={j,1};
            vector<pair<ll,pii>> finedges;
            for(int j=0;j<sz(added);j++){
                finedges.push_back({(j==i?xorval:0),added[j]});
            }
            for(auto x:useful)finedges.push_back(x);
            sort(finedges.begin(),finedges.end());
            ll ans=0;
            for(auto x:finedges){
                if(uni(x.second.first,x.second.second))ans+=x.first;
            }
            best=min(best,ans);
        }
        printf("%lli\n",best);
    }
    return 0;
}