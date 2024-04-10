#include<cstdio>
#include<algorithm>
#define MaxN 100123
int ch[MaxN<<5][2];
int ans[MaxN<<5];
int n,cnt;
int a[MaxN];
inline void Insert(int u)
{
	int cur=0;
	for(int i=30,c;~i;--i)
	{
		c=((u>>i)&1);
		if(!ch[cur][c])ch[cur][c]=++cnt;
		cur=ch[cur][c];
	}
}
inline void Dfs(int u,int depth=29)
{
	#ifdef Dubug
	printf("Dfs(%d,%d);\n",u,depth);
	#endif
	if(ch[u][0])Dfs(ch[u][0],depth-1);
	if(ch[u][1])Dfs(ch[u][1],depth-1);
	if(ch[u][0]&&ch[u][1])
	ans[u]=(1<<depth)+std::min(ans[ch[u][0]],ans[ch[u][1]]);
	else ans[u]=std::max(ans[ch[u][0]],ans[ch[u][1]]);
	#ifdef Dubug
	printf("ans[%d]=%d\n",u,ans[u]);
	#endif
}
inline void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	Insert(a[i]);
	Dfs(1,29);
	printf("%d\n",ans[1]);
}
int main()
{
	Solve();
	return 0;
}