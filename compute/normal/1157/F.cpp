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
const int maxn=2e5+7;

int cnt[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		cnt[tmp]++;
	}
	vector<int> ans;
	vector<int> cur;
	for(int i=1;i<maxn;i++)
	{
		if(cnt[i]>=2)
		{
			for(int j=0;j<cnt[i];j++)
				cur.push_back(i);
		}
		else if(cnt[i]==1){
			cur.push_back(i);
			if(cur.size()>ans.size())
				ans=cur;
			cur.clear();
			cur.push_back(i);
		}
		else{
			if(cur.size()>ans.size()) ans=cur;
			cur.clear();
		}
	}
	printf("%d\n",(int)ans.size());
	deque<int> op;
	for(int i=0;i<ans.size();i++)
	{
		if(i&1) op.push_back(ans[i]);
		else op.push_front(ans[i]);
	}
	while(!op.empty())
	{
		printf("%d ",op.front());
		op.pop_front();
	}
	puts("");
}