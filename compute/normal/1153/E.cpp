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
void ask(int x1,int y1,int x2,int y2)
{
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}
void answer(int x1,int y1,int x2,int y2)
{
	cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<int> row,col;
	for(int i=1;i<=n;i++)//row
	{
		ask(i,1,i,n);
		int ret;
		cin>>ret;
		if(ret%2) row.push_back(i);
	}
	for(int i=1;i<=n;i++)//col
	{
		ask(1,i,n,i);
		int ret;
		cin>>ret;
		if(ret%2) col.push_back(i);
	}
	if(!col.size())
	{
		int xx=row[0];
		int l=1,r=n;
		int ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			ask(xx,l,xx,mid);
			int ret;
			cin>>ret;
			if(ret&1) r=mid-1,ans=mid;
			else l=mid+1;
		}
		assert(ans);
		answer(xx,ans,row[1],ans);
	}
	else if(!row.size())
	{
		int yy=col[0];
		int l=1,r=n;
		int ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			ask(l,yy,mid,yy);
			int ret;
			cin>>ret;
			if(ret&1) r=mid-1,ans=mid;
			else l=mid+1;
		}
		assert(ans);
		answer(ans,yy,ans,col[1]);
	}
	else{
		int ret;
		ask(row[0],col[0],row[0],col[0]);
		cin>>ret;
		if(ret & 1)
			answer(row[0],col[0],row[1],col[1]);
		else answer(row[0],col[1],row[1],col[0]);
	}
}