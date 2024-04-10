#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
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
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
vi G[maxn];
int d[maxn];
void bfs(int st)
{
	memset(d,-1,sizeof(d));
	d[st]=0;
	queue<int> q;
	q.push(st);
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		for(auto v:G[u])
		{
			if(d[v]==-1)
			{
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,a,b,da,db;
		cin>>n>>a>>b>>da>>db;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(db<=2*da) cout<<"Alice\n";
		else{
			bfs(a);
			int dis=d[b];
			if(dis<=da) cout<<"Alice\n";
			else{
				for(int i=1;i<=n;i++)
				{
					if(d[i]>dis)
					{
						dis=d[i];
						b=i;
					}
				}
				bfs(b);
				for(int i=1;i<=n;i++) dis=max(dis,d[i]);
				if(da*2>=dis) cout<<"Alice\n";
				else cout<<"Bob\n";
			}
		}
	}
}