#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
int n,m;
ll x,a[300005];
int fa[300005];
int ans[300005],tot,cur[300005];
vector <int>e[300005],id[300005];
inline int find(register int x){
	if (x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int id;
	ll val;
	node(){
		id=val=0;
		return;
	}
	bool operator <(const node &x)const{
		return val<x.val;
	}
}c;
priority_queue <node>h;
inline void merge(register int nowa,register int nowb){
	if (e[nowa].size()<e[nowb].size())swap(nowa,nowb);
	fa[nowb]=nowa,a[nowa]=a[nowa]+a[nowb]-x;
	c.id=nowa,c.val=a[nowa];
	h.push(c);
	for (register int i=cur[nowb],j=e[nowb].size();i<j;i++)
		e[nowa].push_back(e[nowb][i]),id[nowa].push_back(id[nowb][i]);
	return;
}
signed main(){
	cin>>n>>m>>x;
	for (register int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (register int i=1;i<=m;i++){
		register int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v),id[u].push_back(i);
		e[v].push_back(u),id[v].push_back(i);
	}
	for (register int i=1;i<=n;i++){
		fa[i]=i;
		c.id=i,c.val=a[i];
		h.push(c);
	}
	while(!h.empty()){
		node d=h.top();
		h.pop();
		register int now=d.id;
		if (fa[now]!=now)continue;
		for (register int i=cur[now],j=e[now].size();i<j;i++){
			register int v=find(e[now][i]);
			cur[now]=i;
			if (now==v)continue;
			if (a[now]+a[v]<x)continue;
			ans[++tot]=id[now][i];
			merge(v,now);
			break;
		}
	}
	if (tot==n-1){
		puts("YES");
		for (register int i=1;i<=tot;i++)printf("%d\n",ans[i]);
		return 0;
	}
	puts("NO");
	return 0;
}