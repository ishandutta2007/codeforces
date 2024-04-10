#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e3+1;
int xc[4]={1,-1,0,0};
int yc[4]={0,0,1,-1};
char C[4]={'U','D','L','R'};
char CP[4]={'D','U','R','L'};
pii grid[MAXN][MAXN];
bool gone[MAXN][MAXN];
char ans[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    map<pii,int> ends;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j].first>>grid[i][j].second;
            if(grid[i][j].first!=-1){
                grid[i][j].first-=1,grid[i][j].second-=1;
                ends[grid[i][j]]++;
            }
        }
    }
    for(auto x:ends){
        if(grid[x.first.first][x.first.second]!=x.first){
            printf("INVALID\n");
            return 0;
        }
        queue<pii> q;
        ans[x.first.first][x.first.second]='X';
        gone[x.first.first][x.first.second]=true;
        q.push(x.first);
        int am=0;
        while(sz(q)){
            auto cur=q.front();
            q.pop();
            am++;
            for(int i=0;i<4;i++){
                pii nc={cur.first+xc[i],cur.second+yc[i]};
                if(nc.first>=0&&nc.first<n&&nc.second>=0&&nc.second<n){
                    if(!gone[nc.first][nc.second]&&grid[nc.first][nc.second]==x.first){
                        gone[nc.first][nc.second]=true;
                        ans[nc.first][nc.second]=C[i];
                        q.push(nc);
                    }
                }
            }
        }
        if(am!=x.second){
            printf("INVALID\n");
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!gone[i][j]&&grid[i][j].first==-1){
                pii oth={-1,-1};
                for(int k=0;k<4;k++){
                    pii nc={i+xc[k],j+yc[k]};
                    if(nc.first>=0&&nc.first<n&&nc.second>=0&&nc.second<n){
                        if(!gone[nc.first][nc.second]&&grid[nc.first][nc.second].first==-1) {
                            oth=nc;
                            ans[oth.first][oth.second]=C[k];
                            ans[i][j]=CP[k];
                            break;
                        }
                    }
                }
                if(oth.first==-1){
                    printf("INVALID\n");
                    return 0;
                }
                queue<pii> q;
                gone[i][j]=true;
                gone[oth.first][oth.second]=true;
                q.push({i,j});
                q.push(oth);
                while(sz(q)){
                    auto cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        pii nc={cur.first+xc[k],cur.second+yc[k]};
                        if(nc.first>=0&&nc.first<n&&nc.second>=0&&nc.second<n){
                            if(!gone[nc.first][nc.second]&&grid[nc.first][nc.second].first==-1){
                                gone[nc.first][nc.second]=true;
                                ans[nc.first][nc.second]=C[k];
                                q.push(nc);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("VALID\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%c",ans[i][j]);
        printf("\n");
    }
    return 0;
}