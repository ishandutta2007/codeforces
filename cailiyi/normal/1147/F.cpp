#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define N 50
using namespace std;
int T,n,a[N+5][N+5],p[N+5][N+5],cp[N*2+5],top[N+5],u;
char ch;
inline void match(bool flag)
{
	queue<int> q;
	memset(cp,0,sizeof cp);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j) p[i][j]=j;
		sort(p[i]+1,p[i]+1+n,[&](int x,int y){return (a[i][x]<a[i][y])^flag;});
		for(int j=1;j<=n;++j) p[i][j]+=n;
		q.push(i),top[i]=0;
	}
	while(!q.empty())
	{
		while(!q.empty())
		{
			int x=q.front(),y=p[x][++top[x]];q.pop();
			if(!cp[y]) cp[cp[y]=x]=y;
			else if((a[x][y-n]>a[cp[y]][y-n])^flag) cp[cp[y]]=0,cp[cp[y]=x]=y;
		}
		for(int i=1;i<=n;++i) if(!cp[i]) q.push(i);
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&a[i][j]);
		puts("B"),fflush(stdout);
		for(ch=getchar();ch!='I' && ch!='D';ch=getchar());
		scanf("%d",&u),match((u<=n)^(ch=='I'));
		do
		{
			printf("%d\n",cp[u]);
			fflush(stdout);
			scanf("%d",&u);
		}while(u>0);
		if(u==-2) return 0;
	}
	return 0;
}