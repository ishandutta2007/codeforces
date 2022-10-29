#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,m;
int w[maxn],a[maxn];
int g[maxn],vis[maxn];
int ans;

int get(int k)
{
  int ret=0,i;
  for(i=1;a[i]!=k;i++)
    ret+=w[a[i]];
  for(;i>1;i--)a[i]=a[i-1];
  a[1]=k;
  return ret;
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
    scanf("%d",w+i);
  int tn=0;
  for(int i=1;i<=m;i++)
  {
    scanf("%d",g+i);
    if(!vis[g[i]])a[++tn]=g[i],vis[g[i]]=1;
  }
  for(int i=1;i<=n;i++)
    if(!vis[i])a[++tn]=i;
  for(int i=1;i<=m;i++)
    ans+=get(g[i]);
  cout<<ans<<endl;
  return 0;
}