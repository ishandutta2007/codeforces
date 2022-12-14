#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define rd regitser double
#define ak *
#define lim 100000
const int p=998244353; 
char qwq;
int n,fac[200005]={1},ans,du[200005];
inline int read()
{
	re zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
int main()
{
	n=ans=read();
	for(re i=1;i<=2*(n-1);i++) du[read()]++;
	for(re i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%p;
	for(re i=1;i<=n;i++) ans=ans*1ll*fac[du[i]]%p;
	cout<<ans;
	return 0;
}