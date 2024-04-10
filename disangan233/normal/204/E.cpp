#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define db double
#define in inline
#define pb push_back
char buf[1<<12],*p1=buf,*p2=buf;
in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
in int read()
{
	re x=0,y=1;char c;while(c=gc(),(c<48||c>57)&&c!=-1) if(c==45) y=-1;
	x=c-48;while(c=gc(),47<c&&c<58) x=(x<<3)+(x<<1)+(c^48);return x*y;
}
in void gs(char *s) {char c;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32) *s++=c;}
const int N=3e5+5,inf=1e9;
int n,m,le,tot=1,rt=1,ch[N<<1][26],len[N<<1],fa[N<<1],sum[N<<1],lst=1;
ll ans;
vector<char>s[N];
set<int>st[N];
in void ins(re c,re id)
{
	re p=lst,np=lst=++tot;len[np]=len[p]+1;
	fa[np]=rt;st[np].insert(id);
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(p)
	{
		re q=ch[p][c],nq;
		if(len[q]==len[p]+1) fa[np]=q;
		else
		{
			nq=++tot;fa[nq]=fa[q];len[nq]=len[p]+1;
			fa[q]=fa[np]=nq;memcpy(ch[nq],ch[q],4*26);
			for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
}
vector<int>g[N<<1];
in void add(re x,re y) {g[x].pb(y);}
void dfs(re u)
{
	for(auto v:g[u]) 
	{
		dfs(v);
		if(st[u].size()<st[v].size()) swap(st[u],st[v]);
		for(auto it:st[v]) st[u].insert(it);
	}
	sum[u]=st[u].size();
}
int main()
{
	n=read(),m=read();
	for(re i=1;i<=n;i++)
	{
		static char ch[N];gs(ch+1);
		re k=strlen(ch+1);
		for(re j=1;j<=k;j++) ins(ch[j]-'a',i),s[i].pb(ch[j]),ch[j]=0;
		lst=1;
	}
	for(re i=2;i<=tot;i++) add(fa[i],i);dfs(rt);
	for(re i=1;i<=n;i++)
	{
		ll ans=0;re p=rt;
		for(auto x:s[i])
		{
			p=ch[p][x-'a'];
			while(p&&sum[p]<m) p=fa[p];
			ans+=len[p];
		}
		printf("%lld ",ans);
	}
	return 0;
}
//Author: disangan233