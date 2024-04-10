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
typedef pair<int,int> PII;
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
vi ans;
bool ok;
void dfs(int a,int b,int c,int d)
{
	if(a<0||b<0||c<0||d<0) return;
	if(!a&&!b&&!c&&!d) 
	{
		ok=1;
		return;
	}
	if(ans.back()==0)
	{
		ans.push_back(1);
		dfs(a,b-1,c,d);
	}
	else if(ans.back()==3)
	{
		ans.push_back(2);
		dfs(a,b,c-1,d);
	}
	else if(ans.back()==1)
	{
		if(a)
		{
			ans.push_back(0);
			dfs(a-1,b,c,d);
		}
		else {
			ans.push_back(2);
			dfs(a,b,c-1,d);
		}
	}
	else{
		if(d){
			ans.push_back(3);
			dfs(a,b,c,d-1);
		}
		else{
			ans.push_back(1);
			dfs(a,b-1,c,d);
		}
	}

}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	ans={0};
	dfs(a-1,b,c,d);
	if(!ok)
	{
		ans={1};
		dfs(a,b-1,c,d);
	}
	if(!ok)
	{
		ans={2};
		dfs(a,b,c-1,d);
	}
	if(!ok)
	{
		ans={3};
		dfs(a,b,c,d-1);
	}
	if(!ok) cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i=0;i<a+b+c+d;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
}