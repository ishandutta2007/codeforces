#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int INF=2e9+1;
struct node{
	int price,id;
	bool operator<(const node& a)const{
		return price<a.price;
	}
};
int cnt[1<<9];
typedef pair<int,int> PII;
vector<node> pizza[1<<9];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int f;
		scanf("%d",&f);
		int bit=0;
		while(f--)
		{
			int b;
			scanf("%d",&b);
			b--;
			bit|=(1<<b);
		}
		cnt[bit]++;
	}
	for(int i=0;i<m;i++)
	{
		int price;
		scanf("%d",&price);
		int f;
		scanf("%d",&f);
		int bit=0;
		while(f--)
		{
			int b;
			scanf("%d",&b);
			b--;
			bit|=(1<<b);
		}
		pizza[bit].push_back(node {price,i+1});
	}
	int ans=0,ansp=INF;
	PII op;
	for(int i=0;i<(1<<9);i++) sort(pizza[i].begin(),pizza[i].end());
	for(int i=0;i<(1<<9);i++)
	{
		for(int j=i;j<(1<<9);j++)
		{
			if(!pizza[i].size()||!pizza[j].size()) continue;
			if(i==j&&pizza[i].size()==1) continue;
			node a,b;
			if(i==j) a=pizza[i][0],b=pizza[i][1];
			else a=pizza[i][0],b=pizza[j][0];
			int S=i|j;
			int cur=0;
			for(int T=S;T;T=(T-1)&S)
				cur+=cnt[T];
			if(cur>ans)
			{
				ans=cur;
				ansp=a.price+b.price;
				op=make_pair(a.id,b.id);
			}
			else if(cur==ans)
			{
				int pp=a.price+b.price;
				if(pp<ansp)
				{
					ansp=pp;
					op=make_pair(a.id,b.id);
				}
			}
		}
	}
	printf("%d %d\n",op.first,op.second);
}