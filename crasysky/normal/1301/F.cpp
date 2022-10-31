#include <bits/stdc++.h>
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1002;
vector< pr > G[45];
int t,c[N][N],d[42][N][N];
bool vis[N][N];
deque< pr > q;
int abs(int x){ return x>=0?x:-x; }
void trans(int x1,int y1,int x2,int y2,int c){
    if (!vis[x2][y2]&&d[t][x1][y1]+c<d[t][x2][y2]){
        d[t][x2][y2]=d[t][x1][y1]+c;
       if (c) q.push_back(mp(x2,y2));
       else q.push_front(mp(x2,y2));
    }
}
int main(){
    int n,m,k; cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j){
            scanf("%d",&c[i][j]);
            G[c[i][j]].push_back(mp(i,j));
        }
    for (t=1;t<=40;++t){
        memset(d[t],0x3f,sizeof(d[t]));
        memset(vis,0,sizeof(vis));
        d[t][n+1][t]=0; q.push_back(mp(n+1,t));
        while (!q.empty()){
            pr p=q.front(); q.pop_front();
            if (vis[p.fi][p.se]) continue;
            vis[p.fi][p.se]=true;
            if (p.fi<=n){
                if (p.fi>1) trans(p.fi,p.se,p.fi-1,p.se,1);
                if (p.se>1) trans(p.fi,p.se,p.fi,p.se-1,1);
                if (p.fi<n) trans(p.fi,p.se,p.fi+1,p.se,1);
                if (p.se<m) trans(p.fi,p.se,p.fi,p.se+1,1);
                trans(p.fi,p.se,n+1,c[p.fi][p.se],0);
            }
            else
                for (int i=0;i<G[p.se].size();++i)
                    trans(p.fi,p.se,G[p.se][i].fi,G[p.se][i].se,t!=p.se);
        }
    }
    int q; cin>>q;
    while (q--){
        int r1,c1,r2,c2; scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        int ans=abs(r1-r2)+abs(c1-c2);
        for (int c=1;c<=40;++c)
            ans=min(ans,d[c][r1][c1]+1+d[c][r2][c2]);
        printf("%d\n",ans);
    }
}