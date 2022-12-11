#include <bits/stdc++.h>
const int MaxN = 100123;
const int Mod = 1e9+7;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> rnd(3,Mod-1); 

int pow1[MaxN],pow2[MaxN];

#define Mid ((L+R)>>1)
int ls[MaxN<<6],rs[MaxN<<6],ones[MaxN<<6],hash1[MaxN<<6],hash2[MaxN<<6],cnt,T0;
void Build(int&o,int L=0,int R=MaxN)
{
	o = ++cnt;
	ones[o] = hash1[o] = hash2[o] = 0;
	if(L==R)return;
	Build(ls[o],L,Mid);
	Build(rs[o],Mid+1,R);
}

int Calc(int o,int l,int L=0,int R=MaxN)
{
	if(L==R)return ones[o];
	if(l<=Mid)
	{
		int res = Calc(ls[o],l,L,Mid);
		return (res == Mid-l+1 ? res + ones[rs[o]] : res);
	}
	else return Calc(rs[o],l,Mid+1,R);
}

void Modify0(int&o,int k,int o0,int l,int r,int L=0,int R=MaxN)
{
	if(l<=L&&R<=r)return o = o0,void();
	o = ++cnt;
	if(l<=Mid)Modify0(ls[o],ls[k],ls[o0],l,r,L,Mid);
	else ls[o] = ls[k];
	if(Mid<r)Modify0(rs[o],rs[k],rs[o0],l,r,Mid+1,R);
	else rs[o] = rs[k];
	
	ones[o] = (ones[ls[o]] == Mid-L+1 ? ones[ls[o]] + ones[rs[o]] : ones[ls[o]]);
	hash1[o] = (hash1[ls[o]] + 1LL * pow1[Mid-L+1] * hash1[rs[o]]) % Mod;
	hash2[o] = (hash2[rs[o]] + 1LL * pow2[Mid-L+1] * hash2[rs[o]]) % Mod;
}

void Modify1(int&o,int k,int l,int L=0,int R=MaxN)
{
	o = ++cnt;
	if(L==R)
	{
		ones[o] = hash1[o] = hash2[o] = 1;
		return;
	}
	
	if(l<=Mid)Modify1(ls[o],ls[k],l,L,Mid),rs[o] = rs[k];
	else ls[o] = ls[k],Modify1(rs[o],rs[k],l,Mid+1,R);
	
	ones[o] = (ones[ls[o]] == Mid-L+1 ? ones[ls[o]] + ones[rs[o]] : ones[ls[o]]);
	hash1[o] = (hash1[ls[o]] + 1LL * pow1[Mid-L+1] * hash1[rs[o]]) % Mod;
	hash2[o] = (hash2[rs[o]] + 1LL * pow2[Mid-L+1] * hash2[rs[o]]) % Mod;
}

int Less(int o1,int o2,int L=0,int R=MaxN)
{
	if(L==R)return (ones[o1] < ones[o2] ? 1 : 0);
	if(hash1[rs[o1]] == hash1[rs[o2]] && hash2[rs[o1]] == hash2[rs[o2]])
	return Less(ls[o1],ls[o2],L,Mid);
	else return Less(rs[o1],rs[o2],Mid+1,R);
}
#undef Mid

int Inc(int o,int x)
{
	int c = Calc(o,x), r = 0;
	if(!c)Modify1(r,o,x);
	else Modify0(r,o,T0,x,x+c-1),Modify1(r,r,x+c);
	return r;
}

struct Int
{
	int o;
	Int(int _o):o(_o){}
	operator int()const{return o;}
	friend bool operator < (const Int&a,const Int&b)
	{
		if(a.o == -1)return false;
		if(b.o == -1)return true;
		return Less(a.o,b.o);
	}
};

int n,m,s,t,dis[MaxN],pre[MaxN];
std::vector<std::pair<int,int>> G[MaxN];

void Dijkstra()
{
	static int vis[MaxN];
	memset(dis,-1,sizeof(dis));
	dis[s] = T0; 
	
	std::priority_queue<std::pair<Int,int>,
		std::vector<std::pair<Int,int>>,
		std::greater<std::pair<Int,int>>> q;
	
	q.emplace(dis[s],s);
	while(!q.empty())
	{
		int d = q.top().first, u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		
		for(auto p:G[u])
		{
			int v,w;std::tie(v,w) = p;
			int r = Inc(d,w);
			if(Int(r) < Int(dis[v]))
			{
				dis[v] = r;
				pre[v] = u;
				q.emplace(dis[v],v);
			}
		}
	}
}

int main()
{
	for(int i=pow1[0]=1;i<MaxN;++i)
	pow1[i] = pow1[i-1] * 2 % Mod;
	for(int i=pow2[0]=1,a=rnd(rng);i<MaxN;++i)
	pow2[i] = pow2[i-1] * a % Mod;
	
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	
	Build(T0);
	scanf("%d%d",&s,&t);
	Dijkstra();
	
	if(dis[t] == -1)puts("-1");
	else
	{
		std::vector<int> path;
		for(int i=t;i!=s;i=pre[i])path.push_back(i);
		path.push_back(s);
		
		std::reverse(path.begin(),path.end());
		
		printf("%d\n",hash1[dis[t]]);
		printf("%d\n",static_cast<int>(path.size()));
		for(int x:path)
		printf("%d ",x);
	}
	return 0;
}