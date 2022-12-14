#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[1<<12],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<!2,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getchar()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
int n,siz[200005],cnt,h[200005];
ll f[200005],ans;
struct did{int next,to;}e[400005];
in void Add(re x,re y) {e[++cnt]=(did){h[x],y},h[x]=cnt;}
in void add(re x,re y) {Add(x,y);Add(y,x);}
#define fo(u) for(re i=h[u],v;v=e[i].to,i;i=e[i].next)
in void dfs1(re u,re fa)
{
	siz[u]=1;
	fo(u) if(v!=fa) dfs1(v,u),siz[u]+=siz[v];
}
in void dfs2(re u,re fa)
{
	fo(u) if(v!=fa) f[v]=f[u]+n-siz[v]*2,dfs2(v,u);
}
int main()
{
	n=read();
	for(re i=1;i<n;i++) add(read(),read());
	dfs1(1,0);
	for(re i=1;i<=n;i++) f[1]+=siz[i];
	dfs2(1,0);
	for(re i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}