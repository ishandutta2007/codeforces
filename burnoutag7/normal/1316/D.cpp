#include<bits/stdc++.h>
using namespace std;

int n,tot;
char g[1005][1005];
pair<int,int> dst[1005][1005];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char rev[]={'D','L','U','R'};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dst[i][j].first>>dst[i][j].second;
            if(dst[i][j]==make_pair(i,j)){
                g[i][j]='X';
                q.push(make_pair(i,j));
            }
            if(dst[i][j]==make_pair(-1,-1)){
                if(dst[i-1][j]==make_pair(-1,-1)&&!g[i-1][j]){
                    g[i][j]='U';
                    g[i-1][j]='D';
                    q.push(make_pair(i,j));
                    q.push(make_pair(i-1,j));
                }else if(dst[i][j-1]==make_pair(-1,-1)&&!g[i][j-1]){
                    g[i][j]='L';
                    g[i][j-1]='R';
                    q.push(make_pair(i,j));
                    q.push(make_pair(i,j-1));
                }
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        tot++;
        for(int d=0;d<4;d++){
            int nx=dx[d]+x,ny=dy[d]+y;
            if(nx>0&&ny>0&&nx<=n&&ny<=n&&!g[nx][ny]&&dst[nx][ny]==dst[x][y]){
                q.push(make_pair(nx,ny));
                g[nx][ny]=rev[d];
            }
        }
    }
    if(tot!=n*n){
        cout<<"INVALID"<<endl;
    }else{
        cout<<"VALID"<<endl;
        for(int i=1;i<=n;i++){
            cout<<g[i]+1<<endl;
        }
    }

    return 0;
}