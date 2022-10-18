#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;


pair<int,int> v[maxn];
int a[maxn],c[maxn];

int n;
long long dis[maxn];
vector<pair<int,int> > adj[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i].first>>v[i].second;
    sort(v+1,v+1+n);
    for(int i=1;i<=n;i++)a[i]=v[i].first,c[i]=v[i].second;
    for(int i=1;i<n;i++){
        int s=upper_bound(a+1,a+1+n,a[i]+c[i])-a;
        if(s<=n){
            adj[i].push_back({s,a[s]-a[i]-c[i]});
        }
        if(s-1>i){
            adj[i].push_back({s-1,0});
        }
        if(i!=1)adj[i].push_back({i-1,0});
    }
    adj[n].push_back({n-1,0});
    priority_queue<pair<long long,int> ,vector<pair<long long,int> > ,greater<pair<long long,int> > > pq;
    pq.push({0,1});
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    while(!pq.empty()){
        int u=pq.top().second;long long d=pq.top().first;pq.pop();
        if(dis[u]!=d)continue;
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].first;long long cw=d+adj[u][j].second;
            if(dis[v]>cw){
                dis[v]=cw;
                pq.push({cw,v});
            }
        }
    }
    //for(int i=1;i<=n;i++)cerr<<dis[i]<<endl;
    cout<<accumulate(c+1,c+1+n,dis[n]);
    return 0;
}