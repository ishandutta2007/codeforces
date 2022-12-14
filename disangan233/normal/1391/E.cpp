 #pragma GCC optimize(2,3,"Ofast")
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
	in int gst(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
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
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5;
int n,m,mxd,d[N],s[N];vector<int>e[N],vec[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);} 
void dfs(int u)
{
	mxd=max(mxd,d[u]),vec[d[u]].pb(u);
	for(int v:e[u]) if(!d[v]) d[v]=d[u]+1,dfs(v);
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read(),mxd=1;for(int i=1;i<=m;i++) add(read(),read());
		d[1]=1,dfs(1);
		if(mxd>(int)(n*1.00/2+0.5))
		{
			write("PATH");int t=0;
			for(int i=vec[mxd][0],dep=mxd;i>1&&dep>1;dep--) for(int j:e[i]) if(d[j]==dep-1) {s[++t]=i,i=j;break;}
			write(t+1,'\n');write(1,' ');for(;t;t--) write(s[t]," \n"[t==1]);
		}
		else
		{
			write("PAIRING");int k=0;for(int i=1;i<=mxd;i++) k+=vec[i].size()/2;write(k,'\n');
			for(int i=1;i<=mxd;i++) for(int j=0;j<vec[i].size()-1;j+=2) write(vec[i][j],' '),write(vec[i][j+1],'\n'); 
		}
		for(int i=1;i<=n;i++) e[i].clear(),d[i]=0;for(int i=1;i<=mxd;i++) vec[i].clear();
	}
	return ot(),0;
}
//Author: disangan233