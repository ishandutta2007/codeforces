#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int S=0,T=100,inf=0x3f3f3f3f;
struct bian{int nxt,to,f;}bi[2020];
int n,mp[10][10],m,cnt[10];
int p[10],b[10][2],d[10],head[110],num,id[10][10],tot;
inline void add(int from,int to,int f){bi[++num]=bian{head[from],to,f};head[from]=num;}
inline void ADD(int from,int to,int f){add(from,to,f),add(to,from,0);}
int dep[110],sum,pos[10],key[10];
bool bfs()
{
	queue<int>q;
	memset(dep,0,sizeof(dep));dep[S]=1;q.push(S);
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=head[x];i;i=bi[i].nxt)
			if(bi[i].f)
			{
				y=bi[i].to;
				if(!dep[y])dep[y]=dep[x]+1,q.push(y);
			}
	}
	return dep[T]!=0;
}
int dfs(int v,int last)
{
	if(v==T)
	{
		sum+=last;
		return last;
	}
	int now=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
		if(bi[i].f)
		{
			u=bi[i].to;
			if(dep[u]!=dep[v]+1)continue;
			int dmin=dfs(u,min(last,bi[i].f));
			bi[i].f-=dmin,bi[i^1].f+=dmin;
			last-=dmin,now+=dmin;
			if(!last)break;
		}
	return now;
}
void work()
{
	priority_queue<int>q;
	for(int i=1;i<=m-2;++i)++d[p[i]];
	for(int i=1;i<=m;++i)if(!d[i])q.push(i);
	for(int i=1;i<=m-2;++i)
	{
		b[i][0]=q.top();q.pop();
		b[i][1]=p[i];
		--d[p[i]];
		if(!d[p[i]])q.push(p[i]);
	}
	b[m-1][0]=q.top();q.pop();
	b[m-1][1]=q.top();q.pop();
	for(int i=1;i<=m-1;++i)if(b[i][0]>b[i][1])swap(b[i][0],b[i][1]);
	for(int i=1;i<m;++i)if(!mp[b[i][0]][b[i][1]])return ;
	for(int i=1;i<=m-1;++i)--mp[b[i][0]][b[i][1]];
	memset(head,0,sizeof(head));num=1;
	for(int i=1;i<=m;++i)ADD(S,i,cnt[i]-1);
	tot=m;
	for(int i=1;i<=m;++i)
		for(int j=i;j<=m;++j)id[i][j]=++tot,ADD(id[i][j],T,mp[i][j]);
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<i;++j)ADD(i,id[j][i],inf);
		for(int j=i;j<=m;++j)ADD(i,id[i][j],inf);
	}
	for(int i=1;i<=m-1;++i)++mp[b[i][0]][b[i][1]];
	sum=0;
	while(bfs())while(dfs(S,inf));
	if(sum+m!=n)return;
//	for(int i=1;i<m;++i)printf("%d %d\n",b[i][0],b[i][1]);printf("\n");
	pos[1]=1;key[1]=1;
	for(int i=2;i<=m;++i)pos[i]=pos[i-1]*10,key[i]=pos[i];
	for(int i=1;i<=m-1;++i)printf("%d %d\n",pos[b[i][0]],pos[b[i][1]]);
	for(int i=1;i<=m;++i)++pos[i];
//	for(int i=1;i<=m;++i)
//		for(int j=head[i];j;j=bi[j].nxt)
//			printf("%d %d %d\n",i,bi[j].to,inf-bi[j].f);
	for(int i=1;i<=m;++i)
		for(int j=head[i],l=m;l;j=bi[j].nxt,--l)
			while(bi[j^1].f)printf("%d %d\n",pos[i],key[l]),++pos[i],--bi[j^1].f;
	exit(0);
}
void dfs(int w)
{
	if(w==m-1)return work();
	for(int i=1;i<=m;++i)p[w]=i,dfs(w+1);
}
char c[10];
int main()
{
	scanf("%d",&n);
	if(n<=9)
	{
		for(int i=2;i<=n;++i)printf("%d %d\n",1,i);
		return 0;
	}
	int s=n;
	while(s)++m,s/=10;
	cnt[0]=1;
	for(int i=1;i<m;++i)cnt[i]=cnt[i-1]*10;
	cnt[m]=n+1;
	for(int i=m;i;--i)cnt[i]-=cnt[i-1];
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%s",c+1);
		x=strlen(c+1);
		scanf("%s",c+1);
		y=strlen(c+1);
		if(x>y)swap(x,y);
		++mp[x][y];
	}
	dfs(1);
	printf("-1");
	return 0;
}