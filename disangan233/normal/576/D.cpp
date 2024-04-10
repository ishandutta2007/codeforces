#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
}
using namespace fast_io;
#define pb push_back
#define bt bitset<N>
const int N=1.5e2+5;
int n,m;ll d[N],ans;bt v;
struct did{
	int u,v,w;in void init() {u=read()-1,v=read()-1,w=read();}
	in bool operator<(did a) const {return w<a.w;}
}e[N];
struct mat{
	bt a[N];
	in bt& operator[](int x) {return a[x];}
	in mat operator*(mat b)
	{
		mat c;for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(a[i][j])c[i]|=b[j];return c;
	}
	in bt operator*(bt b) {bt c;for(int i=0;i<n;i++)c[i]=(a[i]&b).any();return c;}
	in void qpow(int b,bt& c) {mat a=*this;for(;b;b>>=1,a=a*a)if(b&1)c=a*c;}
}a;
int main()
{
	n=read(),m=read();for(int i=0;i<m;i++) e[i].init();
	sort(e,e+m);v[0]=1,ans=1e18;
	for(int i=0,t=0;e[i].w<ans&&i<m;i++)
	{
		a.qpow(e[i].w-t,v);a[e[i].v][e[i].u]=1;t=e[i].w;
		static int q[N*N];int l=0,r=0;
		for(int u=0;u<n;u++) if(v[u]) q[++r]=u,d[u]=0; else d[u]=1e18;
		while(l<r)
		{
			int u=q[++l];
			for(int v=0;v<n;v++) if(a[v][u]&&d[v]==1e18) d[v]=d[u]+1,q[++r]=v;
		}
		ans=min(ans,t+d[n-1]);
	}
	if(ans==1e18) write("Impossible"); else write(ans,'\n');
	return ot(),0;
}
//Author: disangan233