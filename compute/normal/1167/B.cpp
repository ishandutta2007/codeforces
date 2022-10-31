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
int a[]={4,8,15,16,23,42};
int ask(int i,int j)
{
	int ret;
	cout<<"? "<<i<<" "<<j<<endl;
	cin>>ret;
	return ret;
}
bool check(vector<int> cur,vector<int> res)
{
	vector<int> all;
	all.push_back(cur[0]*cur[1]);
	all.push_back(cur[0]*cur[2]);
	all.push_back(cur[0]*cur[3]);
	all.push_back(cur[0]*cur[4]);
	for(int i=0;i<4;i++)
	{
		if(all[i]!=res[i]) return false;
	}
	return true;
}
int main()
{
	vector<int> pp;
	for(int i=0;i<6;i++) pp.push_back(a[i]);
	vector<int> all;
	int cur=ask(1,2);
	all.push_back(cur);
	cur=ask(1,3);
	all.push_back(cur);
	cur=ask(1,4);
	all.push_back(cur);
	cur=ask(1,5);
	all.push_back(cur);
	vector<int> ans;
	do{
		if(check(pp,all))
		{
			ans=pp;
			break;
		}
	}while(next_permutation(pp.begin(),pp.end()));
	cout<<"! ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}