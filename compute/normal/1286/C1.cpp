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
vc<string> ask(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	int len=r-l+1;
	vc<string> ret;
	for(int i=0;i<len*(len+1)/2;i++)
	{
		string cur;
		cin>>cur;
		sort(cur.begin(),cur.end());
		ret.push_back(cur);
	}
	return ret;
}
map<string,int> cnt;
void answer(string s)
{
	cout<<"! "<<s<<endl;
}
int main()
{
	int n;
	cin>>n;
	if(n==1)
		answer(ask(1,1)[0]);
	else{
		auto A=ask(1,n);
		auto B=ask(2,n);
		for(auto u:A)
			cnt[u]++;
		for(auto u:B)
			cnt[u]--;
		vc<string> all;
		string ans;
		for(auto u:cnt)
		{
			if(u.second)
				all.push_back(u.first);
		}
		sort(all.begin(),all.end(),[&](string i,string j){return i.length()<j.length();});
		int cc[30];
		memset(cc,0,sizeof(cc));
		for(auto u:all)
		{
			int cur[30];
			memset(cur,0,sizeof(cur));
			for(auto v:u)
				cur[v-'a']++;
			for(int i=0;i<30;i++)
			{
				if(cur[i]>cc[i])
				{
					cc[i]++;
					ans+=(i+'a');
					break;
				}
			}
		}
		answer(ans);
	}

}