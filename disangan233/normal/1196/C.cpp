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
#define gc() getch()
char qwq;
inline ll read()
{
    ll cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
const int N=3e5+5,mod=1e9+7;
int n,k;
struct did{
	int x,y,a,b,c,d;
}p[N];
int main()
{
	re t=read();
	while(t--)
	{
		n=read();
		for(re i=1;i<=n;i++) p[i]=(did){read(),read(),read(),read(),read(),read()};
		re x1=1e5,y1=1e5,x2=-x1,y2=-y1,op=0;
		for(re i=1;i<=n;i++)
		{
			if(!p[i].c) x1=min(x1,p[i].x);
			if(!p[i].d) y2=max(y2,p[i].y);
			if(!p[i].a) x2=max(x2,p[i].x);
			if(!p[i].b) y1=min(y1,p[i].y);
		}
		if(x1<x2||y1<y2) puts("0");
		else printf("1 %d %d\n",x2,y2);
	}
}