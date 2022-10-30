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
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"First"<<endl;
		for(int i=1;i<=2*n;i++)
		{
			cout<<i%n+1;
			if(i==2*n) cout<<endl;
			else cout<<" ";
		}
	}
	else{
		cout<<"Second"<<endl;
		vc<vi> pa(n);
		vi z(2*n+1);
		for(int i=1,p;i<=2*n;i++)
		{
			cin>>p;
			p--;
			z[i]=p;
			pa[p].push_back(i);
		}
		vi vis(n);
		vc<ll> ans(n);
		for(int i=0;i<n;i++)
		{
			if(vis[i])
				continue;
			int cur=i,val=i?i:n;
			while(!vis[cur])
			{
				ans[z[val]]=val;
				vis[cur]=1;
				int nxt=z[val];
				for(auto u:pa[nxt])
				{
					if(u!=val)
					{
						val=u;
						if(val>n) val-=n;
						else val+=n;
						cur=val%n;
						break;
					}
				}
			}

		}
		if(accumulate(ans.begin(),ans.end(),0LL)%(2*n)!=0)
		{
			for(int i=0;i<n;i++)
			{
				if(pa[i][0]==ans[i]) ans[i]=pa[i][1];
				else ans[i]=pa[i][0];
			}
		}
		for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
}