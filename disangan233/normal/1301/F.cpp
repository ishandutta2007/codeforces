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
const int N=1e3+5,M=45;
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
int n,m,k,t,a[N][N],d[M][N][N],s[M][M],vis[M],l,r;
pii q[N*N];vector<pii>v[M]; 
in void init(int t)
{
	l=r=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]==t) q[++r]={i,j},d[t][i][j]=0;
	memset(vis,0,sizeof(vis));
	while(l<r)
	{
		pii u=q[++l];int x=u.fi,y=u.se,w=d[t][x][y];
		if(!vis[a[x][y]]) {vis[a[x][y]]=1;for(auto j:v[a[x][y]]) if(d[t][j.fi][j.se]>w+1) d[t][j.fi][j.se]=w+1,q[++r]=j;}
		if(x>0&&d[t][x-1][y]>w+1) d[t][x-1][y]=w+1,q[++r]={x-1,y};
		if(x<n&&d[t][x+1][y]>w+1) d[t][x+1][y]=w+1,q[++r]={x+1,y};
		if(y>0&&d[t][x][y-1]>w+1) d[t][x][y-1]=w+1,q[++r]={x,y-1};
		if(y<m&&d[t][x][y+1]>w+1) d[t][x][y+1]=w+1,q[++r]={x,y+1};
	}
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read(),v[a[i][j]].pb({i,j});
	t=read();memset(d,63,sizeof(d));
	for(int i=1;i<=k;i++) init(i);	
	for(int i=1;i<=t;i++)
	{
		int a=read(),b=read(),A=read(),B=read(),ans=abs(a-A)+abs(b-B);
		for(int j=1;j<=k;j++) ans=min(ans,d[j][a][b]+d[j][A][B]+1);
		write(ans,'\n');
	}
	return ot(),0;
}
//Author: disangan233