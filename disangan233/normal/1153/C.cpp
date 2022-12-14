#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
#define ak *
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
inline ll qpow(ll x,ll y,ll p,ll z=1)
{
 	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(x*z)%p:z;
	return z;
}
char s[1000005];
int n,m,k,a[1005],vis[1005],c[1005][1005],ans[1005][1005];
int main()
{
	n=read();scanf("%s",s+1);
	for(re i=1;i<=n;i++)
	if(s[i]=='(') k++;
	if(k>n/2) return puts(":("),0;
	for(re i=1;i<=n;i++)
	if(s[i]=='?')
	{
		s[i]=(k+1<=n/2)?'(':')';
		if(s[i]=='(') k++;
	}
	re na=0,nb=0;
	for(re i=1;i<=n;i++)
	{
		if(s[i]=='(') na++;
		else nb++;
		if(nb>na||nb==na&&i!=n) return puts(":("),0;
	}
	for(re i=1;i<=n;i++) putchar(s[i]);
}