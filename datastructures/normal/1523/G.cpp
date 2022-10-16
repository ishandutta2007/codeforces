#include <iostream>
#include <cstdio>
#include <algorithm>
#define inf 1000000000
using namespace std;
struct node{
	int l,r,x;
}a[100005];
bool cmp(node a,node b){
	return (a.r-a.l+1)>(b.r-b.l+1);
}
int n,m,l[100005],r[100005],ans[50005];
struct sgt_node{
	int l,r,val;
	sgt_node(){
		l=r=0;
		val=inf;
	}
}tree[30000005];
int cnt,root[50005];
struct SGT{
	void tree_ins(int &now,int nowl,int nowr,int pos,int val){
		int pre=now;
		now=++cnt;
		tree[now]=tree[pre];
		tree[now].val=min(tree[now].val,val);
		if (nowl==nowr)return;
		int mid=(nowl+nowr)/2;
		if (pos<=mid)tree_ins(tree[now].l,nowl,mid,pos,val);
		else tree_ins(tree[now].r,mid+1,nowr,pos,val);
		return;
	}
	void ins(int &now,int pos,int val){
		tree_ins(now,1,n,pos,val);
		return; 
	}
	int tree_ask(int now,int nowl,int nowr,int lt,int rt){
		if (now==0)return inf;
		if (nowl>=lt&&nowr<=rt)return tree[now].val;
		int mid=(nowl+nowr)/2,s=inf;
		if (mid>=lt)s=min(s,tree_ask(tree[now].l,nowl,mid,lt,rt));
		if (mid+1<=rt)s=min(s,tree_ask(tree[now].r,mid+1,nowr,lt,rt));
		return s;
	}
	int ask(int now,int l,int r){
		return tree_ask(now,1,n,l,r);
	}
}sgt;
struct BIT{
	int lowbit(int x){
		return x&(-x);
	}
	void ins(int l,int r,int x){
		while(r<=n)sgt.ins(root[r],l,x),r+=lowbit(r);
		return;
	}
	int ask(int l,int r){
		int ans=inf;
		while(r)ans=min(ans,sgt.ask(root[r],l,n)),r-=lowbit(r);
		return ans;
	}
}bit;
int calc(int nowl,int nowr){
	if (nowl>nowr)return 0;
	int x=bit.ask(nowl,nowr);
	if (x==inf)return 0;
	return calc(nowl,l[x]-1)+calc(r[x]+1,nowr)+(r[x]-l[x]+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>l[i]>>r[i];
		a[i].l=l[i],a[i].r=r[i];
		a[i].x=i;
	}
	sort(a+1,a+1+m,cmp);
	int j=1;
	for (int i=n;i>=1;i--){
		while(j<=m&&(a[j].r-a[j].l+1)==i)bit.ins(a[j].l,a[j].r,a[j].x),j++;
		ans[i]=calc(1,n);
	}
	for (int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}