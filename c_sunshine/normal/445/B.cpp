#include<stdio.h>
#include<iostream>
using namespace std;
int f[55];
int getfather(int x)
{
  if(f[x]==0)return x;
  return f[x]=getfather(f[x]);
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int i,t1,t2;
  for(i=1;i<=m;i++)
  {
    scanf("%d%d",&t1,&t2);
    t1=getfather(t1);
    t2=getfather(t2);
    if(t1!=t2)f[t1]=t2;
  }
  int tot=n;
  for(i=1;i<=n;i++)
  {
    if(f[i]==0)tot--;
  }
  cout<<(1ll<<tot)<<endl;
  return 0;
}