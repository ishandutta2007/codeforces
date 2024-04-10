#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=505;
const int maxk=22;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,m,k;
int w[maxn][maxn][4];
int dp[maxk][maxn][maxn];


int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            cin>>w[i][j][2];
            w[i][j+1][3]=w[i][j][2];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            cin>>w[i][j][0];
            w[i+1][j][1]=w[i][j][0];
        }
    }
    if(k&1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cout<< -1<<' ';
            cout<<endl;
        }
        return 0;
    }
    k>>=1;
    memset(dp,0x3f,sizeof(dp));

    for(int x=1;x<=n;x++)for(int y=1;y<=m;y++)dp[0][x][y]=0;
    for(int i=1;i<=k;i++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                for(int d=0;d<4;d++){
                    dp[i][x][y]=min(dp[i][x][y],dp[i-1][x+dx[d]][y+dy[d]]+w[x][y][d]);
                }
            }
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            cout<<dp[k][x][y]*2<<' ';
        }
        cout<<endl;
    }
    return 0;
}