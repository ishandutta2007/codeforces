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
const int N=1e5+5,M=5e6+5;
int n,m,k,lst=1,tot=1,fa[N<<1],ch[N<<1][26],len[N<<1],rt[N<<1],f[N<<1][18],cnt[M],pos[M];
vector<int>e[N<<1];char q[M];
in void ins(int c)
{
	if(ch[lst][c]&&len[lst]+1==len[ch[lst][c]]) return lst=ch[lst][c],void();
	int p=lst,np=lst=++tot;len[np]=len[p]+1;fa[np]=1;
	for(;!ch[p][c];p=fa[p]) ch[p][c]=np;
	if(p)
	{
		int q=ch[p][c];
		if(len[p]+1==len[q]) fa[np]=q;
		else
		{
			int nq=++tot;len[nq]=len[p]+1;if(len[p]+1==len[np]) lst=nq;
			fa[nq]=fa[q];memcpy(ch[nq],ch[q],4*26);fa[np]=fa[q]=nq;
			for(;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
}
#define mid ((l+r)>>1)
#define mp make_pair
int nd,ls[N*160],rs[N*160];pair<int,int> s[N*160];
void ins(int &p,int l,int r,int x)
{
	if(!p)p=++nd;if(l==r) return s[p]=mp(s[p].first+1,-l),void();
	x<=mid?ins(ls[p],l,mid,x):ins(rs[p],mid+1,r,x);s[p]=max(s[ls[p]],s[rs[p]]);
}
pair<int,int> ask(int p,int l,int r,int L,int R)
{
	if(!p||R<l||r<L) return mp(0,0);if(L<=l&&r<=R) return s[p];
	return max(ask(ls[p],l,mid,L,R),ask(rs[p],mid+1,r,L,R));
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y) return x|y;int p=++nd;if(l==r) return s[p]=s[x],s[p].first+=s[y].first,p;
	ls[p]=merge(ls[x],ls[y],l,mid);rs[p]=merge(rs[x],rs[y],mid+1,r);return s[p]=max(s[ls[p]],s[rs[p]]),p;
}
void dfs(int u)
{
	for(int i=1;i<18;i++) if(f[u][i-1]) f[u][i]=f[f[u][i-1]][i-1];
	for(int v:e[u]) f[v][0]=u,dfs(v),rt[u]=merge(rt[u],rt[v],1,n);
}
int main()
{
	k=gs(q+1);n=read();
	for(int i=1;i<=n;i++)
	{
		static char s[N];int m=gs(s+1);lst=1;
		for(int j=1;j<=m;j++) ins(s[j]-'a'),ins(rt[lst],1,n,i);
		memset(s+1,0,2*m);
	}
	for(int i=2;i<=tot;i++) e[fa[i]].pb(i);dfs(1);
	for(int i=1,j=0,p=1;i<=k;i++)
	{
		int c=q[i]-'a';
		if(ch[p][c]) p=ch[p][c],j++;
		else
		{
			while(p&&!ch[p][c]) p=fa[p];
			if(!p) p=1,j=0; else j=len[p]+1,p=ch[p][c];
		}
		pos[i]=p,cnt[i]=j;
	}
	m=read();
	while(m--)
	{
		int a=read(),b=read(),c=read(),d=read();
		int l=d-c+1;if(l>cnt[d]) {write(a,' '),write(0,'\n');continue;}
		int u=pos[d];for(int i=17;~i;i--) if(len[f[u][i]]>=l) u=f[u][i];
		pair<int,int>res=ask(rt[u],1,n,a,b);if(res.first==0) res.second=a;
		write(abs(res.second),' '),write(res.first,'\n');
	}
	return ot(),0;
}
//Author: disangan233