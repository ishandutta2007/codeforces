#include <iostream>
#include <cstdio>
#include <algorithm>
#define inf 1000000000000000000
#define int long long
using namespace std;
int n,p[1000005],c[1000005],v[1000005],ans,sum[1000005];
struct SGT{
	int tree[10000005],tag[10000005];
	inline void mem(){
		for (int i=0;i<=4*n+1;i++)tree[i]=tag[i]=0;
		return;
	}
	inline void pushup(int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void pushdown(int now){
		if (tag[now]==0)return;
		int val=tag[now];
		tree[now*2]+=val,tree[now*2+1]+=val;
		tag[now*2]+=val,tag[now*2+1]+=val;
		tag[now]=0;
		return;
	}
	inline void tree_update(int now,int nowl,int nowr,int lt,int rt,int val){
		pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	inline void update(int l,int r,int val){
		if (l<=0||r>n||l>r)return;
		tree_update(1,1,n,l,r,val);
		return;
	}
	inline int query(){
		return tree[1];
	}
	inline void build(int now,int nowl,int nowr){
		if (nowl==nowr){
			tree[now]=sum[nowl];
			return;
		}
		int mid=(nowl+nowr)/2;
		build(now*2,nowl,mid);
		build(now*2+1,mid+1,nowr);
		pushup(now);
		return;
	}
}sgt;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&p[i]);
	for (int i=1;i<=n;i++)scanf("%I64d",&c[i]);
	for (int i=1;i<=n;i++)v[p[i]]=c[i];
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i];
	sgt.mem();
	sgt.build(1,1,n);
	ans=inf;
	int nowsum=0;
	for (int i=1;i<n;i++){
		nowsum+=c[i];
		sgt.update(1,p[i]-1,c[i]);
		sgt.update(p[i],n,-c[i]);
		ans=min(ans,sgt.query());
		ans=min(ans,nowsum);
	}
	cout<<ans<<endl;
}