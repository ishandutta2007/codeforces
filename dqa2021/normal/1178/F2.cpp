#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
typedef long long ll;
const int Mod=998244353;

int n,m,c[1000010];
namespace Col
{
	int last[510],nxt[1000010];
}
int stk[1000010];
struct Edge{
	int to,nxt;
}edge[1010];
int idtot,cnt,last[1010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
void dfs1(int cur,int l,int r)
{
	for (int u=l;u<=r;u++)
	{
		addedge(cur,c[u]);
		for (int v=Col::nxt[u];v;v=Col::nxt[v])
		{
			if (u+1!=v) addedge(c[u],++idtot),dfs1(idtot,u+1,v-1);
			u=v;
		}
	}
}
int dfn[510];
int bin[510];
int L[1010],R[1010];
void dfs2(int cur)
{
	if (cur<=n)
	{
		for (int i=last[cur];i;i=edge[i].nxt) dfs2(edge[i].to);
		return;
	}
	(*bin)=0;
	for (int i=last[cur];i;i=edge[i].nxt) bin[++*bin]=edge[i].to;
	L[cur]=(*dfn)+1,R[cur]=(*dfn)+(*bin);
	for (int i=(*bin);i;i--) dfn[++*dfn]=bin[i];
	for (int i=last[cur];i;i=edge[i].nxt) dfs2(edge[i].to);
}
int dp[510][510]; bool vis[510][510];
int dfs(int l,int r)
{
	if (vis[l][r]) return dp[l][r];
	vis[l][r]=true;
	int minpos=-1;
	for (int i=l;i<=r;i++)
		if (minpos==-1||dfn[i]<dfn[minpos]) minpos=i;
	int subtree=1;
	for (int i=last[dfn[minpos]];i;i=edge[i].nxt)
		subtree=(ll)subtree*dfs(L[edge[i].to],R[edge[i].to])%Mod;
	int L=0,R=0;
	for (int i=minpos;i>=l;i--)
		L=(L+(ll)(i==l?1:dfs(l,i-1))*(i==minpos?1:dfs(i,minpos-1)))%Mod;
	for (int i=minpos;i<=r;i++)
		R=(R+(ll)(i==minpos?1:dfs(minpos+1,i))*(i==r?1:dfs(i+1,r)))%Mod;
	return dp[l][r]=(ll)L*R%Mod*subtree%Mod;
}
int main()
{
	n=read(),m=read(); idtot=n;
	for (int i=1;i<=m;i++)
	{
		c[i]=read();
	}
	for (int i=m;i;i--)
	{
		Col::nxt[i]=Col::last[c[i]]; Col::last[c[i]]=i;
	}
	for (int i=1;i<=m;i++)
	{
		if ((*stk)&&c[stk[*stk]]>c[i]) return puts("0"),0;
		if ((*stk)&&c[stk[*stk]]==c[i])
		{
			if (Col::nxt[i]) stk[*stk]=i;
			else (*stk)--;
			continue;
		}
		if (Col::nxt[i]) stk[++*stk]=i;
	}
	dfs1(++idtot,1,m); dfs2(n+1);
	printf("%d\n",dfs(L[n+1],R[n+1]));   //negative? no
	return 0;
}