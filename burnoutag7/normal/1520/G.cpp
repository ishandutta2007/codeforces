#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,w,g[2005][2005],dx[]={-1,0,1,0},dy[]={0,1,0,-1};
ll ds[2005][2005],dt[2005][2005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.emplace(1,1);
    memset(ds,0x3f,sizeof(ds));
    ds[1][1]=0;
    while(!q.empty()){
        int x=q.front().first,y=q.front().second,nx,ny;
        ll nw=ds[x][y]+w;
        q.pop();
        for(int i=0;i<4;i++){
            nx=x+dx[i],ny=y+dy[i];
            if(nx>0&&ny>0&&nx<=n&&ny<=m&&g[nx][ny]!=-1&&ds[nx][ny]>nw){
                ds[nx][ny]=nw;
                q.emplace(nx,ny);
            }
        }
    }
    q.emplace(n,m);
    memset(dt,0x3f,sizeof(dt));
    dt[n][m]=0;
    while(!q.empty()){
        int x=q.front().first,y=q.front().second,nx,ny;
        ll nw=dt[x][y]+w;
        q.pop();
        for(int i=0;i<4;i++){
            nx=x+dx[i],ny=y+dy[i];
            if(nx>0&&ny>0&&nx<=n&&ny<=m&&g[nx][ny]!=-1&&dt[nx][ny]>nw){
                dt[nx][ny]=nw;
                q.emplace(nx,ny);
            }
        }
    }
    ll ps=1e18,pt=1e18;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]>0){
                ps=min(ps,ds[i][j]+g[i][j]);
                pt=min(pt,dt[i][j]+g[i][j]);
            }
        }
    }
    cout<<(min(ps+pt,ds[n][m])<1e18?min(ps+pt,ds[n][m]):-1);

    return 0;
}