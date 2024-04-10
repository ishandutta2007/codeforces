#include<bits/stdc++.h>
using namespace std;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
int n,i,j,m,k,kb,s,p[1000005],q[1000005],u,v,head[1000005],Next[2000005],adj[2000005];
int a[25],b[25],vis[1000005],f[1000005];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i)
{
	int j;
	vis[i]=1;
	for(j=head[i];j!=0;j=Next[j])
		if(!vis[adj[j]])
			dfs(adj[j]);
}
int cnt(int x)
{
	int ans=0;
	while(x)
	{
		++ans;
		x-=-x&x;
	}
	return ans;
}
void dfs2(int i,int s,int x)
{
	if(i>k)
	{
		if(s!=k&&s!=0&&s>=cnt(x))
		{
			puts("NO");
			exit(0);
		}
		return;
	}
	dfs2(i+1,s,x);
	dfs2(i+1,s+1,x|f[i]);
}
int main()
{
	gi(n),gi(m);
	for(i=1;i<=m;++i)
	{
		gi(u),gi(v);
		++p[u],++q[v];
		Push(u,v);
	}
	k=0;
	for(i=1;i<=n;++i)
	{
		if(!q[i])
			a[++k]=i;
		if(!p[i])
			b[++kb]=i;
	}
	for(i=1;i<=k;++i)
	{
		memset(vis,0,sizeof(vis));
		dfs(a[i]);
		for(j=1;j<=k;++j)
			if(vis[b[j]])
				f[i]|=1<<j-1;
	}
	dfs2(1,0,0);
	puts("YES");
}