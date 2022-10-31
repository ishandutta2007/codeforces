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
const int maxn=1505;
struct Seg{
	int l,r;
	bool operator<(const Seg& a)const{
		if(a.l==l) return r<a.r;
		return l<a.l;
	}
};
int arr[maxn];
map<int,int> num;
vector<Seg> ext[maxn*maxn];
vector<Seg> ans;
int main()
{
	int n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		int cur=0;
		for(int j=i;j<n;j++)
		{
			cur+=arr[j];
			if(num.count(cur))
			{
				ext[num[cur]].push_back(Seg{i,j});
			}
			else 
			{
				num[cur]=cnt++;
				ext[num[cur]].push_back(Seg{i,j});
			}
		}
	}
	int tar=0;
	int sz=0;
	for(auto p:num)
	{
		int cur=p.second;
		sort(ext[cur].begin(),ext[cur].end());
		int l=-1,r=-1;
		int tot=0;
		vector<Seg> temp;
		for(int i=0;i<ext[cur].size();i++)
		{
			Seg u=ext[cur][i];
			if(u.l>r)
			{
				tot++;
				temp.push_back(u);
				l=u.l;r=u.r;
			}
			else
			{
				if(u.r<r){
					r=u.r;
					temp.pop_back();
					temp.push_back(u);
				}
			}
		}
		if(tot>sz)
		{
			ans=temp;
			tar=p.first;
			sz=tot;
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].l+1<<" "<<ans[i].r+1<<endl;
	}
}