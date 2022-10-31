#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,m; string s[maxn];
bool dfs(int x,int y)
{
    if(x==n-1 && y==m-1) return true;
    if(x>=n || y>=m || s[x][y]=='#') return false;
    if(x || y) s[x][y]='#';
    return dfs(x+1,y) || dfs(x,y+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) cin>>s[i];
    if(!dfs(0,0)) return puts("0"),0;
    printf("%d\n",dfs(0,0)?2:1);
    return 0;
}