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
	int k,n;
	cin>>k;
	while(k--)
	{
		cin>>n;
		string s,t;
		cin>>s>>t;
		int cnt[30];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			cnt[s[i]-'a']++;
			cnt[t[i]-'a']++;
		}
		vc<PII> ans;
		bool ok=1;
		for(int i=0;i<26;i++)
		{
			if(cnt[i]&1) ok=0;
		}
		if(!ok) cout<<"No\n";
		else{
			cout<<"Yes\n";
			for(int i=0;i<n;i++)
			{
				if(s[i]!=t[i])
				{
					bool fd=0;
					for(int j=i+1;j<n;j++)
					{
						if(t[j]==t[i])
						{
							ans.push_back(make_pair(i,j));
							swap(s[i],t[j]);
							fd=1;
							break;
						}
					}
					if(!fd)
					{
						for(int j=i+1;j<n;j++)
						{
							if(s[j]==t[i])
							{
								ans.push_back(make_pair(j,j));
								swap(s[j],t[j]);
								ans.push_back(make_pair(i,j));
								swap(s[i],t[j]);
								break;
							}
						}
					}
				}
			}
			cout<<ans.size()<<'\n';
			for(auto u:ans) cout<<u.first+1<<" "<<u.second+1<<'\n';
		}
	}
}