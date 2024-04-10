#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=5005,M=1e6+5;
int n,na,nb,nc,p[N];
struct ho{
	int y,l,r;
	in bool operator < (ho p) const {return y<p.y;}
}b[N];
struct ve{
	int x,l,r;
	in bool operator < (ve p) const {return r<p.r;}
}a[N],c[N];
ll ans;
struct bit{
	int t[N*3];
	in void clear() {memset(t,0,sizeof(t));}
	in int lowbit(re x) {return x&-x;}
	in void upd(re x,re y) {for(;x<=15000;x+=lowbit(x)) t[x]+=y;}
	in int ask(re x) {re y=1;for(;x;x-=lowbit(x)) y+=t[x];return y;}
	in int ask(re x,re y) {return ask(y)-ask(x-1);}
}t;
int main()
{
	n=read();
	for(re i=1;i<=n;i++)
	{
		re x1=read(),y1=read(),x2=read(),y2=read();
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
		if(x1==x2) a[++na]=(ve){x1,y1,y2};
		else b[++nb]=(ho){y1,x1,x2};
	}
	sort(a+1,a+na+1);sort(b+1,b+nb+1);
	for(re i=1;i<=nb;i++)
	{
		nc=0;
		for(re j=1;j<=na;j++)
		if(a[j].x>=b[i].l&&a[j].x<=b[i].r&&b[i].y>=a[j].l&&b[i].y<=a[j].r)
		c[++nc]=a[j],t.upd(a[j].x+5001,1);
		re nw=1;
		for(re j=i+1;j<=nb;j++)
		if(b[i].y!=b[j].y)
		{
			while(nw<=nc&&c[nw].r<b[j].y) t.upd(c[nw++].x+5001,-1);
			re cnt=t.ask(b[j].l+5001,b[j].r+5001);
			ans+=(ll)(cnt)*(cnt-1)/2;
		}
		t.clear();
	}
	cout<<ans;
}