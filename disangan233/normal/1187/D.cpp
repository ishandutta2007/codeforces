#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[1<<12],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<!2,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getchar()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
int opt,n,a[300005],b[300005],c[300005],d[300005],t[1200005],nw[300005],pre[300005];
in void push_up(re x) {t[x]=max(t[ls(x)],t[rs(x)]);}
void build(re p,re l,re r)
{
	if(l==r) return t[p]=a[l],void();
	re mid=(l+r)>>1;
	build(ls(p),l,mid);build(rs(p),mid+1,r);
	push_up(p);
}
void update(re p,re l,re r,re x)
{
	if(l==r) return t[p]=0,void();
	re mid=(l+r)>>1;
	if(mid>=x) update(ls(p),l,mid,x);
	else update(rs(p),mid+1,r,x);
	push_up(p);
}
int query(re p,re l,re r,re ql,re qr)
{
	if(ql<=l&&r<=qr) return t[p];
	re mid=(l+r)>>1,maxn=0;
	if(mid>=ql) maxn=query(ls(p),l,mid,ql,qr);
	if(mid<qr) maxn=max(maxn,query(rs(p),mid+1,r,ql,qr));
	return maxn;
}
int main()
{
	opt=read();
	while(opt--)
	{
		n=read();
		for(re i=1;i<=n;i++) a[i]=c[i]=read();
		for(re i=1;i<=n;i++) b[i]=d[i]=read();
		sort(c+1,c+n+1);sort(d+1,d+n+1);
		re op=0;
		for(re i=1;i<=n;i++)
		if(c[i]!=d[i]) {puts("NO");op=1;break;}
		if(op) continue;
		for(re i=1;i<=n;i++) nw[i]=0;
		for(re i=1;i<=n;i++)
		if(!nw[c[i]]) nw[c[i]]=i;
		for(re i=1;i<=n;i++) d[i]=nw[i];
		for(re i=1;i<=n;i++)
		{
			re tmp=a[i];a[i]=nw[a[i]];
			nw[tmp]++;pre[a[i]]=i;
		}
		for(re i=1;i<=n;i++) nw[i]=d[i];
		for(re i=1;i<=n;i++)
		{
			re tmp=b[i];b[i]=nw[b[i]];nw[tmp]++;
		}
		build(1,1,n);
		re ok=1;
		for(re i=n;i;i--)
		{
			if(query(1,1,n,pre[b[i]],n)>b[i]) {ok=0;break;}
			update(1,1,n,pre[b[i]]);
		}
		puts(ok?"YES":"NO");
	}
}