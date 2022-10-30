#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[33;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
	cout<<x;
	if(suc==1) cout<<'\n';
	else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
	for(int i=0;i<v.size();i++)
	print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=5e5+7;
vi G[2][maxn];
struct D{
	int id,tp;ll d;
	bool operator<(const D&a)const{
		return d>a.d;
	}
};
int vis[maxn][2];
ll dis[maxn][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int sx,sy,fx,fy;
	cin>>sx>>sy>>fx>>fy;
	ll ans=abs(sx-fx)+abs(sy-fy);
	vi allx,ally;
	allx.push_back(sx);ally.push_back(sy);
	//ally.push_back(sy);ally.push_back(fy);
	vc<pi> pt(m);
	for(int i=0,x,y;i<m;i++)
	{
		cin>>x>>y;
		pt[i]=pi(x,y);
		allx.push_back(x);
		ally.push_back(y);
	}
	mkuni(allx);mkuni(ally);
	sx=lower_bound(allx.begin(),allx.end(),sx)-allx.begin();
	sy=lower_bound(ally.begin(),ally.end(),sy)-ally.begin();
	priority_queue<D> q;
	q.push({sx,0,0});q.push({sy,1,0});
	memset(dis,0x3f,sizeof(dis));
	dis[sx][0]=0;dis[sy][1]=0;
	auto upd=[&](int id,int tp,ll d){
		if(dis[id][tp]>d)
		{
			dis[id][tp]=d;
			q.push({id,tp,d});
		}
	};
	for(int i=0;i<m;i++)
	{
		pt[i].first=lower_bound(allx.begin(),allx.end(),pt[i].first)-allx.begin();
		pt[i].second=lower_bound(ally.begin(),ally.end(),pt[i].second)-ally.begin();
		G[0][pt[i].first].push_back(pt[i].second);
		G[1][pt[i].second].push_back(pt[i].first);
	}
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(vis[u.id][u.tp]) continue;
		vis[u.id][u.tp]=1;
		dbg(u.id,u.tp,dis[u.id][u.tp]);
		if(u.id)
		{
			ll d;
			if(u.tp) d=dis[u.id][u.tp]+ally[u.id]-ally[u.id-1];
			else
				d=dis[u.id][u.tp]+allx[u.id]-allx[u.id-1];
			upd(u.id-1,u.tp,d);
		}
		if(u.tp)
		{
			if(u.id+1<ally.size())
				upd(u.id+1,u.tp,ally[u.id+1]-ally[u.id]+dis[u.id][u.tp]);
		}
		else{
			if(u.id+1<allx.size())
				upd(u.id+1,u.tp,allx[u.id+1]-allx[u.id]+dis[u.id][u.tp]);
		}
		for(auto v:G[u.tp][u.id])
		{
			ll d=dis[u.id][u.tp];
			upd(v,u.tp^1,d);
		}
	}
	for(int i=0;i<m;i++)
	{
		int x=allx[pt[i].first],y=ally[pt[i].second];
		ll d=min(dis[pt[i].first][0],dis[pt[i].second][1]);
		ans=min(ans,d+abs(x-fx)+abs(y-fy));
	}
	print(ans);
}