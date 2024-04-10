#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1;
const int MAXM=1e4+1;
vector<pii> matrix[MAXN];
pair<ll,pii> edge[MAXM];
bool spec[MAXM];
ll dist[MAXN];
pii from[MAXN];
int n,m,s,t;
vector<int> onpathedges;
pair<ll,int> dijkstra(){
    onpathedges=vector<int>();
    for(int i=0;i<n;i++)dist[i]=LLONG_MAX,from[i]={-1,-1};
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
    dist[s]=0;
    q.push({0,s});
    while(sz(q)){
        auto cur=q.top();
        q.pop();
        if(cur.first<=dist[cur.second]){
            for(auto x:matrix[cur.second]){
                if(cur.first+edge[x.second].first<dist[x.first]){
                    dist[x.first]=cur.first+edge[x.second].first;
                    from[x.first]={cur.second,x.second};
                    q.push({dist[x.first],x.first});
                }
            }
        }
    }
    int cur=t;
    while(from[cur].first!=-1){
        if(spec[from[cur].second]){
            onpathedges.push_back(from[cur].second);
        }
        cur=from[cur].first;
    }
    return {dist[t],(sz(onpathedges)?onpathedges[0]:-1)};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll l;
    cin>>n>>m>>l>>s>>t;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b>>edge[i].first;
        if(edge[i].first==0)spec[i]=true,edge[i].first=1;
        edge[i].second={a,b};
        matrix[a].push_back({b,i});
        matrix[b].push_back({a,i});
    }
    pair<ll,int> cur=dijkstra();
    if(cur.first>l){
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<m;i++){
        if(spec[i])edge[i].first=1e18;
    }
    for(auto x:onpathedges)edge[x].first=1;
    while(cur.first<l){
        if(cur.second==-1){
            printf("NO\n");
            return 0;
        }
        edge[cur.second].first+=l-cur.first;
        cur=dijkstra();
    }
    printf("YES\n");
    for(int i=0;i<m;i++)printf("%d %d %lli\n",edge[i].second.first,edge[i].second.second,edge[i].first);
    return 0;
}