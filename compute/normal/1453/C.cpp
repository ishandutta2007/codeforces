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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vi ans(10);
		vc<string> maze(n);
		for(int i=0;i<n;i++) cin>>maze[i];
		vc<vi> mir(n,vi(10,n)),mxr(n,vi(10,-1));
		vc<vi> mic(n,vi(10,n)),mxc(n,vi(10,-1));
		vi mirs(10,n),mxrs(10,-1),mics(10,n),mxcs(10,-1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int cc=maze[i][j]-'0';
				mir[i][cc]=min(mir[i][cc],j);
				mxr[i][cc]=max(mxr[i][cc],j);
				mic[j][cc]=min(mic[j][cc],i);
				mxc[j][cc]=max(mxc[j][cc],i);
				mirs[cc]=min(mirs[cc],j);
				mxrs[cc]=max(mxrs[cc],j);
				mics[cc]=min(mics[cc],i);
				mxcs[cc]=max(mxcs[cc],i);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				
				int cc=maze[i][j]-'0';
				// row
				int d=max(n-1-i,i);
				int rd=max(j-mir[i][cc],mxr[i][cc]-j);
				ans[cc]=max(ans[cc],d*rd);
				//col
				d=max(n-1-j,j);
				rd=max(i-mic[j][cc],mxc[j][cc]-i);
				ans[cc]=max(ans[cc],d*rd);
				/*
				for(int cc=0;cc<10;cc++)
				{
					if(mir[i][cc]<=j)
					{
						if(mxc[j][cc]!=-1)
						{
							ans[cc]=max(ans[cc],(j-mir[i][cc])*max(mxc[j][cc],n-1-mxc[j][cc]));
							ans[cc]=max(ans[cc],(j-mir[i][cc])*max(n-1-mic[j][cc],mic[j][cc]));
							ans[cc]=max(ans[cc],max(mir[i][cc],n-1-mir[i][cc])*(mxc[j][cc]-i));
							ans[cc]=max(ans[cc],max(mir[i][cc],n-1-mir[i][cc])*(i-mic[j][cc]));
						}
					}
				}
				*/
				ans[cc]=max(ans[cc],max(i,n-1-i)*max(j-mirs[cc],mxrs[cc]-j));
				ans[cc]=max(ans[cc],max(j,n-1-j)*max(i-mics[cc],mxcs[cc]-i));
			}
		}
		print(ans);
	}
}