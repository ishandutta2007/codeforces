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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi p(n);
		for(int i=0;i<n;i++) cin>>p[i];
		int mx=n/2;
		int g=0,s=0,b=0;
		vi dis;
		dis.push_back(0);
		int ming=1;
		for(int i=1;i<=mx;i++)
		{
			if(p[i]==p[i-1]) ming++;
			else break;
		}
		for(int i=1;i<=mx;i++){
			if(p[i]!=p[i-1]) dis.push_back(i);
		}
		int cur=mx;
		if(dis.back()!=mx) cur=dis.back();
		else dis.pop_back();
		for(int i=dis.size()-1;i>=0;i--){
			if(cur<s&&cur<b)
			{
				g=cur;
				break;
			}
			else{
				if(b<=ming) b+=cur-dis[i];
				else s+=cur-dis[i];
				cur=dis[i];
			}
		}
		if(g<s&&g<b&&g&&s&&b)
			cout<<g<<" "<<s<<" "<<b<<'\n';
		else cout<<"0 0 0\n";

	}
}