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
int n,m,h,a[1005],b[1005],c[1005][1005],ans[1005][1005];
int main()
{
	n=read(),m=read();h=read();
	for(re i=1;i<=m;i++) a[i]=read();
	for(re i=1;i<=n;i++) b[i]=read();
	for(re i=1;i<=n;i++) for(re j=1;j<=m;j++)
	ans[i][j]=read()*min(a[j],b[i]);
	for(re i=1;i<=n;i++)
	{
		for(re j=1;j<=m;j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}