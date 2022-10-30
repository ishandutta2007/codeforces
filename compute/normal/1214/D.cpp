#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
string maze[maxn];
map<int,int> vis[maxn];
int n,m;
bool dfs(int x,int y)
{
  if(x<0||x>=n||y<0||y>=m||vis[x][y]||maze[x][y]=='#') return false;
  if(x==n-1&&y==m-1) return true;
  vis[x][y]=1;
  return dfs(x+1,y)||dfs(x,y+1);
}
int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>maze[i];
  if(!dfs(0,0)) cout<<0<<endl;
  else{
    vis[0][0]=0;
    if(!dfs(0,0))
      cout<<1<<endl;
    else cout<<2<<endl;
  }
}