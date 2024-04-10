#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
// 	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	#define gc getchar
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
};
using namespace fast_io;
const int N=3e5+5;
int n,m,tot,ch[N][26],vis[N][26],fail[N],cnt[N],sum[N],rt[N],siz[N];
char s[N];
struct acam
{
	int st[N],t;
	int merge(int x,int y)
	{
		if(!x||!y) return x+y;
		for(int i=0;i<26;i++) ch[x][i]=merge(ch[x][i],ch[y][i]);
		return cnt[x]+=cnt[y],x;
	}
	in void build(int id)
	{
		static int q[N*10];int l=0,r=0;
		for(int i=0;i<26;i++)
		if(ch[rt[id]][i]) fail[vis[rt[id]][i]=ch[rt[id]][i]]=rt[id],q[++r]=vis[rt[id]][i];
		else vis[rt[id]][i]=rt[id];
		while(l<r)
		{
			int u=q[++l];sum[u]=cnt[u]+sum[fail[u]];
			for(int i=0;i<26;i++)
			if(ch[u][i]) fail[vis[u][i]=ch[u][i]]=vis[fail[u]][i],q[++r]=vis[u][i];
			else vis[u][i]=vis[fail[u]][i];
		}
	}
	in int ask(char *s)
	{
		int n=strlen(s+1),res=0;
		for(int i=1;i<=t;i++) for(int j=1,u=rt[st[i]];j<=n;j++) u=vis[u][s[j]-'a'],res+=sum[u];
		return res;
	}
	in void ins(char *s)
	{
		int n=strlen(s+1),id=++tot;if(!rt[id]) rt[id]=++m;
		int p=rt[id];for(int i=1;i<=n;i++) ch[p][s[i]-'a']=++m,p=ch[p][s[i]-'a'];
		cnt[p]++;siz[id]=1;while(t&&siz[st[t]]==siz[id]) rt[id]=merge(rt[id],rt[st[t]]),siz[id]+=siz[st[t--]];
		build(st[++t]=id);
	}
}t1,t2;
int main()
{
	n=read();
	while(n--)
	{
		int op=read();gs(s+1);
		if(op==1) t1.ins(s);
		else if(op==2) t2.ins(s);
		else printf("%d\n",t1.ask(s)-t2.ask(s));
		fflush(stdout);memset(s,0,sizeof(char)*(strlen(s+1)+1));
	}
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.