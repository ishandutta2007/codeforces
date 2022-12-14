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
int n,m,a[1005][1005],b[1005][1005],l[1005],cnt;
int main()
{
	n=read(),m=read();
	for(re i=1;i<=n;i++) for(re j=1;j<=m;j++) a[i][j]=read();
	for(re i=1;i<=n;i++) for(re j=1;j<=m;j++) b[i][j]=read();
	for(re i=1;i<=n;i++)
	{
		re x=0,y=0;
		for(re j=1;j<=m;j++) x^=a[i][j],y^=b[i][j];
		if(x!=y) return puts("No"),0;
	}
	for(re j=1;j<=m;j++)
	{
		re x=0,y=0;
		for(re i=1;i<=n;i++) x^=a[i][j],y^=b[i][j];
		if(x!=y) return puts("No"),0;
	}
	return puts("Yes"),0;
}