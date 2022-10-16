#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct BIT{
	int tree[200005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=200000;
		return;
	}
	inline int lowbit(register int x){
		return x&(-x);
	}
	inline void add(register int pos,register int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int ask(register int l,register int r){
		register int ans=0;
		while(r)ans+=tree[r],r-=lowbit(r);
		l--;
		while(l)ans-=tree[l],l-=lowbit(l);
		return ans;
	}
}bit;
struct node{
	int pos,col;
}a[200005];
inline bool cmp(node a,node b){
	return a.col<b.col;
}
int n,u[400005],v[400005],first[400005],nxt[400005];
int fa[200005],l[200005],r[200005],nowid;
inline void dfs(register int now,register int f){
	l[now]=++nowid;
	fa[now]=f;
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs(v[i],now);
	}
	r[now]=nowid;
	return;
}
int ch[200005],ans;
inline void add(register int l,register int r){
	ch[l]++,ch[r+1]--;
	return;
}
inline void upd(register int now,register int val){
	add(l[now],l[now]); 
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==fa[now]){
			if (bit.ask(1,l[now]-1)+bit.ask(r[now]+1,n)!=val-1)
				add(1,l[now]-1),add(r[now]+1,n);
		}
		else{
			if (bit.ask(l[v[i]],r[v[i]])!=val-1)
				add(l[v[i]],r[v[i]]);
		}
	}
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i].col),a[i].pos=i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0);
	for (register int i=1;i<=n;i++){
		int j=i;
		while(j<n&&a[j+1].col==a[i].col)j++;
		if (i==j)continue;
		for (register int k=i;k<=j;k++)
			bit.add(l[a[k].pos],1);
		for (register int k=i;k<=j;k++)
			upd(a[k].pos,j-i+1);
		for (register int k=i;k<=j;k++)
			bit.add(l[a[k].pos],-1);
		i=j;
	}
	for (register int i=1;i<=n;i++)
		ch[i]+=ch[i-1],ans+=(ch[i]==0);
	cout<<ans<<endl;
	return 0;
}