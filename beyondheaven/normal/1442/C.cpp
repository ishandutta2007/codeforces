#include<bits/stdc++.h>
#define MaxN 400123
typedef long long LL;
const LL Mod=998244353;

inline LL pow_mod(LL a,LL b)
{
	a%=Mod;b%=(Mod-1);
	if(!b)return a?1:0;
	LL res=1;
	for(;b;b>>=1,a=a*a%Mod)
	if(b&1)res=res*a%Mod;
	return res;
}

struct Edge
{
	int v,w;
	Edge(int _v=0,int _w=0):
		v(_v),w(_w){}
};

int n,m;
int U[MaxN],V[MaxN];

int min_reverse,min_reverse_move;

inline void Solve1()
{
	static std::vector<Edge>G[MaxN];
	
	typedef std::pair<int,int> pii;
	
	for(int i=1;i<=m;++i)
	{
		G[U[i]].push_back(Edge(V[i],0));
		G[V[i]+n].push_back(Edge(U[i]+n,0));
	}
	
	for(int i=1;i<=n;++i)
	{
		G[i].push_back(Edge(i+n,1));
		G[i+n].push_back(Edge(i,1));
	}
	
	std::priority_queue<std::pair<pii,int>,
		std::vector<std::pair<pii,int> >,
		std::greater<std::pair<pii,int> > >q;
	
	static pii dis[MaxN];
	static bool done[MaxN];
	
	for(int i=1;i<=2*n;++i)
	dis[i]=std::make_pair(0x3f3f3f3f,0x3f3f3f3f);
	dis[1]=std::make_pair(0,0);
	q.push(std::make_pair(dis[1],1));
	
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(done[u])continue;
		done[u]=true;
		for(std::size_t i=0;i<G[u].size();++i)
		{
			int v=G[u][i].v,w=G[u][i].w;
			if(w==0)
			{
				if(dis[v]>std::make_pair(dis[u].first,dis[u].second+1))
				{
					dis[v]=std::make_pair(dis[u].first,dis[u].second+1);
					q.push(std::make_pair(dis[v],v));
				}
			}
			else
			{
				if(dis[v]>std::make_pair(dis[u].first+1,dis[u].second))
				{
					dis[v]=std::make_pair(dis[u].first+1,dis[u].second);
					q.push(std::make_pair(dis[v],v));
				}
			}
		}
	}
	
	pii ans=std::min(dis[n],dis[n+n]);
	min_reverse=ans.first;
	min_reverse_move=ans.second;
}

std::vector<Edge>G[MaxN*20]; 
int dis[MaxN*20];
bool done[MaxN*20];

inline void Solve2()
{
	int lim=0;
	while((1<<(lim+1))<=n)++lim;
	
	if(min_reverse>=lim)
	{
		printf("%lld\n",(pow_mod(2,min_reverse)-1+min_reverse_move)%Mod);
		return; 
	}
	
	for(int _=0;_<=lim;++_)
	for(int i=1;i<=m;++i)
	if(_&1)G[V[i]+_*n].push_back(Edge(U[i]+_*n,1));
	else G[U[i]+_*n].push_back(Edge(V[i]+_*n,1));
	
	for(int _=0;_<lim;++_)
	for(int i=1;i<=n;++i)
	G[i+_*n].push_back(Edge(i+(_+1)*n,0));
	
	std::deque<int>q;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;q.push_front(1);
	while(!q.empty())
	{
		int u=q.front();q.pop_front();
		for(std::size_t i=0;i<G[u].size();++i)
		{
			Edge&e=G[u][i];
			if(dis[e.v]>dis[u]+e.w)
			{
				dis[e.v]=dis[u]+e.w;
				if(e.w)q.push_back(e.v);
				else q.push_front(e.v);
			}
		}
	}
	
	int ans=0x3f3f3f3f;
	for(int _=min_reverse;_<=lim;++_)
	ans=std::min(1LL*ans,pow_mod(2,_)+dis[n+_*n]-1);
	
	printf("%lld\n",ans%Mod);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	scanf("%d%d",U+i,V+i);
	Solve1();
	Solve2();
	return 0;
}