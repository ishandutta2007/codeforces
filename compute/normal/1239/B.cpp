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

const int maxn=3e5+7;
int pre[maxn];
char s[maxn];
PII cur;
int n;
int solve(int p)
{
	int cnt=0;
	for(int l=0,r=0;l<n;l=r+1)
	{
		int cc=0;
		r=l;
		while(r<n&&pre[r]>=p)
		{
			if(pre[r]==p) cc++;
			r++;
		}
		if(cc>cnt)
		{
			cnt=cc;
			cur=make_pair(l,r);
		}
	}
	return cnt;
}
map<int,int> prepos;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int mi=0,pos=0;
	cin>>n;
	cin>>(s+1);
	int cc=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(') cc++;
		else cc--;
		if(cc<mi)
		{
			mi=cc;
			pos=i;
		}
	}
	string ns;
	for(int i=pos+1;i<=n;i++)
	{
		prepos[(int)ns.length()]=i;
		ns+=s[i];
	}
	for(int i=1;i<=pos;i++) 
	{
		prepos[(int)ns.length()]=i;
		ns+=s[i];
	}
	pre[0]=(ns[0]=='('?1:-1);
	bool ok=1;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		pre[i]=pre[i-1];
		if(ns[i]=='(') pre[i]++;
		else pre[i]--;
		if(pre[i]<0) ok=0;
		if(!pre[i]) ans++;
	}
	dbg(ok);
	if(!ok||(n&1)||pre[n-1]!=0) cout<<"0\n1 1\n";
	else{
		int sv=ans;
		PII op={0,0};
		int a1=solve(1);
		if(a1>ans)
		{
			op=cur;
			ans=a1;
		}
		int a2=solve(2);
		if(a2+sv>ans)
		{
			op=cur;
			ans=a2+sv;
		}
		print(ans);
		print(prepos[op.first],2);
		print(prepos[op.second]);
	}
}