#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
	int pos,val;
}a[1000005];
bool cmp(node a,node b){
	return a.val<b.val;
}
int n,m,u[1000005],v[1000005],first[500005],nxt[1000005],t[500005];
int book[1000005];
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		a[i].pos=i,a[i].val=t[i];
	}
	sort(a+1,a+1+n,cmp);
	int fg=1;
	for (int i=1;i<=m;i++)
		if (t[u[i]]==t[v[i]])fg=0;
	for (int i=1;i<=n;i++){
		int now=a[i].pos;
		int cnt=0;
		for (int j=first[now];j;j=nxt[j]){
			book[t[v[j]]]++;
			if (t[v[j]]<t[now]&&book[t[v[j]]]==1)cnt++;
		}
		if (cnt<t[now]-1)fg=0;
		for (int j=first[now];j;j=nxt[j])
			book[t[v[j]]]=0;
	}
	if (fg==0)puts("-1");
	else{
		for (int i=1;i<=n;i++)
			printf("%d ",a[i].pos);
	}
	return 0;
}