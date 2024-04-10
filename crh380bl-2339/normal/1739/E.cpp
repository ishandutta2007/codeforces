#include<bits/stdc++.h>
using namespace std;
char s[2][300005];
bool vis[2][300005];
int ans[2][300005];
int n;
int DFS(int x,int y){
    if(y>n)return 0;
    if(vis[x][y])return ans[x][y];
    vis[x][y]=1;
    if(s[x^1][y]==0 && s[x][y+1]==0)return ans[x][y] = DFS(x, y+1);
    if(s[x^1][y] && s[x][y+1] == 0)return ans[x][y] = max(1 + s[x^1][y+1] + DFS(x^1,y+1), DFS(x,y+1));
    if(s[x^1][y]==0 && s[x][y+1])return ans[x][y] = 1 + DFS(x, y+1);
    ans[x][y] = max(1 + DFS(x,y+1), 1 + s[x^1][y+1] + s[x^1][y+2] + DFS(x^1, y+2));
    return ans[x][y];
}
int main(){
    int i,j;
    scanf("%d",&n);
    scanf("%s%s",s[0]+1,s[1]+1);
    for(i=0;i<2;++i)for(j=1;j<=n;++j)s[i][j]-='0';
    printf("%d\n",DFS(0,1));
    //printf("%d %d\n",DFS(0,1), DFS(0,8));
    return 0;
}