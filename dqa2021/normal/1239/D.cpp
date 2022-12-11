#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}

int T;
int n,m;
struct Edge{
	int to,nxt;
}edge[1000010];
int cnt,last[1000010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int dfn[1000010],low[1000010];
bool vis[1000010]; int stk[1000010];
int col[1000010];
void tarjan(int cur)
{
	dfn[cur]=low[cur]=++*dfn;
	vis[cur]=true; stk[++*stk]=cur;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			low[cur]=min(low[cur],low[edge[i].to]);
		}
		else if (vis[edge[i].to]) low[cur]=min(low[cur],dfn[edge[i].to]);
	if (dfn[cur]^low[cur]) return;
	++*col;
	while (stk[*stk]^cur)
	{
		vis[stk[*stk]]=false;
		col[stk[*stk]]=*col;
		--*stk;
	}
	vis[stk[*stk]]=false;
	col[stk[*stk]]=*col;
	--*stk;
}
int A[1000010],B[1000010];
void solve()
{
	n=read(),m=read();
	for (int i=1,x,y;i<=m;i++) x=read(),y=read(),addedge(x,y);
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++)
		if (col[i]<(*col)) A[++*A]=i;
		else B[++*B]=i;
	if ((*A)&&(*B))
	{
		puts("Yes");
		printf("%d %d\n",(*A),(*B));
		for (int i=1;i<=(*A);i++) printf("%d ",A[i]); putchar('\n');
		for (int i=1;i<=(*B);i++) printf("%d ",B[i]); putchar('\n');
	}
	else puts("No");
	
	cnt=0; memset(last+1,0,n*sizeof(int));
	(*dfn)=0; memset(dfn+1,0,n*sizeof(int));
	(*col)=0; (*A)=(*B)=0;
}
int main()
{
	T=read();
	while (T--) solve();
	return 0;
}