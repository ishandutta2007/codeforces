#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,Ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;Ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)Ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*Ny;
	}
	in db gf() {int a=read(),y=Ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e5+5;
int n,m,k,ans,b[15][15],b2[15][15][15][15],c[N][15][15],a[15];
vector<pii>e[N];
in void add(int u,int v,int w) {e[u].pb({w,v});}
void dfs1(int u)
{
	if(u==k+1)
	{
		for(int i=1;i<=k;i++)if(b[i][a[i]])return;
		for(int i=1;i<=k;i++) for(int j=i+1;j<=k;j++) if(b2[i][a[i]][j][a[j]]) return;
		ans++;return;
	}
	for(int i=1;i<=u;i++) a[u]=i,dfs1(u+1);
}
int main()
{
	n=read();m=read(),k=read();
	for(int i=1,u,v;i<=m;i++) u=read(),v=read(),add(u,v,read());
	for(int i=1;i<=n;i++)
	{
		if(!e[i].size()) return write("0"),ot(),0;sort(e[i].begin(),e[i].end());
		int cnt=0;for(auto j:e[i]) c[j.se][e[i].size()][++cnt]++;
	}
	for(int u=1;u<=n;u++)
	{
		vector<pii>nw;
		for(int i=1;i<=k;i++)  for(int j=1;j<=i;j++)
		{if(c[u][i][j]>=2) {b[i][j]=1;continue;}if(c[u][i][j]==1) nw.pb({i,j});}
		for(int i=0;i<nw.size();i++) for(int j=i+1;j<nw.size();j++) b2[nw[i].fi][nw[i].se][nw[j].fi][nw[j].se]=1;
	}
	dfs1(1);write(ans,'\n');
	return ot(),0;
}
//Author: disangan233