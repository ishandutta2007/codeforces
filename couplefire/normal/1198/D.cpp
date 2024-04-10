#include <bits/stdc++.h>
using namespace std;
int dp[51][51][51][51];
int visit[51][51][51][51];
int n;
char a[52][52];
 
int f(int x,int y,int xx,int yy){
    if(visit[x][y][xx][yy])return dp[x][y][xx][yy];
    visit[x][y][xx][yy]=1;
    int ret=max(xx-x+1,yy-y+1);
    int i;
    for(i=x ; i<xx ; i++){
        ret=min(ret,f(x,y,i,yy)+f(i+1,y,xx,yy));
    }
    for(i=y ; i<yy ; i++)
        ret=min(ret,f(x,y,xx,i)+f(x,i+1,xx,yy));
    return dp[x][y][xx][yy]=ret;
}
int main(){
    scanf("%d ",&n);
    int i,j;
    for(i=1 ; i<=n ; i++){
        scanf("%s",a[i]+1);
        for(j=1 ; j<=n ; j++){
            if(a[i][j]=='#')dp[i][j][i][j]=1;
            else dp[i][j][i][j]=0;
            visit[i][j][i][j]=1;
        }
    }
    cout<<f(1,1,n,n);
    return 0;
}