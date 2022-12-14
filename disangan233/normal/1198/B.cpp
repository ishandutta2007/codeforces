#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
#define db double
#define in inline
inline char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getchar()
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=4e5+5;
int n,m,a[N],b[N],ans,c[N];
int main()
{
	n=read();
	for(re i=1;i<=n;i++) a[i]=read();
	m=read();
	for(re i=1;i<=m;i++)
	{
		re op=read(),x=read();
		if(op==2) c[i]=x;
		else a[x]=read(),b[x]=i;
	}
	for(re i=m;i;i--) c[i]=max(c[i],c[i+1]);
	for(re i=1;i<=n;i++) a[i]=max(a[i],c[b[i]+1]);
	for(re i=1;i<=n;i++) printf("%d ",a[i]);
}