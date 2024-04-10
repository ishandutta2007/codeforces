#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
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
const int maxn=1e5+7;
vi G[maxn];
int deg[maxn];
struct D{
	int d,id;
	bool operator<(const D&a) const{
		if(d==a.d) return id<a.id;
		return d<a.d;
	}
};
const int N=2e5+7;
template<typename T1,typename T2>
struct Table
{
	T1 key[N];
	T2 val[N];
	int head[19260817],next[N],tot;
	int sta[N],top;
	void init(bool flag)
	{
		if(flag)
		{
			memset(head,-1,sizeof(head));
			tot=top=0;
			return ;
		}
		while(top>0)
		{
			head[sta[--top]]=-1;
		}
		tot=0;
	}
	int gethas(T1 v)
	{
		return (v.first*1000+v.second)%19260817;
	}
	void modify(T1 x,T2 y)
	{
		int u=gethas(x);
		for(int i=head[u];~i;i=next[i])
		{
			if(key[i]==x)
			{
				val[i]=y;
				return ;
			}
		}
		key[tot]=x;
		val[tot]=y;
		next[tot]=head[u];
		if(head[u]==-1)
		{
			sta[top++]=u;
		}
		head[u]=tot++;
	}
	T2 query(T1 x)
	{
		int u=gethas(x);
		for(int i=head[u];~i;i=next[i])
		{
			if(key[i]==x)
			{
				return val[i];
			}
		}
		return 0;//NULL
	}
};
Table<pi,int> es;
int del[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	es.init(1);
	int T;
	cin>>T;
	while(T--)
	{
		es.init(0);
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<=n;i++)
		{
			G[i].clear();
			deg[i]=0;
			del[i]=0;
		}
		for(int i=0,u,v;i<m;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			es.modify(pi(u,v),1);
			es.modify(pi(v,u),1);
			deg[u]++;deg[v]++;
		}
		set<D> st;
		for(int i=1;i<=n;i++) st.insert(D{deg[i],i});
        bool ok=0;
		while(st.size()&&(*st.begin()).d<k)
		{
			auto cur=st.begin();
			int cc=(*cur).d;
			int u=(*cur).id;
            if(cc==k-1)
            {
                vi tar;
				tar.push_back(u);
				for(auto v:G[u])
				{
					if(!del[v])
						tar.push_back(v);
				}
				bool suc=1;
				for(auto v:G[u])
				{
					if(!del[v])
					{
						for(auto x:tar)
						{
							if(v!=x&&!es.query(pi(x,v)))
							{
								suc=0;
								break;
							}
						}
						if(!suc) break;
					}
				}
				if(suc)
				{
                    print(2);
                    print(tar);
                    ok=1;
                    break;
                }
            }
			st.erase(cur);
			for(auto v:G[u])
			{
				if(!del[v])
				{
					st.erase(D{deg[v],v});
					deg[v]--;
					st.insert(D{deg[v],v});
				}
			}
			del[u]=1;
		}
        if(ok) continue;
		if(!st.size())
			print(-1);
		else{
			cout<<1<<" "<<st.size()<<'\n';
			for(auto u:st) cout<<u.id<<" ";
			cout<<'\n';
		}
	}
}