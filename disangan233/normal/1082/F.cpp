#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define ld long db
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db find() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e2+5;
int n,K,ans,mx,cnt=1,ch[N][12],f[N][N][12],d[N],s[N],siz[N],len[N],a[N],t[N][12],fa[N][N];char g[N];
in void cmx(int &x,int y) {if(x<y)x=y;}
void dfs(int u) 
{
	fa[u][0]=u;siz[u]=1;for(int i=0;i<=len[u];i++) f[u][i][!i]=d[fa[u][i]]*s[u];
	for(int i=0,v;i<10;i++) if(v=ch[u][i]) 
	{
		d[v]=d[u]+1;for(int j=0;j<=len[u];j++) fa[v][++len[v]]=fa[u][j];dfs(v);
		for(int j=0;j<=len[u];j++) for(int k=0;k<=siz[u]&&k<=K;k++) t[j][k]=f[u][j][k],f[u][j][k]=-1e9;
		for(int j=0;j<=len[u];j++) for(int k=0;k<=siz[u]&&k<=K;k++) 
		for(int l=0;l<=siz[v]&&k+l<=K;l++) cmx(f[u][j][k+l],t[j][k]+max(f[v][j+1][l],f[v][0][l]));
		siz[u]+=siz[v]; 
	}
}
int main()
{
	n=read(),K=read()+1;memset(f,-63,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		int m=gs(g+1),p=1;a[i]=read();ans+=m*a[i];
		for(int j=1,c;j<=m;j++)
		{
			if(!ch[p][g[j]-'0']) ch[p][g[j]-'0']=++cnt;
			p=ch[p][g[j]-'0'];
		}
		s[p]+=a[i];memset(g+1,0,2*m);
	}
	dfs(1);for(int i=1;i<=K;i++) mx=max(mx,f[1][0][i]);
	write(ans-mx,'\n');
	return ot(),0;
}
//Author: disangan233