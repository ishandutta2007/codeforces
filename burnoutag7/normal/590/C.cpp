#include<bits/stdc++.h>
using namespace std;

int n,m;
char g[1005][1005];
int dis[3][1005][1005];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void bfs(int d[][1005],deque<pair<int,int>> &q){
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop_front();
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(d[nx][ny]==-1&&g[nx][ny]!='#'&&nx>0&&ny>0&&nx<=n&&ny<=m){
                d[nx][ny]=d[x][y]+(g[nx][ny]=='.');
                if(g[nx][ny]=='.')q.push_back(make_pair(nx,ny));
                else q.push_front(make_pair(nx,ny));
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    memset(dis,-1,sizeof(dis));
    {
        deque<pair<int,int> > q[3];
        for(int i=1;i<=n;i++){
            cin>>g[i]+1;
            for(int j=1;j<=m;j++){
                for(int k=0;k<3;k++){
                    if(g[i][j]==k+'1'){
                        q[k].push_back(make_pair(i,j));
                        dis[k][i][j]=0;
                    }
                }
            }
        }
        bfs(dis[0],q[0]);
        bfs(dis[1],q[1]);
        bfs(dis[2],q[2]);
    }
    int ans=1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dis[0][i][j]!=-1&&dis[1][i][j]!=-1&&dis[2][i][j]!=-1)ans=min(ans,dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-(g[i][j]=='.')*2);
        }
    }
    if(ans==1e9)ans=-1;
    cout<<ans<<endl;

    return 0;
}