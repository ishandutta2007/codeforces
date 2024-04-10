#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define int long long
#define inf 1000000000 
using namespace std;
int n,a[500005],ans;
vector <int>c[500005];
int len[500005];
struct tree_node{
	int l,r,val,cnt,tag;
	inline void mem(){
		l=r=val=cnt=tag=0;
		return;
	}
}tree[2000005];
int tag[2000005];
inline void pushup(register int now){
	if (tree[now*2].val<tree[now*2+1].val)tree[now].val=tree[now*2].val,tree[now].cnt=tree[now*2].cnt;
	else if (tree[now*2+1].val<tree[now*2].val)tree[now].val=tree[now*2+1].val,tree[now].cnt=tree[now*2+1].cnt;
	else tree[now].val=tree[now*2].val,tree[now].cnt=tree[now*2].cnt+tree[now*2+1].cnt;
	return;
}
inline void pushdown(register int now){
	tree[now*2].val+=tree[now].tag,tree[now*2+1].val+=tree[now].tag;
	tree[now*2].tag+=tree[now].tag,tree[now*2+1].tag+=tree[now].tag;
	tree[now].tag=0;
	return;
}
inline void build(register int now,register int nowl,register int nowr){
	if (nowl==nowr){
		tree[now].val=inf;
		tree[now].cnt=1;
		return;
	}
	register int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	pushup(now);
	return;
}
inline void mem(){
	for (register int i=0;i<=2000000;i++)tree[i].mem();
	memset(tag,0,sizeof(tag));
	build(1,1,n);
	return;
}
inline void update(register int now,register int nowl,register int nowr,register int lt,register int rt,register int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now].val+=val;
		tree[now].tag+=val;
		return;
	}
	register int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
inline int ask(){
	if (tree[1].val==0)return tree[1].cnt;
	return 0;
}
signed main(){
	cin>>n;
	for (register int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (register int i=1;i<=n;i++)c[i].push_back(0);
	mem();
	for (register int i=1;i<=n;i++){
		update(1,1,n,i,i,-inf);
		c[a[i]].push_back(i),++len[a[i]];
		update(1,1,n,c[a[i]][len[a[i]]-1]+1,c[a[i]][len[a[i]]],1);
		if (len[a[i]]>=3)update(1,1,n,c[a[i]][len[a[i]]-3]+1,c[a[i]][len[a[i]]-2],-1);
		if (len[a[i]]>=4)update(1,1,n,c[a[i]][len[a[i]]-4]+1,c[a[i]][len[a[i]]-3],1);
		ans+=ask();
	}
	cout<<ans<<endl;
	return 0;
}