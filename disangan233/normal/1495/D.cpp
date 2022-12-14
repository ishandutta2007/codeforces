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
const int N=1e3+5,p=998244353,sn[2]={-1,1};
int n,m,a[N],d[N][N],s[N][N],q[N];
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
void bfs(int s,int *d)
{
	int l=0,r=0;for(int i=1;i<=n;i++) d[i]=-1;d[q[++r]=s]=0;
	while(l<r)
	{
		int u=q[++l];for(int v:e[u]) if(!~d[v]) d[q[++r]=v]=d[u]+1;
	}
}
in int ask(int x,int y)
{
	memset(a,0,4*(n+1));int res=1,L=d[x][y];
	for(int i=1;i<=n;i++) if(d[x][i]+d[i][y]==L) a[d[x][i]]++;
	for(int i=0;i<=n;i++) if(a[i]>1) return 0;
	for(int u=1;u<=n;u++) if(u^x)
	{
		int coef=0,op=d[x][u]+d[u][y]==L;
		for(int v:e[u]) coef+=d[x][u]-1==d[x][v]&&d[u][y]+sn[op]==d[v][y];
		res=1ll*res*coef%p;
	}return res;
}
int main()
{
	n=read(),m=read();for(int i=1;i<=m;i++) add(read(),read());
	for(int i=1;i<=n;i++) bfs(i,d[i]); 
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) s[i][j]=s[j][i]=ask(i,j);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) write(s[i][j]," \n"[j==n]);
	return ot(),0;
}
//Author: disangan233