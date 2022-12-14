#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define db double
#define rd regitser double
#define ak *
#define lim 100000 
char qwq;
ll ans,t,n,k,a[300005],s[300005];
inline ll read()
{
	ll zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
int main()
{
	n=read(),k=read();
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=n;i;i--) s[i]=s[i+1]+a[i];
	sort(s+2,s+n+1,greater<ll>());ans=s[1];
	for(re i=2;i<=k;i++) ans+=s[i];
	cout<<ans;
	return 0;
}