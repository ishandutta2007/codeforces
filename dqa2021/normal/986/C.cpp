#include<cstdio>
char ch;
void read(int &x)
{
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for (x=0;ch<='9'&&ch>='0';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
}
int n,m,a[(1<<22)+10];
int pos[(1<<22)+10];
int que[(1<<23)+10],hd,tl;
bool vis[(1<<23)+10];
void bfs(int x)
{
	int u;
	hd=tl=0;
	vis[x]=true,que[++tl]=x;
	while (hd<tl)
	{
		hd++;
		if (que[hd]<=m)
		{
			if (!vis[m+1+a[que[hd]]])
				vis[m+1+a[que[hd]]]=true,que[++tl]=m+1+a[que[hd]];
			continue;
		}
		u=que[hd]-m-1;
		for (int i=0;i<n;i++)
			if (!((u>>i)&1)&&!vis[m+1+(u|(1<<i))])
				vis[m+1+(u|(1<<i))]=true,que[++tl]=m+1+(u|(1<<i));
		if (pos[(~u)&((1<<n)-1)]&&!vis[pos[(~u)&((1<<n)-1)]])
			vis[pos[(~u)&((1<<n)-1)]]=true,que[++tl]=pos[(~u)&((1<<n)-1)];
	}
}
int ans;
int main()
{
	read(n);read(m);
	for (int i=1;i<=m;i++)
	{
		read(a[i]);
		pos[a[i]]=i;
	}
	for (int i=1;i<=m;i++)
		if (!vis[i])
			ans++,bfs(i);
	printf("%d\n",ans);
	return 0;
}