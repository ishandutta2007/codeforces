#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
#define pb push_back
const int N=1e6+5,p=1e9+7;
int n,m,k,tot,ch[N][26],len[N],fa[N],d[N],anc[N],f[N],g[N],lst;char s[N],t[N];
in void M(int &x) {x-=p;x+=x>>31&p;}
in void init() {len[tot=1]=-1,fa[0]=fa[1]=anc[0]=1;}
in void ins(int c,int n)
{
	int p=lst;while(s[n-len[p]-1]^s[n]) p=fa[p];
	if(!ch[p][c])
	{
		int v=++tot,q=fa[p];len[v]=len[p]+2;
		while(s[n-len[q]-1]^s[n]) q=fa[q];
		fa[v]=ch[q][c],ch[p][c]=v,d[v]=len[v]-len[fa[v]];
		anc[v]=(d[v]==d[fa[v]])?anc[fa[v]]:fa[v];
	}lst=ch[p][c];
}
int main()
{
	n=gs(t+1);f[0]=1,init();if(n&1) return write("0"),ot(),0;
	for(int i=1;i<=n;i+=2) s[i]=t[i/2+1];
	for(int i=2;i<=n;i+=2) s[i]=t[n-i/2+1];
	for(int i=1;i<=n;i++)
	{
		ins(s[i]-'a',i);
		for(int k=lst;k;k=anc[k])
		{
			g[k]=f[i-len[anc[k]]-d[k]];
			if(anc[k]^fa[k]) M(g[k]+=g[fa[k]]);
			if(!(i&1)) M(f[i]+=g[k]);
		}
	}write(f[n],'\n');
	return ot(),0;
}
//Author: disangan233