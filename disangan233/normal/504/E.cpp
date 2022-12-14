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
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
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
const int N=3e5+5,b1=19260817,b2=20191001,P1=998244353,P2=1e9+7;
int n,m,tim,dfn[N],dep[N],fa[N],son[N],top[N],siz[N];
char s[N],t[N];ll pw1[N],pw2[N],s1[N],s2[N],s3[N],s4[N];
struct pii
{
	int a,b;
	in bool operator==(pii x)const{return a==x.a&&b==x.b;}
	in bool operator!=(pii x)const{return a!=x.a||b!=x.b;}
};
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
in pii ask1(int l,int r) {return {(int)(s1[r]+P1-s1[l-1]*pw1[r-l+1]%P1)%P1,(int)(s2[r]+P2-s2[l-1]*pw2[r-l+1]%P2)%P2};}
in pii ask2(int l,int r) {return {(int)(s3[l]+P1-s3[r+1]*pw1[r-l+1]%P1)%P1,(int)(s4[l]+P2-s4[r+1]*pw2[r-l+1]%P2)%P2};}
void dfs1(int u)
{
	siz[u]=1;
	for(int v:e[u]) if(v^fa[u])
	{
		fa[v]=u,dep[v]=dep[u]+1,dfs1(v);siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp;dfn[u]=++tim;t[tim]=s[u];if(son[u]) dfs2(son[u],tp);
	for(int v:e[u]) if(v^fa[u]&&v^son[u]) dfs2(v,v);
}
in int ask(int u,int v,pii *p)
{
	vector<pii>v1,v2;
	while(top[u]^top[v])
	{
		if(dep[top[u]]>dep[top[v]]) v1.pb({dfn[u],dfn[top[u]]}),u=fa[top[u]];
		else v2.pb({dfn[top[v]],dfn[v]}),v=fa[top[v]];
	}
	v1.pb({dfn[u],dfn[v]});int cnt=0;
	for(auto x:v1) p[++cnt]=x; int l=cnt;
	for(auto x:v2) p[++cnt]=x; reverse(p+l+1,p+cnt+1);
	return cnt;
}
in int solve(int a,int b,int c,int d)
{
	pii p[105],q[105];int n=ask(a,b,p),m=ask(c,d,q),i=1,j=1,d1=0,d2=0,ans=0;
	while(i<=n&&j<=m)
	{
		int l1=abs(p[i].a-p[i].b)+1,l2=abs(q[j].a-q[j].b)+1,d=min(l1-d1,l2-d2);
		int v1=p[i].a>p[i].b,v2=q[j].a>q[j].b;
		pii t1=(!v1)?ask1(p[i].a+d1,p[i].a+d1+d-1):ask2(p[i].a-d1-d+1,p[i].a-d1);
		pii t2=(!v2)?ask1(q[j].a+d2,q[j].a+d2+d-1):ask2(q[j].a-d2-d+1,q[j].a-d2);
		if(t1!=t2)
		{
			int l=0,r=d;
			while(l<r)
			{
				int m=((l+r)>>1)+1;
				t1=(!v1)?ask1(p[i].a+d1,p[i].a+d1+m-1):ask2(p[i].a-d1-m+1,p[i].a-d1);
				t2=(!v2)?ask1(q[j].a+d2,q[j].a+d2+m-1):ask2(q[j].a-d2-m+1,q[j].a-d2);
				(t1==t2)?l=m:r=m-1;
			}
			ans+=l;break;
		}
		ans+=d;d1+=d;d2+=d;
		if(d1==l1) i++,d1=0; if(d2==l2) j++,d2=0;
	}
	return ans;
}
int main()
{
	n=read();gs(s+1);for(int i=1;i<n;i++) add(read(),read());
	pw1[0]=pw2[0]=1;for(int i=1;i<=n;i++) pw1[i]=pw1[i-1]*b1%P1,pw2[i]=pw2[i-1]*b2%P2;
	dfs1(1);dfs2(1,1);
	for(int i=1;i<=n;i++) s1[i]=(s1[i-1]*b1+t[i])%P1,s2[i]=(s2[i-1]*b2+t[i])%P2;
	for(int i=n;i;i--) s3[i]=(s3[i+1]*b1+t[i])%P1,s4[i]=(s4[i+1]*b2+t[i])%P2;
	m=read();
	while(m--)
	{
		int a=read(),b=read(),c=read(),d=read();
		write(solve(a,b,c,d),'\n');
	}
	return ot(),0;
}
//Author: disangan233