#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 100000000
#define fi first
#define se second
#define N 405
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
	int from,to,cap,flow,pre;
}e[N*8];
int h[N],d[N],vis[N],cou,s,t,cur[N];
void Addedge(int from,int to,int cap)
{
	cou++;
	e[cou]=(Edge){from,to,cap,0,h[from]};
	h[from]=cou;
	cou++;
	e[cou]=(Edge){to,from,0,0,h[to]};
	h[to]=cou;
	//if(cou>1400) printf("%d",1/0);
}

bool BFS()
{
	queue<int> q;
	int i,x,v;
	memset(vis,0,sizeof(vis));
	d[s]=0,vis[s]=1;
	//memset(d,0,sizeof(d));
	q.push(s);
	while(!q.empty())
	{
		x=q.front(),q.pop();
		//vis[x]=1;
		for(i=h[x];i;i=e[i].pre)
		{
			v=e[i].to;
			if(e[i].cap>e[i].flow&&!vis[v])
			{
				d[v]=d[x]+1;
				q.push(v);
				vis[v]=1;
				if(v==t) return 1;
			}
		}
	}
	return 0;
}

int DFS(int x,int a)
{
	if(x==t||a==0)
		return a;
	int v,flow=0,f;
	int &i=cur[x];
	for(;i;i=e[i].pre)
	{
		v=e[i].to;
		if(d[v]==d[x]+1&&(f=DFS(v,min(a,e[i].cap-e[i].flow))))
		{
			a-=f;
			flow+=f;
			e[i].flow+=f;
			e[((i-1)^1)+1].flow-=f;
			if(a==0) break;
		}
	}
	return flow;
}

int Maxflow()
{
	int flow=0,i;
	while(BFS())
	{
		//debug(134);
		for(i=s;i<=t;i++)
			cur[i]=h[i];
		flow+=DFS(s,INF);
		//debug(flow);
	}
	return flow;
}


int a[N],b[N],go[N][N];
int main()
{
	int n,m,i,u,v,s1=0,s2=0,j;
	cin>>n>>m;
	s=0,t=n+n+1;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
	{
		Addedge(i+n,t,b[i]),s1+=a[i];
		Addedge(s,i,a[i]),s2+=b[i];
		Addedge(i,i+n,INF);
	}
	while(m--)
	{
		scanf("%d%d",&u,&v);
		Addedge(u,v+n,INF);
		Addedge(v,u+n,INF);
	}
	if(s1!=s2||Maxflow()!=s1)
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		printf("YES\n");
		for(i=1;i<=cou;i++)
		{
			u=e[i].from,v=e[i].to;
			//debug(i);
			//debug(u);
			//debug(v);
			//debug(e[i].flow);
			if(u+n==v)
				go[u][u]=e[i].flow;
			else if(u<v&&u!=s&&v!=t)
			{
				//debug(u
				go[u][v-n]=e[i].flow;
				//debug(go[u][v-n]);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%d ",go[i][j]);
			printf("\n");
			//cout<<endl;
		}
	}
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")