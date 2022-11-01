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
int cnt[4];
int main()
{
	int n,sx,sy;
	cin>>n>>sx>>sy;
	for(int i=0,x,y;i<n;i++)
	{
		cin>>x>>y;
		if(x==sx)
		{
			if(y>sy) cnt[0]++;
			else cnt[2]++;
		}
		else if(y==sy)
		{
			if(x>sx) cnt[1]++;
			else cnt[3]++;
		}
		else{
			if(x>sx&&y>sy)
			{
				cnt[0]++;
				cnt[1]++;
			}
			else if(x>sx&&y<sy)
			{
				cnt[1]++;
				cnt[2]++;
			}
			else if(x<sx&&y>sy)
			{
				cnt[0]++;
				cnt[3]++;
			}
			else {
				cnt[3]++;
				cnt[2]++;
			}
		}
	}
	int mx=0,tar=-1;
	for(int i=0;i<4;i++){
		if(mx<cnt[i])
		{
			mx=cnt[i];
			tar=i;
		}
	}
	cout<<mx<<endl;
	if(tar==0)
		sy++;
	else if(tar==1) sx++;
	else if(tar==2) sy--;
	else sx--;
	cout<<sx<<" "<<sy<<endl;
}