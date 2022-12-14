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
const int N=2e2+5,M=35;
int n,m,k,a[M],b[M][2],vis[N<<1];char s[N];
vector<int>e[N<<1];
unordered_map<char,int>mp;
int dfs(int u)
{
	if(vis[u>n?u-n:u+n]) return 0; vis[u]=1;
	for(int v:e[u]) if(!vis[v]&&!dfs(v)) return 0;
	return 1;
}
in int chk(int o)
{
	memset(vis+1,0,8*n);for(int i=1;i<=o;i++) if(!dfs(a[s[i]-'a'+1]*n+i)) return 0;
	for(int i=o+1;i<=n;i++)
	{
		if(vis[i]) s[i]=b[1][0]+'a'-1;
		else if(vis[i+n]) s[i]=b[1][1]+'a'-1;
		else
		{
			int x=min(b[1][0],b[1][1]),y=max(b[1][0],b[1][1]);
			if(dfs(a[x]*n+i)) s[i]=x+'a'-1;
			else if(dfs(a[y]*n+i)) s[i]=y+'a'-1;
			else return 0;
		}
	}return 1;
}
int main()
{
	k=gs(s+1);mp['V']=0,mp['C']=1;b[k+1][0]=b[k+1][1]=k+1;
	for(int i=k,t[2]={k+1,k+1};i;i--) t[a[i]=mp[s[i]]]=i,b[i][0]=t[0],b[i][1]=t[1];
	memset(s+1,0,2*k);n=read(),m=read();
	for(int i=1,x,s1,s2,t1,t2;i<=m;i++)
	{
		static char ch[2];
		x=read();gs(ch);s1=x+mp[ch[0]]*n,s2=(s1>n)?s1-n:s1+n;
		x=read();gs(ch);t1=x+mp[ch[0]]*n,t2=(t1>n)?t1-n:t1+n;
		e[s1].pb(t1),e[t2].pb(s2);
	}
	n=gs(s+1);if(chk(n)) return write(s+1),ot(),0;
	else if(b[1][0]==k+1||b[1][1]==k+1) return write("-1"),ot(),0;
	for(int i=n;i;i--)
	{
		int c=s[i]-'a'+2,x=min(b[c][0],b[c][1]),y=max(b[c][0],b[c][1]);
		if(x^(k+1)) {s[i]=x+'a'-1;if(chk(i)) return write(s+1),ot(),0;}
		if(y^(k+1)) {s[i]=y+'a'-1;if(chk(i)) return write(s+1),ot(),0;}
	}
	write("-1");
	return ot(),0;
}
//Author: disangan233