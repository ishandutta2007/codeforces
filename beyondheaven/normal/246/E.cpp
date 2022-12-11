#include<bits/stdc++.h>
#define MaxN 200123

int n,m;
std::vector<int>G[MaxN];
int c[MaxN],dfn[MaxN],rev[MaxN],dep[MaxN],size[MaxN],dfs_clock;

auto cmp=[&](int a,int b)->bool{return dfn[a]<dfn[b];};

int ans[MaxN];
struct Solver
{
	std::vector<int>v;
	std::vector<std::tuple<int,int,int>>q;
	
	void insert(int x){v.emplace_back(x);}
	void add_query(int u,int v,int id)
	{q.emplace_back(std::make_tuple(u,v,id));}
	
	void work()
	{
		std::sort(v.begin(),v.end(),cmp);
		
		std::vector<int>pre;
		pre.resize(v.size()+5);
		
		std::map<int,int>mp;
		
		for(int i=0;i<static_cast<int>(v.size());++i)
		if(mp.count(c[v[i]]))
		{
			pre[i]=mp[c[v[i]]];
			mp[c[v[i]]]=i;
		}
		else
		{
			mp.insert(std::make_pair(c[v[i]],i));
			pre[i]=-1;
		}
		
		std::vector<std::vector<std::tuple<int,int,int>>>qlist;
		qlist.resize(v.size()+5);
		
		for(auto&p:q)
		{
			int a=std::get<0>(p),b=std::get<1>(p),id=std::get<2>(p);
			a=std::lower_bound(v.begin(),v.end(),a,cmp)-v.begin();
			b=std::upper_bound(v.begin(),v.end(),b,cmp)-1-v.begin();
			
			#ifdef Dubug
			printf("query %d:\n",id);
			for(int i=a;i<=b;++i)
			printf("%d ",i);
			puts("");
			#endif 
			
			if(a>b)continue;
			if(a)
			qlist[a-1].emplace_back(std::make_tuple(a-1,-1,id));
			qlist[b].emplace_back(std::make_tuple(a-1,1,id));
		}
		
		std::vector<int>BIT(v.size()+10,0);
		
		auto Add=[&](int x)->void
		{
			x+=2;
			for(;x<static_cast<int>(v.size())+10;x+=(x&-x))++BIT[x];
		};
		auto Sum=[&](int x)->int
		{
			x+=2;
			int res=0;
			for(;x;x-=(x&-x))res+=BIT[x];
			return res;
		};
		
		for(int i=0;i<static_cast<int>(v.size());++i)
		{
			Add(pre[i]);
			for(auto&p:qlist[i])
			{
				int u=std::get<0>(p),t=std::get<1>(p),id=std::get<2>(p);
				ans[id]+=t*Sum(u);
			}
		}
	}
	
	Solver():v(),q(){}
}solver[MaxN];

inline void Dfs(int u,int f)
{
	size[u]=1;
	dep[u]=dep[f]+1;
	dfn[u]=++dfs_clock;rev[dfs_clock]=u;
	solver[dep[u]].insert(u);
	
	for(int v:G[u])
	{
		Dfs(v,u);
		size[u]+=size[v];
	}
	assert(dfs_clock==dfn[u]+size[u]-1);
}

inline void Init()
{
	std::cin>>n;
	std::map<std::string,int>mp;
	for(int i=1,f;i<=n;++i)
	{
		std::string s;
		std::cin>>s>>f;
		G[f].emplace_back(i);
		if(!mp.count(s))
		mp.insert(std::make_pair(s,static_cast<int>(mp.size())));
		c[i]=mp[s];
	}
	
	for(int u:G[0])Dfs(u,0); 
	
	std::cin>>m;
	for(int i=1,v,k;i<=m;++i)
	{
		std::cin>>v>>k;
		if(dep[v]+k<=n)
		solver[dep[v]+k].add_query(v,rev[dfn[v]+size[v]-1],i);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	Init();
	for(int i=1;i<=n;++i)
	solver[i].work();
	for(int i=1;i<=m;++i)
	std::cout<<ans[i]<<std::endl;
	return 0;
}