#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char mp[maxn][maxn];
int n,m,d;
int dis[maxn][maxn];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<pair<int,int> > legal_cells;
vector<pair<int,int> > bfs(int sx,int sy){
    vector<pair<int,int> > ret(0);
    dis[sx][sy] = 0;
    ret.push_back(make_pair(sx,sy));
    for (int i=0;i<ret.size();i++){
        int x,y;
        tie(x,y) = ret[i];
        if (dis[x][y] == d)break;
        for(int k=0;k<4;k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && dis[xx][yy] == -1 && mp[xx][yy] != 'X'){
                dis[xx][yy] = dis[x][y] + 1;
                ret.push_back(make_pair(xx,yy));
            }
        }
    }
    for (auto p : ret){
        int x,y;
        tie(x,y) = p;
        dis[x][y] = -1;
    }
    return ret;
}
int cntR = 0;
bool used[maxn][maxn];
void gao(int X,int Y){
    vector<pair<int,int> > to_check = bfs(X,Y);
    for (auto p1 : to_check){
        int x1,y1;
        tie(x1,y1) = p1;
        for (auto p2 : legal_cells){
            int x2,y2;
            tie(x2,y2) = p2;
            if (x1 == x2 && y1 == y2)continue;
            vector<pair<int,int> > ok(0),ok1 = bfs(x1,y1),ok2 = bfs(x2,y2);
            ok.insert(ok.end(),ok1.begin(),ok1.end());
            ok.insert(ok.end(),ok2.begin(),ok2.end());
            //sort(ok.begin(),ok.end());
            //ok.erase(unique(ok.begin(), ok.end()),ok.end());
            int cnt = 0;
            for (auto p : ok){
                int x,y;
                tie(x,y) = p;
            
                cnt += mp[x][y] == 'R' && !used[x][y];
                used[x][y] = 1;
            }
            for (auto p : ok){
                int x,y;
                tie(x,y) = p;
                used[x][y] = 0;
            }
            if (cnt == cntR){
                printf("%d %d %d %d\n",x1,y1,x2,y2);
                exit(0);
            }
        }
    }
    puts("-1");
    exit(0);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&d);
    for (int i=1;i<=n;i++){
        scanf("%s",&mp[i][1]);
        for (int j=1;j<=m;j++){
            cntR += mp[i][j] == 'R';
            dis[i][j] = -1;
        }
    }
    if (cntR >= 300){
        puts("-1");
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mp[i][j] == 'R'){
                vector<pair<int,int> > cells = bfs(i,j);
                legal_cells.insert(legal_cells.end(),cells.begin(),cells.end());
            }
        }
    }
    sort(legal_cells.begin(),legal_cells.end());
    legal_cells.erase(unique(legal_cells.begin(), legal_cells.end()),legal_cells.end());
    if(legal_cells.size() == 1){
        int x,y;
        tie(x,y) = legal_cells.front();
        for (int i=1;i<=n;i++){
            if (legal_cells.size() >= 2)break;
            for (int j=1;j<=m;j++){
                if (legal_cells.size() >= 2)break;
                if (i == x && j == y)continue;
                if (mp[i][j] == '.'){
                    legal_cells.push_back(make_pair(i,j));
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mp[i][j] == 'R')gao(i,j);
        }
    }
    assert(0);
    return 0;
}
/*
 
 6 8 1
 XXXXXXXX
 X.R....X
 XRRR.R.X
 X.R.RRRX
 X....R.X
 XXXXXXXX
 
 6 8 1
 XXXXXXXX
 XXXXXXXX
 XXRXXXXX
 XXXXXRXX
 XXXXXXXX
 XXXXXXXX
 */