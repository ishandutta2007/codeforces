#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<queue>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
const int INF=0x7f7f7f7f;

int n,m; bool nok[55][55];
bool ans[55][55];
struct Edge{
	int to,nxt,val,cst;
}edge[20010];
int cnt=1,last[3010],S,T;
inline void addedge(int x,int y,int v,int c)
{
	//printf("addedge %d %d %d %d\n",x,y,v,c);
	edge[++cnt]=(Edge){y,last[x],v,c},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],0,-c},last[y]=cnt;
}
int gethash(int x,int y)
{
	return (x-1)*n+y;
}
int dis[3010],h[3010];
int pedge[3010];
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> > que;
bool dijkstra()  //init
{
	memset(dis,0x7f,sizeof dis);
	dis[S]=0; que.push((P){dis[S],S});
	while (!que.empty())
	{
		P cur=que.top(); que.pop();
		if (dis[cur.second]^cur.first) continue;
		int u=cur.second,v;
		for (int i=last[u];i;i=edge[i].nxt)
			if (v=edge[i].to,edge[i].val&&dis[u]+h[u]-h[v]+edge[i].cst<dis[v])
			{
				dis[v]=dis[u]+h[u]-h[v]+edge[i].cst;
				pedge[v]=i;
				que.push((P){dis[v],v});
			}
	}
	return dis[T]!=INF;
}
void mcmf()
{
	while (dijkstra())
	{
		int flw=1e9;
		for (int i=T;i^S;i=edge[pedge[i]^1].to) flw=min(flw,edge[pedge[i]].val);
		for (int i=T;i^S;i=edge[pedge[i]^1].to) edge[pedge[i]].val-=flw,edge[pedge[i]^1].val+=flw;
		for (int i=1;i<=T;i++) h[i]+=dis[i];
	}
}
int main()
{
	n=read(),m=read(); S=n+n*n+1,T=S+1;
	for (int i=1,x,y;i<=m;i++) x=read(),y=read(),nok[y][x]=1;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int x=gethash(i,j)+n;
			addedge(S,x,1,0);
			if (!nok[i][j]) addedge(x,j,1,0);
			if (!nok[j][i]) addedge(x,i,1,0);
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<n;j++)
			addedge(i,T,1,(j<<1)-1);
	mcmf();
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int x=gethash(i,j)+n;
			for (int u=last[x],v;u;u=edge[u].nxt)
				if (v=edge[u].to,v<=n&&!edge[u].val)
				{
					if (v==i) ans[j][i]=1;
					else ans[i][j]=1;
					break;
				}
		}
	for (int i=1;i<=n;i++,putchar('\n'))
		for (int j=1;j<=n;j++)
			putchar(ans[i][j]?'1':'0');
	return 0;
}