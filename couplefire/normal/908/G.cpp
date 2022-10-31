#include <bits/stdc++.h>
#define il inline
#define RG register
#define ll long long
#define rhl (1000000007)
 
using namespace std;
 
int f[705][705][2],p[705],a[705],n,ans;
 
int main(){
#ifndef ONLINE_JUDGE
  freopen("order.in","r",stdin);
  freopen("order.out","w",stdout);
#endif
  RG char ch=getchar();
  while (ch<'0' || ch>'9') ch=getchar();
  while (ch>='0' && ch<='9') a[++n]=ch-'0',ch=getchar();
  for (RG int i=1;i<=n;++i) p[i]=(10LL*p[i-1]+1)%rhl;
  for (RG int d=0;d<9;++d){
    memset(f,0,sizeof(f)),f[0][0][1]=1;
    for (RG int i=1;i<=n;++i)
      for (RG int j=0;j<=i;++j)
	for (RG int k=0;k<2;++k)
	  for (RG int p=0;p<10;++p)
	    if (!k || p<=a[i]) (f[i][j+(p>d)][k&&p==a[i]]+=f[i-1][j][k])%=rhl;
      for (RG int j=1;j<=n;++j) ans=(1LL*p[j]*(f[n][j][0]+f[n][j][1])+ans)%rhl;
  }
  cout<<ans; return 0;
}