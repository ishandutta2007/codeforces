// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
#define lrb lower_bound 
#define int ll
const int N=4e5+5;
int n,ta[N<<1],tb[N<<1],la[N],ra[N],lb[N],rb[N],na,nb;
struct qry{
	int a,b,c,d;	
}s[N],s1[N],s2[N];
struct bit{
	int t1[N<<1],t2[N<<1];
	in void upd(int *t,int x,int y) {for(;x<=max(nb,na);x+=x&-x)t[x]+=y;}
	in int ask(int *t,int x) {int y=0;for(;x;x-=x&-x)y+=t[x];return y;}
	in void upd(int l,int r,int x) {upd(t1,l,x);upd(t1,r+1,-x);upd(t2,l,x*l);upd(t2,r+1,-(r+1)*x);}
	in int ask(int l,int r) {return ((r+1)*ask(t1,r)-ask(t2,r))-(l*ask(t1,l-1)-ask(t2,l-1));} 
}t;
signed main()
{
	n=read();for(int i=1;i<=n;i++) la[i]=read(),ra[i]=read(),lb[i]=read(),rb[i]=read(),ta[++na]=la[i],ta[++na]=ra[i],tb[++nb]=lb[i],tb[++nb]=rb[i];
	sort(ta+1,ta+na+1);na=unique(ta+1,ta+na+1)-ta-1;
	sort(tb+1,tb+nb+1);nb=unique(tb+1,tb+nb+1)-tb-1;
	for(int i=1;i<=n;i++)
	{
		la[i]=lrb(ta+1,ta+na+1,la[i])-ta;ra[i]=lrb(ta+1,ta+na+1,ra[i])-ta;
		lb[i]=lrb(tb+1,tb+nb+1,lb[i])-tb;rb[i]=lrb(tb+1,tb+nb+1,rb[i])-tb;
		s1[i]=s2[i]={la[i],ra[i],lb[i],rb[i]};
	}
	memset(t.t1,sizeof(t.t1),0);memset(t.t2,sizeof(t.t2),0);
	sort(s1+1,s1+n+1,[](qry a,qry b){return a.a<b.a;});
	sort(s2+1,s2+n+1,[](qry a,qry b){return a.b<b.b;});
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n&&s2[j].b<s1[i].a) t.upd(s2[j].c,s2[j].d,1),j++;
		if(t.ask(s1[i].c,s1[i].d)) return write("NO"),ot(),0; 
	}
	memset(t.t1,0,sizeof(t.t1));memset(t.t2,0,sizeof(t.t2));
	sort(s1+1,s1+n+1,[](qry a,qry b){return a.c<b.c;});
	sort(s2+1,s2+n+1,[](qry a,qry b){return a.d<b.d;});
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n&&s2[j].d<s1[i].c) t.upd(s2[j].a,s2[j].b,1),j++;
		if(t.ask(s1[i].a,s1[i].b)) return write("NO"),ot(),0; 
	}
	write("YES");
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.