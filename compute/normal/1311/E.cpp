#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
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
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		if(n*(n-1)/2<d) cout<<"NO\n";
		else{
			vi cnt(5005);
			int rem=n;
			for(int i=0;i<15;i++)
			{
				cnt[i]=min(rem,1<<i);
				d-=cnt[i]*i;
				rem-=cnt[i];
			}
			if(d<0) cout<<"NO\n";
			else{
				while(d)
				{
					for(int i=1;i<n;i++)
					{
						if(!cnt[i]||!d) break;
						while(d&&cnt[i]&&(cnt[i]-1)*2>=cnt[i+1]+1)
						{
							cnt[i]--;
							cnt[i+1]++;
							d--;
						}
					}
				}
				vi fa(n+1);
				int cur=2;
				int pre=1;
				for(int i=1;;i++)
				{
					if(!cnt[i]) break;
					int fi=cur;
					for(int j=0;j<cnt[i];j++)
						fa[cur++]=pre+j/2;
					pre=fi;
				}
				cout<<"YES\n";
				for(int i=2;i<=n;i++) cout<<fa[i]<<(i==n?'\n':' ');
			}
		}
	}
}