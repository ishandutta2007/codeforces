#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k,a[1000005],f[35005][105],s[100005],e[100005];
struct SGT{
	int tree[200005],tag[200005],maxn;
	SGT(){
		maxn=50000;
		memset(tree,0x3f,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	inline void pushup(register int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void pushdown(register int now){
		tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	inline void tree_add(register int now,register int nowl,register int nowr,register int lt,register int rt,register int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		register int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_add(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_add(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	inline void add(register int l,register int r,register int val){
		tree_add(1,1,n,l+1,r+1,val);
		return;
	}
	inline void tree_upd(register int now,register int nowl,register int nowr,register int pos,register int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl==nowr){
			tree[now]=val;
			return;
		}
		register int mid=(nowl+nowr)/2;
		if (pos<=mid)tree_upd(now*2,nowl,mid,pos,val);
		else tree_upd(now*2+1,mid+1,nowr,pos,val);
		pushup(now);
		return;
	}
	inline void upd(register int pos,register int val){
		tree_upd(1,1,n,pos+1,val);
		return;
	}
	inline int tree_ask(register int now,register int nowl,register int nowr,register int lt,register int rt){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		register int mid=(nowl+nowr)/2,s=1e9;
		if (mid>=lt)s=min(s,tree_ask(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=min(s,tree_ask(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	inline int ask(register int l,register int r){
		return tree_ask(1,1,n,l+1,r+1);
	}
}sgt[105];
int main(){
	cin>>n>>k;
	for (register int i=1;i<=n;i++)scanf("%d",&a[i]);
	sgt[0].upd(0,0);
	for (register int i=1;i<=n;i++){
		if (s[a[i]]==0)s[a[i]]=e[a[i]]=i;
		else{
			for (register int j=1;j<=k;j++)sgt[j-1].add(0,e[a[i]]-1,i-e[a[i]]);
			e[a[i]]=i;
		}
		for (register int j=1;j<=k;j++){
			f[i][j]=sgt[j-1].ask(0,i-1);
			sgt[j].upd(i,f[i][j]);
		}
	}
	cout<<f[n][k]<<endl;
	return 0;
}