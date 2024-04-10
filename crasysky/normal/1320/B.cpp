#include <bits/stdc++.h>
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1e6+6;
vector<int> G[2][N];
int d[2][N],a[N];
void bfs(int t,int s){
    queue<int> q; q.push(s);
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (int i=0;i<G[t][u].size();++i){
            int v=G[t][u][i];
            if (v!=s&&!d[t][v]){
                d[t][v]=d[t][u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    for (int i=1;i<=m;++i){
        int u,v; scanf("%d%d",&u,&v);
        G[0][u].pb(v),G[1][v].pb(u);
    }
    int k; cin>>k;
    for (int i=1;i<=k;++i) scanf("%d",&a[i]);
    bfs(0,a[1]),bfs(1,a[k]);
    int mn=0,mx=0;
    for (int i=1;i<k;++i){
        int t=n;
        for (int j=0;j<G[0][a[i]].size();++j){
            int v=G[0][a[i]][j];
            if (v!=a[i+1]) t=min(t,d[0][a[i]]+1+d[1][v]);
        }
        if (t<d[0][a[i]]+1+d[1][a[i+1]]) ++mn;
        if (t<=d[0][a[i]]+1+d[1][a[i+1]]) ++mx;
    }
    cout<<mn<<" "<<mx<<endl;
}