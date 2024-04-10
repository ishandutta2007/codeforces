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
struct Q{
	vc<pi> op;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		vc<string> maze(n);
		for(int i=0;i<n;i++) cin>>maze[i];
		vc<vi> a(n,vi(m));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) a[i][j]=maze[i][j]-'0';
		}
		vc<Q> ans;
		auto add=[&](int x1,int y1,int x2,int y2,int x3,int y3){
			vc<pi> op(3);
			op[0]=make_pair(x1,y1);
			op[1]=make_pair(x2,y2);
			op[2]=make_pair(x3,y3);
			ans.push_back(Q{op});
		};
		auto go=[&](int x1,int y1,int x2,int y2,int x3,int y3){
			a[x1][y1]^=1;
			a[x2][y2]^=1;
			a[x3][y3]^=1;
		};
		for(int i=n-1;i>=2;i--)
		{
			for(int j=0;j<m-1;j++)
			{
				if(a[i][j])
				{
					add(i,j,i-1,j+1,i-1,j);
					go(i,j,i-1,j+1,i-1,j);
				}
			}
			if(a[i][m-1])
			{
				add(i,m-1,i-1,m-1,i-1,m-2);
				go(i,m-1,i-1,m-1,i-1,m-2);
			}
		}
		for(int j=m-1;j>=2;j--)
		{
			for(int i=0;i<2;i++)
			{
				if(a[i][j])
				{
					add(i,j,i^1,j-1,i,j-1);
					go(i,j,i^1,j-1,i,j-1);
				}
			}
		}
		int cc=0;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) cc+=a[i][j];
		if(cc&1) for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]^=1;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
				if(a[i][j])
					add(i^1,j^1,i^1,j,i,j^1);
		}
		print(ans.size());
		for(auto u:ans)
		{
			for(int j=0;j<3;j++) cout<<u.op[j].first+1<<" "<<u.op[j].second+1<<" \n"[j==2];
		}

	}
}