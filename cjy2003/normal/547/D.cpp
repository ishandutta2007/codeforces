#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct bian
{
	int nxt,to;
}bi[1000010];
int n,p[200020][2],d[400040],head[400040],num=1,cnth[200020],cntl[200020];
map<pair<int,int>,bool>mp;
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
bool vis[400040],used[500050],color[500050];
int c=0;
void dfs(int v,int fb)
{
	for(int &i=head[v],u;i;i=bi[i].nxt)
		if(!used[i/2])
		{
			used[i/2]=1;
			u=bi[i].to;
			dfs(u,i/2);
		}
//	printf("%d ",v);
	color[fb]=c^=1;
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&x,&y);
		p[i][0]=x,p[i][1]=y;
		++cnth[x],++cntl[y];
		add(x,y+200000),add(y+200000,x);
	}
	for(int i=1;i<=200000;++i)if(cnth[i]&1)add(i,0),add(0,i);
	for(int i=1;i<=200000;++i)if(cntl[i]&1)add(0,i+200000),add(i+200000,0);
	dfs(0,0);
	for(int i=1;i*2<=num;++i)if(!used[i])dfs(bi[i*2].to,0);
	for(int i=1;i<=n;++i)putchar(color[i]?'r':'b');
	return 0;
}