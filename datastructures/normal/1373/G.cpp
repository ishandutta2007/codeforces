#include <iostream>
#include <cstdio>
#include <map>
#define maxn 500000
using namespace std;
int tree[2000005],tag[2000005],qwq[2000005];
void pushup(int now){
	tree[now]=0;
	if (qwq[now*2]==0)tree[now]=max(tree[now],tree[now*2]);
	if (qwq[now*2+1]==0)tree[now]=max(tree[now],tree[now*2+1]);
	return; 
}
void pushdown(int now){
	tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
void upd1(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]+=val;
		tag[now]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)upd1(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)upd1(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return; 
}
void upd2(int now,int nowl,int nowr,int pos){
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr){
		qwq[now]^=1;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)upd2(now*2,nowl,mid,pos);
	else upd2(now*2+1,mid+1,nowr,pos);
	pushup(now);
	return;
}
int n,k,q,x,y;
int cnt[500005];
map<int,int> c[500005];
int main(){
	cin>>n>>k>>q;
	for (int i=1;i<=maxn;i++)upd1(1,1,maxn,i,i,i-1),upd2(1,1,maxn,i);
	while(q--){
		int x,y,fg;
		scanf("%d%d",&x,&y);
		c[x][y]^=1;
		if (c[x][y]==0)fg=-1;
		else fg=1;
		int z;
		if (x<=k)z=y+k-x;
		else z=y+x-k;
		upd1(1,1,maxn,1,z,fg);
		cnt[z]+=fg;
		if (fg==-1&&cnt[z]==0)upd2(1,1,maxn,z);
		if (fg==1&&cnt[z]==1)upd2(1,1,maxn,z);
		printf("%d\n",max(0,tree[1]-n)); 
	}
	return 0;
}