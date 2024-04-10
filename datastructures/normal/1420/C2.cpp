#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
struct node{
	int min0,max0,min1,max1;
	node(){
		min0=max0=min1=max1=0;
		return;
	}
}tree[4000005];
int t,n,q,a[300005];
inline void pushup(int now){
	tree[now].min0=min(tree[now*2].min0+tree[now*2+1].min0,tree[now*2].min1-tree[now*2+1].max1);
	tree[now].min1=min(tree[now*2].min0+tree[now*2+1].min1,tree[now*2].min1-tree[now*2+1].max0);
	tree[now].max0=max(tree[now*2].max0+tree[now*2+1].max0,tree[now*2].max1-tree[now*2+1].min1);
	tree[now].max1=max(tree[now*2].max0+tree[now*2+1].max1,tree[now*2].max1-tree[now*2+1].min0);
	return;
}
inline void build(int now,int nowl,int nowr){
	if (nowl==nowr){
		tree[now].min0=tree[now].max0=0;
		tree[now].min1=tree[now].max1=a[nowl];
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	pushup(now);
	return;
}
inline void update(int now,int nowl,int nowr,int pos){
	if (nowl==nowr){
		tree[now].min0=tree[now].max0=0;
		tree[now].min1=tree[now].max1=a[nowl];
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)update(now*2,nowl,mid,pos);
	else update(now*2+1,mid+1,nowr,pos);
	pushup(now);
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>q;
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		build(1,1,n);
		printf("%lld\n",tree[1].max1);
		while(q--){
			int x,y;
			scanf("%lld%lld",&x,&y);
			swap(a[x],a[y]);
			update(1,1,n,x);
			update(1,1,n,y);
			printf("%lld\n",tree[1].max1);
		}
	}
	return 0;
}