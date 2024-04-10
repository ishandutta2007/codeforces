#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
typedef pair<int,int> PII;
const int maxn=2e5+7;
int arr[maxn],ans[maxn];
int cnt[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	set<int> st;
	for(int i=0,tmp;i<n;i++)
	{
		cin>>tmp;
		cnt[tmp]++;
	}
	for(int i=0;i<n;i++)
		if(cnt[i])
			st.insert(i);
	for(int i=0;i<n;i++)
	{
		int tar=n-arr[i];
		auto pos=st.lower_bound(tar);
		if(pos==st.end())
			pos=st.begin();
		int cur=*pos;
		ans[i]=(cur+arr[i])%n;
		cnt[cur]--;
		if(!cnt[cur]) st.erase(cur);
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;

}