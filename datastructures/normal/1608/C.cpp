#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int t,n;
struct node{
	int a,b,id;
}a[100005];
bool cmp1(node x,node y){
	return x.a<y.a;
}
bool cmp2(node x,node y){
	return x.b<y.b;
}
int totm,u[200005],v[200005],first[200005],nxt[200005];
void add(int x,int y){
	int i=++totm;
	u[i]=x,v[i]=y;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
int idx,tot,dfn[200005],low[200005],in_sta[200005],sta[200005];
int ans[200005];
void dfs(int now){
	dfn[now]=++idx;
	low[now]=dfn[now];
	in_sta[now]=1;
	sta[++tot]=now;
	for (int i=first[now];i;i=nxt[i]){
		if (dfn[v[i]]==0)dfs(v[i]),low[now]=min(low[now],low[v[i]]);
		else if (in_sta[v[i]]==1)low[now]=min(low[now],low[v[i]]);
	}
	if (dfn[now]==low[now]){
		while(sta[tot]!=now){
			in_sta[sta[tot]]=0;
			if (now==a[n].id)ans[sta[tot]]=1;
			tot--;
		}
		in_sta[sta[tot]]=0;
		if (now==a[n].id)ans[sta[tot]]=1;
		tot--;
	}
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i].a),a[i].id=i;
		for (int i=1;i<=n;i++)scanf("%d",&a[i].b);
		sort(a+1,a+1+n,cmp1);
		for (int i=2;i<=n;i++)add(a[i].id,a[i-1].id);
		sort(a+1,a+1+n,cmp2);
		for (int i=2;i<=n;i++)add(a[i].id,a[i-1].id);
		dfs(a[n].id);
		for (int i=1;i<=n;i++)printf("%d",ans[i]);puts("");
		totm=idx=tot=0;
		for (int i=1;i<=2*n;i++)u[i]=v[i]=first[i]=nxt[i]=dfn[i]=in_sta[i]=ans[i]=0;
	}
	return 0;
}