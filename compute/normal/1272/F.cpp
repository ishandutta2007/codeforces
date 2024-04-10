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
struct Data{
	int h,p1,p2;
};
const int maxn=205;
Data pre[maxn*2][maxn][maxn];
bool vis[maxn*2][maxn][maxn];
void print(Data cur){
	if(!cur.h&&!cur.p1&&!cur.p2) return;
	auto pp=pre[cur.h][cur.p1][cur.p2];
	print(pp);
	if(pp.h>cur.h) cout<<')';
	else cout<<'(';
}
int main()
{
	string s,t;
	cin>>s>>t;
	s+='\n';
	t+='\n';
	queue<Data> q;
	q.push({0,0,0});
	vis[0][0][0]=1;
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		if(u.p1==s.length()-1&&u.p2==t.length()-1&&!u.h)
		{
			print(u);
			cout<<endl;
			break;
		}
		{
			Data nxt=u;
			nxt.h++;
			if(s[u.p1]=='(') nxt.p1++;
			if(t[u.p2]=='(') nxt.p2++;
			if(!vis[nxt.h][nxt.p1][nxt.p2])
			{
				q.push(nxt);
				pre[nxt.h][nxt.p1][nxt.p2]=u;
				vis[nxt.h][nxt.p1][nxt.p2]=1;
			}
		}
		if(u.h){
			Data nxt=u;
			nxt.h--;
			if(s[u.p1]==')') nxt.p1++;
			if(t[u.p2]==')') nxt.p2++;
			if(!vis[nxt.h][nxt.p1][nxt.p2])
			{
				q.push(nxt);
				pre[nxt.h][nxt.p1][nxt.p2]=u;
				vis[nxt.h][nxt.p1][nxt.p2]=1;
			}
		}
		
	}
}