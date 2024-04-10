#include<cstdio>
#include<iostream>
using namespace std;
int const maxn=1005;
int n,m;
int v[maxn];
int ans;
int main()
{
  scanf("%d%d",&n,&m);
  int i,t1,t2;
  for(i=1;i<=n;i++)
    scanf("%d",v+i);
  for(i=1;i<=m;i++)
  {
    scanf("%d%d",&t1,&t2);
    ans+=min(v[t1],v[t2]);
  }
  cout<<ans;
  return 0;
}