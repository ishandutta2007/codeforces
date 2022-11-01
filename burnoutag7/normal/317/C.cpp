#include<bits/stdc++.h>
using namespace std;

int n,v,m,a[305],b[305];
int dist[305][305],fa[305][305],lft;
vector<pair<pair<int,int>,int>> seq;

void dfs(const int &s,const int &t,const int &d){
    const int &f=fa[s][t];
    int dd=d-a[f];
    seq.emplace_back(make_pair(f,t),min(d,a[f]));
    a[t]+=min(d,a[f]);
    a[f]-=min(d,a[f]);
    if(s!=f)dfs(s,f,d);
    if(dd>0){
        seq.emplace_back(make_pair(f,t),dd);
        a[f]-=dd;
        a[t]+=dd;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>v>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        lft+=a[i]!=b[i];
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        static int u,v;
        cin>>u>>v;
        dist[u][v]=dist[v][u]=1;
        fa[u][v]=u;
        fa[v][u]=v;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    fa[i][j]=fa[k][j];
                }
            }
        }
    }
    while(lft){
        bool ntrans=true;
        for(int s=1;s<=n&&ntrans;s++)if(a[s]>b[s]){
            for(int t=1;t<=n&&ntrans;t++)if(a[t]<b[t]&&dist[s][t]!=0x3f3f3f3f){
                dfs(s,t,min(a[s]-b[s],b[t]-a[t]));
                lft-=a[s]==b[s];
                lft-=a[t]==b[t];
                ntrans=false;
            }
        }
        if(ntrans){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<seq.size()<<'\n';
    for(const pair<pair<int,int>,int> &p:seq){
        cout<<p.first.first<<' '<<p.first.second<<' '<<p.second<<'\n';
    }

    return 0;
}