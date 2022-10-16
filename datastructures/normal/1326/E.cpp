#include <iostream>
#include <cstdio>
using namespace std;
int tree[1200005],tag[1200005];
void pushup(int now){
	tree[now]=max(tree[now*2],tree[now*2+1]);
	return;
}
void pushdown(int now){
	tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
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
int n,p[300005],q[300005],pos[300005],now;
int main(){
	cin>>n;
	for (register int i=1;i<=n;i++)scanf("%d",&p[i]),pos[p[i]]=i;
	for (register int i=1;i<=n;i++)scanf("%d",&q[i]);
	now=n;
	update(1,1,n,1,pos[now],1);
	printf("%d ",now);
	for (register int i=1;i<n;i++){
		update(1,1,n,1,q[i],-1);
		while(tree[1]<=0)now--,update(1,1,n,1,pos[now],1);
		printf("%d ",now);
	}
	return 0;
}