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
const int maxn=1e6+7;
pi seg[maxn];
int pre[maxn];
int fa[maxn];
int cnt=0;
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	if(x!=y) cnt++;
	fa[y]=x;
}
int pos[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++) fa[i]=i;
	for(int i=1,l,r;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		seg[i]=make_pair(l,r);
		pos[seg[i].first]=i;
		pos[seg[i].second]=-i;
	}
	for(int i=1;i<=2*n;i++) pre[i]=i-1;
	bool ok=1;
	for(int i=1;i<=2*n;i++)
	{
		int cur=pos[i];
		dbg(i,cur);
		if(cur<0)
		{
			int cc=i;
			dbg(i,pre[cc],pos[pre[cc]]);
			while(pre[cc]&&pos[pre[cc]]!=-cur)
			{
				cc=pre[cc];
				if(Find(-cur)==Find(pos[cc]))
				{
					ok=0;
					break;
				}
				Union(pos[cc],-cur);
			}
			if(!ok) break;
			pre[cc]=pre[pre[cc]];
			pre[i+1]=pre[i];
		}
	}
	if(!ok||cnt!=n-1) puts("NO");
	else puts("YES");
	
}