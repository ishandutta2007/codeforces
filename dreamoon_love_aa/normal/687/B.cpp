#include<cstdio>
#include<algorithm>
using namespace std;
int n,K,d[1111],dn,dp[1234567],i;
main(){
  scanf("%d%d",&n,&K);
  for(i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    dp[x]=1;
  }
  for(i=1;i<=1000000;i++)
    for(int j=i;j<=1000000;j+=i)dp[i]|=dp[j];
  for(i=1;i<=K;i++)
    if(K%i==0)d[dn++]=i;
  dp[1]=1;
  for(i=0;i<dn;i++){
    int x=d[i];
    for(int j=0;j<i;j++){
      int y=d[j];
      if(dp[y]&&dp[x/y]&&x%y==0&&__gcd(x/y,y)==1)dp[x]=1;
    }
  }
  puts(dp[K]?"Yes":"No");
}