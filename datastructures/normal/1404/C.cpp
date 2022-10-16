#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define inf 1000000000
using namespace std;
int n,T,a[1000005],ans[1000005];
int tree[10000005],tag[10000005];
int q[1000005],head=1,tail;
vector <int>c[1000005],id[1000005];
struct BIT{
	int tree[1000005];
	BIT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int pos){
		while(pos<=n)tree[pos]++,pos+=lowbit(pos);
		return;
	}
	inline int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit;
inline void pushdown(int now){
	tree[now*2]-=tag[now],tree[now*2+1]-=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
inline void pushup(int now){
	tree[now]=min(tree[now*2],tree[now*2+1]);
	return;
}
inline void change(int now,int nowl,int nowr,int pos,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr){
		tree[now]=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)change(now*2,nowl,mid,pos,val);
	else change(now*2+1,mid+1,nowr,pos,val);
	pushup(now);
	return;
}
inline void update(int now,int nowl,int nowr,int lt,int rt){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]--;
		tag[now]++;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt);
	pushup(now);
	return;
}
inline void check(int now,int nowl,int nowr){
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr){
		if (tree[now]==0){
			q[++tail]=nowl;
			bit.add(nowl);
			tree[now]=inf;
		}
		return;
	}
	int mid=(nowl+nowr)/2;
	if (tree[now*2]==0)check(now*2,nowl,mid);
	if (tree[now*2+1]==0)check(now*2+1,mid+1,nowr);
	pushup(now);
	return; 
}
int main(){
	cin>>n>>T;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=T;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=1+x,y=n-y;
		c[x].push_back(y);
		id[x].push_back(i);
	}
	for (int i=1;i<=n;i++)change(1,1,n,i,inf);
	for (int i=n;i>=1;i--){
		if (i-a[i]==0)bit.add(i),q[++tail]=i;
		if (i-a[i]>0)change(1,1,n,i,i-a[i]);
		while(head<=tail){
			update(1,1,n,q[head],n);
			check(1,1,n);
			head++;
		}
		for (int j=0,len=c[i].size();j<len;j++)
			ans[id[i][j]]=bit.ask(c[i][j]);
	} 
	for (int i=1;i<=T;i++)printf("%d\n",ans[i]);
	return 0;
}