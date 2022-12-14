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
const int N=3e5+5;
int n,m,ans,fa[N],siz[N],val[N],vis[N],l[N],r[N],id[N],tag[N];
char s[N];
struct pii{int a,b;};
pii getfa(int x) {int op=tag[x];while(fa[x]) x=fa[x],op^=tag[x];return {x,op};}
in void merge(int a,int b) {fa[a]=b;siz[b]+=siz[a];val[b]+=val[a];vis[b]|=vis[a];tag[a]^=tag[b];}
int main()
{
	n=read(),m=read(),gs(s+1);
	for(int i=1;i<=m;i++)
	{
		int k=read();
		for(int j=1,x;j<=k;j++) x=read(),(!id[x])?id[x]=i:(l[x]=id[x],r[x]=i);
	}
	for(int i=1;i<=m;i++) siz[i]=1;
	for(int i=1;i<=n;i++)
	{
		if(!l[i])
		{
			if(!id[i]) {write(ans,'\n');continue;}
			pii x=getfa(id[i]);
			if(!(x.b^(s[i]-'0'))) tag[x.a]^=1,ans+=(siz[x.a]-2*val[x.a]),val[x.a]=siz[x.a]-val[x.a];
			vis[x.a]=1;write(ans,'\n');continue;
		}
		pii x=getfa(l[i]),y=getfa(r[i]);if(siz[x.a]>siz[y.a]) swap(x,y); 
		if(x.a==y.a) {write(ans,'\n');continue;}
		if(!(x.b^y.b^(s[i]-'0')))
		{
			int sa=siz[x.a]-2*val[x.a],sb=siz[y.a]-2*val[y.a];
			if((sa<sb&&!vis[x.a])||vis[y.a]) ans+=sa,val[x.a]=siz[x.a]-val[x.a],tag[x.a]^=1;
			else ans+=sb,val[y.a]=siz[y.a]-val[y.a],tag[y.a]^=1;
		}
		merge(x.a,y.a);write(ans,'\n');
	}
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.
/*
abccba
bbaacc
*/