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

string s;
vector<PII> ans;
void update(int l,int r)
{
	ans.push_back(make_pair(l,r));
	while(l<r)
	{
		swap(s[l],s[r]);
		l++,r--;
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ans.clear();
		int n,k;
		cin>>n>>k;
		cin>>s;
		k--;
		for(int i=0;i<n;i++)
		{
			if(!k)
			{
				int r=-1;
				for(int j=i;j<n;j++)
				{
					if(s[j]=='(')
					{
						r=j;
						break;
					}
				}
				if(r==-1) break;
				if(r!=i)
					update(i,r);
			}
			else{
				if(i&1)
				{
					k--;
					int r=-1;
					for(int j=i;j<n;j++)
					{
						if(s[j]==')')
						{
							r=j;
							break;
						}
					}
					if(r!=i)
						update(i,r);
				}
				else{
					int r=-1;
					for(int j=i;j<n;j++)
					{
						if(s[j]=='(')
						{
							r=j;
							break;
						}
					}
					if(r!=i)
						update(i,r);
				}
			}
			dbg(s);
			dbg(k);
		}
		printf("%d\n",(int)ans.size());
		for(auto u:ans) printf("%d %d\n",u.first+1,u.second+1);
	}

}