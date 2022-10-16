#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,q,a[3000005],opt,x,y;
int depth[3000005],tag[25],tree[3000005];
inline void pushup(int now){
	tree[now]=tree[now*2]+tree[now*2+1];
	return;
}
inline void build(int now,int nowl,int nowr,int nowd){
	depth[now]=nowd;
	if (nowl==nowr){
		tree[now]=a[nowl];
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid,nowd-1);
	build(now*2+1,mid+1,nowr,nowd-1);
	pushup(now);
	return;
}
inline void update(int now,int pos,int val){
	if (depth[now]==0){
		tree[now]=val;
		return;
	}
	if (pos<=(1<<(depth[now]-1))){
		if (tag[depth[now]]==0)update(now*2,pos,val);
		else update(now*2+1,pos,val);
	}
	else{
		if (tag[depth[now]]==0)update(now*2+1,pos-(1<<(depth[now]-1)),val);
		else update(now*2,pos-(1<<(depth[now]-1)),val); 
	}
	pushup(now);
	return;
}
inline int query(int now,int pos){
	if (depth[now]==0)return tree[now];
	if (pos<=(1<<(depth[now]-1))){
		if (tag[depth[now]]==0)return query(now*2,pos);
		return query(now*2+1,pos);
	}
	else{
		if (tag[depth[now]]==0)return tree[now*2]+query(now*2+1,pos-(1<<(depth[now]-1)));
		return tree[now*2+1]+query(now*2,pos-(1<<(depth[now]-1)));
	}
	return 0;
}
signed main(){
	cin>>n>>q;
	for (int i=1;i<=(1<<n);i++)scanf("%lld",&a[i]);
	build(1,1,(1<<n),n);
	while(q--){
		scanf("%lld",&opt);
		if (opt==1){
			scanf("%lld%lld",&x,&y);
			update(1,x,y);
		}
		else if (opt==2){
			scanf("%lld",&x);
			for (int i=1;i<=x;i++)tag[i]^=1;
		}
		else if (opt==3){
			scanf("%lld",&x);
			tag[x+1]^=1;
		}
		else{
			scanf("%lld%lld",&x,&y);
			if (x==1)printf("%lld\n",query(1,y));
			else printf("%lld\n",query(1,y)-query(1,x-1));
		}
	}
	return 0;
}