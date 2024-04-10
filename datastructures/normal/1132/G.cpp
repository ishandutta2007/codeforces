#include <iostream>
#include <cstdio>
using namespace std;
int n,k,a[1000005],totm,u[1000005],v[1000005],first[1000005],nxt[1000005];
int q[1000005],tail;
int idx,l[1000005],r[1000005];
int tree[4000005],tag[4000005];
void pushdown(int now){
	tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
void pushup(int now){
	tree[now]=max(tree[now*2],tree[now*2+1]);
}
void update(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]+=val;
		tag[now]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
void add(int a,int b){
	int i=++totm;
	u[i]=a,v[i]=b;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
void dfs(int now){
	if (now!=0)l[now]=++idx;
	for (int i=first[now];i;i=nxt[i])dfs(v[i]);
	if (now!=0)r[now]=idx;
	return;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=n;i>=1;i--){
		while(tail&&a[q[tail]]<=a[i])tail--;
		add(q[tail],i);
		q[++tail]=i;
	}
	dfs(0);
	for (int i=1;i<=k;i++)update(1,1,n,l[i],r[i],1);
	printf("%d ",tree[1]);
	for (int i=2;i+k-1<=n;i++){
		update(1,1,n,l[i-1],r[i-1],-1);
		update(1,1,n,l[i+k-1],r[i+k-1],1);
		printf("%d ",tree[1]);
	}
	return 0;
}