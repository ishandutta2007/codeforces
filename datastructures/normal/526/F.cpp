#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[1000005],x,y;
struct SGT{
	struct node{
		int val,num,tag;
		node(){
			val=num=tag=0;
			return;
		}
	}tree[1200005];
	inline void build(register int now,register int nowl,register int nowr){
		tree[now].num=nowr-nowl+1;
		if (nowl==nowr)return;
		register int mid=(nowl+nowr)/2;
		build(now*2,nowl,mid);
		build(now*2+1,mid+1,nowr);
		return;
	}
	inline void pushup(register int now){
		if (tree[now*2].val==tree[now*2+1].val)tree[now].val=tree[now*2].val,tree[now].num=tree[now*2].num+tree[now*2+1].num;
		if (tree[now*2].val<tree[now*2+1].val)tree[now].val=tree[now*2].val,tree[now].num=tree[now*2].num;
		if (tree[now*2+1].val<tree[now*2].val)tree[now].val=tree[now*2+1].val,tree[now].num=tree[now*2+1].num;
		return;
	}
	inline void pushdown(register int now){
		tree[now*2].val+=tree[now].tag,tree[now*2+1].val+=tree[now].tag;
		tree[now*2].tag+=tree[now].tag,tree[now*2+1].tag+=tree[now].tag;
		tree[now].tag=0;
		return;
	}
	inline void tree_update(register int now,register int nowl,register int nowr,register int lt,register int rt,register int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now].val+=val;
			tree[now].tag+=val;
			return;
		}
		register int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	inline void update(register int l,register int r,register int val){
		tree_update(1,1,n,l,r,val);
		return;
	}
	inline int ask(){
		return tree[1].num;
	}
}sgt;
int q1[1000005],t1,q2[1000005],t2;
long long ans;
int main(){
	cin>>n;
	for (register int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	sgt.build(1,1,n);
	for (register int i=1;i<=n;i++){
		sgt.update(1,i,-1);
		while(t1>0&&a[q1[t1]]<a[i]){
			sgt.update(q1[t1-1]+1,q1[t1],a[i]-a[q1[t1]]);
			--t1;
		}
		q1[++t1]=i;
		while(t2>0&&a[q2[t2]]>a[i]){
			sgt.update(q2[t2-1]+1,q2[t2],a[q2[t2]]-a[i]);
			--t2;
		}
		q2[++t2]=i;
		ans+=sgt.ask();
	}
	cout<<ans<<endl;
	return 0;
}