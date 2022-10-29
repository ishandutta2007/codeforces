#include<cstdio>
#include<iostream>
using namespace std;
const int M=1000000007;
const int maxn=100005;
int sum[maxn],f[maxn];
int main()
{
  int t,k;
  cin>>t>>k;
  f[0]=sum[0]=1;
  for(int i=1;i<=100000;i++)
  {
    f[i]=f[i-1];
    if(i>=k)f[i]=(f[i]+f[i-k])%M;
    sum[i]=(sum[i-1]+f[i])%M;
  }
  int a,b,ans;
  while(t--)
  {
    scanf("%d%d",&a,&b);
    ans=(sum[b]-sum[a-1])%M;
    if(ans<0)ans+=M;
    printf("%d\n",ans);
  }
  return 0;
}