#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<iostream>
#define X first
#define Y second
#define N 100005
#define mp make_pair
using namespace std;
int f[22][N],n,a[N],d[N];
map<int,long long> ans;

int gcd(int a,int b)
{
  if(b==0)return a;
  return gcd(b,a%b);
}

int query(int l,int r)
{
  int h=d[r-l+1];
  return gcd(f[h][l],f[h][r-(1<<h)+1]);
}
int search(int l,int r,int p,int x)
{
  while(l<r)
  {
    int mid=(l+r)>>1;
    query(p,mid)==x?l=mid+1:r=mid;
  }
  return l;
} 
int main()
{
  int x,m;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",a+i);
  for(int i=2;i<=n;i++)
    d[i]=d[i-1]+(i==(i&-i));
  for(int i=1;i<=n;i++)
    f[0][i]=a[i];
  for(int i=1;i<=d[n];i++)
    for(int j=1;j<=n-(1<<i)+1;j++)
      f[i][j]=gcd(f[i-1][j],f[i-1][j+(1<<(i-1))]);
  for(int i=1;i<=n;i++)
  {
    int x=a[i],now=i;
    while(now<=n)
    {
      int a=search(now,n+1,i,x);
      ans[x]+=a-now;
      now=a,x=query(i,now);
    }
  }
  scanf("%d",&m);
  while(m--)
  {
    scanf("%d",&x);
    cout<<ans[x]<<endl;
  }
  return 0;
}