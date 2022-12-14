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
ll n,m,a[N],b[N],c[N],ans;
int main()
{
	n=read(),m=read()*8ll;m/=n;
	if(m<=20) m=min(1ll<<m,n);
	else m=n;
	for(re i=1;i<=n;i++) a[i]=b[i]=read();
	sort(b+1,b+n+1);ll tot=unique(b+1,b+n+1)-b-1;
	for(re i=1;i<=n;i++) a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	for(re i=1;i<=n;i++) c[a[i]]++;
	for(re i=1;i<=tot;i++) c[i]+=c[i-1];
	m=min(m,tot);
	for(re i=m;i<=tot;i++) ans=max(ans,c[i]-c[i-m]);
	printf("%d\n",n-ans);
	return 0;
 
}