#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
#define db double
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
inline int read()
{
    re cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
const int N=3005;
int n,m,a,b,x,y,z,g,h[N][N];
ll ans;
struct deeque{
	int q[N],a[N],h,t,mx;
	inline void clear(re x) {h=1;t=0;mx=x;}
	inline void ins(re x,re y)
	{
		while(h<=t&&y-q[h]>=mx) h++;
		while(h<=t&&a[t]>=x) t--;
		q[++t]=y;a[t]=x;
	}
	inline int ans() {return a[h];}
}q[N],tmp;
int main()
{
	n=read(),m=read(),a=read(),b=read();
	g=read(),x=read(),y=read(),z=read();
	for(re i=1;i<=n;i++)
	for(re j=1;j<=m;j++)
	h[i][j]=g,g=((ll)g*x+y)%z;
	for(re i=1;i<=n;i++) q[i].clear(b);
	for(re j=1;j<=m;j++)
	{
		for(re i=1;i<=n;i++) q[i].ins(h[i][j],j);
		if(j>=b)
		{
			tmp.clear(a);
			for(re i=1;i<=n;i++)
			{
				tmp.ins(q[i].ans(),i);
				if(i>=a) ans+=tmp.ans();
			}
		}
	}
	cout<<ans<<endl;
}