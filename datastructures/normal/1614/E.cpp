#include <iostream>
#include <cstdio>
#include <cstring>
#define maxv 1000000000
using namespace std;
struct SGT{
	struct tree_node{
		int l,r,val;
		tree_node(){
			l=r=val=0;
			return;
		}
	}tree[7000005];
	int root,cnt;
	SGT(){
		root=cnt=0;
		return;
	}
	void tree_update(int &now,int nowl,int nowr,int pos){
		if (now==0)now=++cnt;
		tree[now].val++;
		if (nowl==nowr)return;
		int mid=(nowl+nowr)/2;
		if (pos<=mid)tree_update(tree[now].l,nowl,mid,pos);
		else tree_update(tree[now].r,mid+1,nowr,pos);
		return;
	}
	void update(int pos){
		if (pos<0||pos>maxv)return;
		tree_update(root,0,maxv,pos);
		return;
	}
	int tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (now==0)return 0;
		if (nowl>=lt&&nowr<=rt)return tree[now].val;
		int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s+=tree_query(tree[now].l,nowl,mid,lt,rt);
		if (mid+1<=rt)s+=tree_query(tree[now].r,mid+1,nowr,lt,rt);
		return s;
	}
	int query(int l,int r){
		if (l>r)return 0;
		return tree_query(root,0,maxv,l,r);
	}
}sgt;
int tag;
int n,t,k,x,lastans;
int ask(int x){
	return x+tag-sgt.query(0,x);
}
int larger(int t){
	int l=0,r=maxv,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if (ask(mid)>=t)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int lower(int t){
	int l=0,r=maxv,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if (ask(mid)<=t)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&t);
		int p1=lower(t-1),p2=larger(t+1);
		if (p1!=-1){
			tag++;
			sgt.update(p1+1);
		}
		if (p2!=-1)sgt.update(p2);
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			scanf("%d",&x);
			x=(x+lastans)%(maxv+1);
			lastans=ask(x);
			printf("%d\n",lastans);
		}
	}
	return 0;
}