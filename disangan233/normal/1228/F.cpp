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
}
using namespace fast_io;   
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int N=17;
int n;pii f[1<<N];set<int>s[1<<N];
vector<int>ans,e[1<<N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
void dfs(int u,int fa) {for(int v:e[u]) if(v^fa) s[u].insert(v),dfs(v,u);}
in void calc(int u)
{
	if(s[u].size()==0) f[u]={0,1};
	else if(s[u].size()==1) f[u]=f[*s[u].begin()]==mp(0,1)?mp(u,2):mp(-1,-1);
	else if(s[u].size()==2)
	{
		auto it=s[u].begin();auto x=f[*it],y=f[*++it]; if(x>y) swap(x,y); 
		if(!x.fi&&!y.fi) f[u]=x.se==y.se?mp(0,x.se+1):mp(-1,-1);
		else if(!x.fi&&y.fi>0) f[u]=x.se==y.se?mp(y.fi,x.se+1):mp(-1,-1);
		else f[u]=mp(-1,-1); 
	}
	else if(s[u].size()==3)
	{
		auto it=s[u].begin();auto x=f[*it],y=f[*++it],z=f[*++it];
		if(x>y) swap(x,y); if(x>z) swap(x,z); if(y>z) swap(y,z);
		if(!x.fi&&!y.fi&&!z.fi) f[u]=x.se==y.se&&y.se+1==z.se?mp(u,z.se+1):mp(-1,-1);
		else f[u]=mp(-1,-1);
	}
	else f[u]={-1,-1};
}
void solve(int u,int fa)
{
	if(f[u].fi>0) ans.pb(f[u].fi);
	for(int v:e[u]) if(v^fa)
	s[u].erase(v),s[v].insert(u),calc(u),calc(v),solve(v,u),s[u].insert(v),s[v].erase(u),calc(v),calc(u);
} 
void dp(int u,int fa) {for(int v:e[u]) if(v^fa) dp(v,u);calc(u);}
int main()
{
	n=read();for(int i=1;i<=(1<<n)-3;i++) add(read(),read());
	dfs(1,0);dp(1,0);solve(1,0);write((int)ans.size(),'\n');
	sort(ans.begin(),ans.end());for(int x:ans) write(x,' ');
	return ot(),0;
}
//Author: disangan233