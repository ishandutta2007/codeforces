#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,ans=2e9; 
struct node{
	int l,r,w;
	node(){
		l=r=w=0;
		return;
	}
}a[300005];
bool cmp(node a,node b){
	return a.w<b.w;
}
struct SGT{
	int maxn,tree[4000005],tag[4000005];
	void mem(){
		maxn=1000000;
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	void pushup(int now){
		tree[now]=min(tree[now<<1],tree[(now<<1)|1]);
		return;
	}
	void pushdown(int now,int nowl,int nowr){
		int mid=(nowl+nowr)>>1;
		tag[now<<1]+=tag[now],tag[(now<<1)|1]+=tag[now];
		tree[now<<1]+=tag[now],tree[(now<<1)|1]+=tag[now];
		tag[now]=0;
		return;
	}
	int tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)>>1,s=1e9;
		if (mid>=lt)s=min(s,tree_query(now<<1,nowl,mid,lt,rt));
		if (mid+1<=rt)s=min(s,tree_query((now<<1|1),mid+1,nowr,lt,rt));
		return s;
	}
	int query(int l,int r){
		return tree_query(1,1,maxn,l,r);
	}
	void tree_update(int now,int nowl,int nowr,int lt,int rt,int val){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_update(now<<1,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_update((now<<1)|1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	void update(int l,int r,int val){
		return tree_update(1,1,maxn,l,r,val);
	}
}sgt;
int main(){
	sgt.mem();
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w),a[i].r--;
	sort(a+1,a+1+n,cmp);
	int j=1;
	for (int i=1;i<=n;i++){
		if (i>1)sgt.update(a[i-1].l,a[i-1].r,-1);
		while(j<=n&&sgt.query(1,m-1)==0)sgt.update(a[j].l,a[j].r,1),j++;
		if (sgt.query(1,m-1)>0)ans=min(ans,a[j-1].w-a[i].w);
	}
	cout<<ans<<endl;
	return 0;
}