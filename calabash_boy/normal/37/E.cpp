#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
char mp[maxn][maxn];
int dis[maxn][maxn];
const int inf = 0x3f3f3f3f;
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs(int sx, int sy){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dis[i][j] = inf;
        }
    }
    dis[sx][sy] = 0;
    queue<pair<int,int> > Q;
    Q.push(make_pair(sx,sy));
    while (!Q.empty()){
        int x,y;
        tie(x,y) = Q.front();
        Q.pop();
        for (int d=0;d<4;d++){
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (xx >= 1 && x <= n && yy >= 1 && yy <= m){
                int tmp_dis = dis[x][y] + (mp[x][y] != mp[xx][yy]);
                if (tmp_dis < dis[xx][yy]){
                    dis[xx][yy] = tmp_dis;
                    Q.push(make_pair(xx,yy));
                }
                
            }
        }
    }
    int ans = -1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mp[i][j] == 'B')
            ans = max(ans, dis[i][j]);
        }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>&mp[i][1];
    }
    int ans = inf;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            //cerr<<i<<","<<j<<":"<<bfs(i,j)<<endl;
            ans = min(ans,bfs(i,j));
        }
    }
    cout<<ans+1<<endl;
    return 0;
}