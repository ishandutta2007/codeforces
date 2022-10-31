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
struct node{
	int v,pos;
	bool operator<(const node& a)const{
		if(v==a.v) return pos<a.pos;
		return v>a.v;
	}
};
const int maxn=2e5+7;
vector<PII> query[maxn];
int ans[maxn];
int n;
int cnt[maxn<<2];
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void update(int p,int L=1,int R=n,int o=1)
{
	cnt[o]++;
	if(L==R)
		return;
	int mid=L+R>>1;
	if(p<=mid) update(p,Lson);
	else update(p,Rson);
}
int getans(int k,int L=1,int R=n,int o=1)
{
	if(L==R)
		return L;
	int mid=L+R>>1;
	if(cnt[lson]>=k) return getans(k,Lson);
	return getans(k-cnt[lson],Rson);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	vi a(n);
	vector<node> all;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		all.push_back(node{a[i],i});
	}
	sort(all.begin(),all.end());
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		PII tmp;
		cin>>tmp.first>>tmp.second;
		query[tmp.first].push_back(make_pair(tmp.second,i));
	}
	for(int i=1;i<=n;i++)
	{
		update(all[i-1].pos+1);
		dbg(i,all[i-1].pos);
		sort(query[i].begin(),query[i].end());
		for(auto q:query[i])
			ans[q.second]=a[getans(q.first)-1];
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
}