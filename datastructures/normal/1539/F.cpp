#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define inf 1000000000
using namespace std;
int n;
struct SGT{// add[l,r] askmin[l,r]
	int tree[1000005],tag[1000005];
	SGT(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	inline void mem(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	inline void pushdown(register int now){
		tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	inline void pushup(register int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void tree_upd(register int now,register int nowl,register int nowr,register int lt,register int rt,register int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		register int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_upd(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_upd(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	inline void upd(register int l,register int r,register int val){
		tree_upd(1,1,n,l,r,val);
		return;
	}
	inline int tree_ask(register int now,register int nowl,register int nowr,register int lt,register int rt){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		register int mid=(nowl+nowr)/2,s=inf;
		if (mid>=lt)s=min(s,tree_ask(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=min(s,tree_ask(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	inline int ask(register int l,register int r){
		if (l>r)return 0;
		return tree_ask(1,1,n,l,r);
	}
}pre,suf;
int a[200005],ans[200005];
vector <int>pos[200005];
inline void add(register int pos,register int val){
	pre.upd(pos,n,val);
	suf.upd(1,pos,val);
	return;
}
inline int ask(register int pos){
	register int preval=pre.ask(pos,pos)-min(0,pre.ask(1,pos-1));
	register int sufval=suf.ask(pos,pos)-min(0,suf.ask(pos+1,n));
	register int nowval=pre.ask(pos,pos);
	if (pos>1)nowval-=pre.ask(pos-1,pos-1);
	return preval+sufval-nowval;
}
inline void mem(){
	pre.mem();
	suf.mem();
}
int main(){
	cin>>n;
	for (register int i=1;i<=n;i++)add(i,1);
	for (register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	for (register int i=1;i<=n;i++){
		for (register int j=0,len=pos[i].size();j<len;j++){
			register int now=pos[i][j];
			ans[now]=max(ans[now],ask(now)/2);
		}
		for (register int j=0,len=pos[i].size();j<len;j++){
			register int now=pos[i][j];
			add(now,-2);
		}
	}
	mem();
	for (register int i=1;i<=n;i++)add(i,-1);
	for (register int i=1;i<=n;i++){
		for (register int j=0,len=pos[i].size();j<len;j++){
			register int now=pos[i][j];
			add(now,2);
		}
		for (register int j=0,len=pos[i].size();j<len;j++){
			register int now=pos[i][j];
			ans[now]=max(ans[now],(ask(now)+1)/2-1);
		}
	}
	for (register int i=1;i<=n;i++)printf("%d ",ans[i]);
	puts("");
	return 0;
}