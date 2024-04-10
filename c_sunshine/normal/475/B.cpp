#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,m;
int v[30][30];
char lr[30],ud[30];

int dfs(int x,int y)
{
  if(x<=0||x>n||y<=0||y>m)return 0;
  if(v[x][y])return 0;
  v[x][y]=1;
  int ret=1;
  if(lr[x]=='<')ret+=dfs(x,y-1);
  else ret+=dfs(x,y+1);
  if(ud[y]=='^')ret+=dfs(x-1,y);
  else ret+=dfs(x+1,y);
  return ret;
}

int main()
{
  scanf("%d%d\n",&n,&m);
  scanf("%s\n",lr+1);
  scanf("%s\n",ud+1);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
      memset(v,0,sizeof(v));
      if(dfs(i,j)<n*m)
      {printf("NO\n");exit(0);}
    }
  printf("YES\n");
  return 0;
}