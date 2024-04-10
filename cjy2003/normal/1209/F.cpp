#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
const int mod=1000000007;
vector<int>E[600010][10];
int n,m,tot,dis[100010],ans[600010];
bool vis[600010];
deque<vector<int> >q;
deque<int>w;
struct bian
{
	int nxt,to,w;
}bi[200020];
int head[100010],num;
void add(int from,int to,int w)
{
	bi[++num]=bian{head[from],to,w};
	head[from]=num;
}
void ADD(int from,int to,int w)
{
	static int st[20],tp;
	tp=0;
	while(w)st[++tp]=w%10,w/=10;
	int last=from;
	for(int i=tp;i>1;--i)
	{
		E[last][st[i]].push_back(++tot);
		last=tot;
	}
	E[last][st[1]].push_back(to);
}

int main()
{
	scanf("%d %d",&n,&m);
	tot=n;
	int x,y,po=10,cnt=1;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		if(i==po)po*=10,++cnt;
		add(x,y,cnt);
		add(y,x,cnt);
	}
	priority_queue<pair<int,int> >q1;
	memset(dis,0x3f,sizeof(dis));
	q1.push(make_pair(dis[1]=0,1));
	while(!q1.empty())
	{
		x=q1.top().second;q1.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(dis[x]+bi[i].w<dis[y])
			{
				dis[y]=dis[x]+bi[i].w;
				q1.push(make_pair(-dis[y],y));
			}
		}
	}
	memset(vis+1,0,n);
	for(int i=1;i<=n;++i)
		for(int j=head[i];j;j=bi[j].nxt)
			if(dis[bi[j].to]-dis[i]==bi[j].w)
				ADD(i,bi[j].to,(j+1)/2);
	vector<int>now,nxt;
	now.push_back(1);
	w.push_back(0);
	q.push_back(now);
	int nw;
	while(!q.empty())
	{
		nxt=q.front();q.pop_front();
		nw=w.front();w.pop_front();
		now.clear();
		for(auto p:nxt)
			if(!vis[p])vis[p]=1,ans[p]=nw,now.push_back(p);
		for(int i=9;~i;--i)
		{
			nxt.clear();
			for(auto p:now)
				for(auto x:E[p][i])nxt.push_back(x);
			if(nxt.size())q.push_front(nxt),w.push_front((10ll*nw+i)%mod);
		}
	}
	for(int i=2;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}