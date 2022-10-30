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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vi p(n);
	for(int i=0;i<n;i++) cin>>p[i];
	sort(p.begin(),p.end());
	multiset<int> st,org;
	ll tot=0;
	for(int i=0;i<n;i++) org.insert(p[i]);
	for(int i=1;i<n;i++)
	{
		st.insert(p[i]-p[i-1]);
		tot+=p[i]-p[i-1];
	}
	print(st.size()?tot-*st.rbegin():0);
	while(q--)
	{
		int t,x;
		cin>>t>>x;
		if(t==0)
		{
			auto it=org.find(x);
			auto l=it,r=it;
			if(it!=org.begin())
			{
				l--;
				st.erase(st.find(*it-*l));
				tot-=*it-*l;
			}
			if(it!=org.end())
			{
				r++;
				if(r!=org.end())
				{
					st.erase(st.find(*r-*it));
					tot-=*r-*it;
				}
			}
			if(r!=org.end()&&it!=org.begin())
			{
				st.insert(*r-*l);
				tot+=*r-*l;
			}
			org.erase(it);
		}
		else{
			auto it=org.lower_bound(x);
			if(it!=org.end())
			{
				auto l=it;
				if(l!=org.begin())
				{
					l--;
					st.erase(st.find(*it-*l));
					tot-=*it-*l;
				}
				st.insert(*it-x);
				tot+=*it-x;
			}
			if(it!=org.begin())
			{
				it--;
				st.insert(x-*it);
				tot+=x-*it;
			}
			org.insert(x);
		}
		print(st.size()?tot-*st.rbegin():0);
	}
}