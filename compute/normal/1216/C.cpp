#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
ll quick(ll a,ll b,ll mod)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
vector<int> all;
inline int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
inline bool inside(int x,int y,int x1,int y1,int x2,int y2)
{
	return x>=x1&&x<=x2&&y>=y1&&y<=y2;
}
int main()
{
	int x1,y1,x2,y2;
	int x3,y3,x4,y4;
	int x5,y5,x6,y6;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	cin>>x5>>y5>>x6>>y6;
	x1*=2;x2*=2,x3*=2,x4*=2,x5*=2,x6*=2;
	y1*=2;y2*=2,y3*=2,y4*=2,y5*=2,y6*=2;
	for(int i=-4;i<=4;i++)
	{
		all.push_back(x1+i);
		all.push_back(x2+i);
		all.push_back(x3+i);
		all.push_back(x4+i);
		all.push_back(x5+i);
		all.push_back(x6+i);
		all.push_back(y1+i);
		all.push_back(y2+i);
		all.push_back(y3+i);
		all.push_back(y4+i);
		all.push_back(y5+i);
		all.push_back(y6+i);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	x1=getid(x1);
	x2=getid(x2);
	x3=getid(x3);
	x4=getid(x4);
	x5=getid(x5);
	x6=getid(x6);
	y1=getid(y1);
	y2=getid(y2);
	y3=getid(y3);
	y4=getid(y4);
	y5=getid(y5);
	y6=getid(y6);
	bool ans=0;
	for(int x=x1;x<=x2;x++)
	{
		for(int y=y1;y<=y2;y++)
		{
	//		dbg(x,y);
			if(!inside(x,y,x3,y3,x4,y4)&&!inside(x,y,x5,y5,x6,y6))
				ans=1;
		}
	}
	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}