#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,k,u[200005],v[200005],first[100005],nxt[200005],book[100005];
struct node{
	int u,v,w;
}e[100005];
int a[100005],q[100005],head,tail;
bool cmp(node a,node b){
	return a.w<b.w;
}
bool check(int x){
	memset(first,0,sizeof(first));
	memset(nxt,0,sizeof(nxt));
	memset(book,0,sizeof(book));
	for (int i=1;i<=x;i++){
		u[i]=e[i].u,v[i]=e[i].v;
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	q[head=tail=1]=a[1];
	book[a[1]]=1;
	while(head<=tail){
		int now=q[head];
		for (int i=first[now];i;i=nxt[i])
			if (book[v[i]]==0)book[v[i]]=1,q[++tail]=v[i];
		head++;
	}
	for (int i=1;i<=k;i++)
		if (book[a[i]]==0)return 0;
	return 1;
}
int main(){
//	freopen("1081D.in","r",stdin);
//	freopen("1081D.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+m,cmp);
	int l=1,r=m,ans=1000000000;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=e[mid].w,r=mid-1;
		else l=mid+1;
	}
	for (int i=1;i<=k;i++)printf("%d ",ans);
	return 0;
}