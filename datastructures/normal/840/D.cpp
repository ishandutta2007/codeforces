#include <iostream>
#include <cstdio>
using namespace std;
int n,q,a[300005],l,r,k;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct tree_node{
	int l,r,val;
	tree_node(){
		l=r=val=0;
		return;
	}
}tree[10000005];
int root[300005],cnt;
void ins(int &now,int nowl,int nowr,int pos){
	int pre=now;
	now=++cnt;
	tree[now]=tree[pre];
	tree[now].val++;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)ins(tree[now].l,nowl,mid,pos);
	else ins(tree[now].r,mid+1,nowr,pos);
	return;
}
int ask(int now1,int now2,int nowl,int nowr,int k){
	if (nowl==nowr){
		if (tree[now2].val-tree[now1].val>=k)return nowl;
		return -1;
	}
	int mid=(nowl+nowr)/2,qwq1=-1,qwq2=-1;
	if (tree[tree[now2].l].val-tree[tree[now1].l].val>=k)qwq1=ask(tree[now1].l,tree[now2].l,nowl,mid,k);
	if (qwq1!=-1)return qwq1;
	if (tree[tree[now2].r].val-tree[tree[now1].r].val>=k)qwq2=ask(tree[now1].r,tree[now2].r,mid+1,nowr,k);
	if (qwq2!=-1)return qwq2;
	return -1;
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)root[i]=root[i-1],ins(root[i],1,n,a[i]);
	while(q--){
		l=read(),r=read(),k=read();
		printf("%d\n",ask(root[l-1],root[r],1,n,(r-l+1)/k+1));
	}
	return 0;
}