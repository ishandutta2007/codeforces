#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=100005;
int a[maxn],n;
void readi(int &x);

int Find(int x)
{
  int low=0,high=n,mid;
  while(low+1<high)
  {
    mid=low+high>>1;
    if(a[mid]>=x)high=mid;
    else low=mid;
  }
  return high;
}

int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    readi(a[i]);
    a[i]+=a[i-1];
  }
  int t,x;
  readi(t);
  while(t--)
  {
    readi(x);
    printf("%d\n",Find(x));
  }
  return 0;
}

void readi(int &x)
{
  char c;
  for(c=getchar();c<'0'||c>'9';c=getchar());
  x=c^48;
  for(c=getchar();c<='9'&&c>='0';c=getchar())x=x*10+(c^48);
}