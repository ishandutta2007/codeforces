#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> g[200005];
int a[200005];
int ds[200005],dt[200005];

void bfs(int s,int *d){
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=0;i<g[x].size();i++){
            int& y=g[x][i];
            if(d[y]==-1){
                d[y]=d[x]+1;
                q.push(y);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(ds,-1,sizeof(ds));
    bfs(1,ds);
    memset(dt,-1,sizeof(dt));
    bfs(n,dt);
    vector<pair<int,int> > v;
    for(int i=0;i<k;i++){
        v.push_back(make_pair(ds[a[i]]-dt[a[i]],a[i]));
    }
    sort(v.begin(),v.end());
    int ans=0,mx=-1e9;
    for(pair<int,int> p:v){
        ans=max(ans,mx+dt[p.second]);
        mx=max(mx,ds[p.second]);
    }
    cout<<min(ans+1,ds[n])<<endl;

    return 0;
}