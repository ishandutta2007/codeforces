#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=305;
int n,p[maxn];
int a[maxn][maxn];
int f[maxn];
int getfather(int x)
{
  if(f[x])return f[x]=getfather(f[x]);
  return x;
}
int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",p+i);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      scanf("%1d",&a[i][j]);
      if(a[i][j])
      {
        int x=getfather(i),y=getfather(j);
        if(x!=y)f[x]=y;
      }
    }
  for(int i=1;i<n;i++)
  {
    for(int j=i+1;j<=n;j++)
      if(getfather(i)==getfather(j)&&p[i]>p[j])swap(p[i],p[j]);
  }
  for(int i=1;i<=n;i++)
    printf("%d%c",p[i]," \n"[i==n]);
  return 0;
}