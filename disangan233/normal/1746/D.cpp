// LUOGU_RID: 90740750
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1) if(nc==45) y=-1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58) x=(x<<3)+(x<<1)+(nc^48);return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0) y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y) z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++,*s++)sr[++C]=*s;sr[++C]='\n';}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
};
using namespace fast_io;
const int N=2e5+5;
int T,n,k,c[N],fa[N],l[N],r[N];ll a[N],f[N][2],ans;
vector<int>e[N];
void dfs(int u)
{
	f[u][0]=f[u][1]=0;
	int t=e[u].size();
	for(int v:e[u]) l[v]=l[u]/t,r[v]=r[u]/t+(r[u]%t>0),dfs(v);
}
priority_queue<int>q;
void dp(int u)
{
	f[u][0]=a[u]*l[u],f[u][1]=a[u]*r[u];int k1=0,k2=0,t=e[u].size();
	for(int v:e[u]) dp(v),f[u][0]+=f[v][0],f[u][1]+=f[v][0],k1=l[u]-l[v]*t,k2=r[u]-l[v]*t;
	while(!q.empty()) q.pop();
	for(int v:e[u]) q.push(f[v][1]-f[v][0]);
	while(k1&&q.size()) k1--,f[u][0]+=q.top(),q.pop();
	while(!q.empty()) q.pop();
	for(int v:e[u]) q.push(f[v][1]-f[v][0]);
	while(k2&&q.size()) k2--,f[u][1]+=q.top(),q.pop();
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),l[1]=r[1]=read();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=2;i<=n;i++) e[fa[i]=read()].push_back(i);
		for(int i=1;i<=n;i++) a[i]=read();
		dfs(1);dp(1);
		write(f[1][1],'\n');
	}
	return ot(),0;
}