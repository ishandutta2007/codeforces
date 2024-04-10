#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int n,m,k,s,t,d,w;
int val[100005],nxt[100005],f[100005][205];
int tree[400005],tag[400005];
inline void pushdown(int now){
	tree[now*2]=max(tree[now*2],tag[now]);
	tree[now*2+1]=max(tree[now*2+1],tag[now]);
	tag[now*2]=max(tag[now*2],tag[now]);
	tag[now*2+1]=max(tag[now*2+1],tag[now]);
	tag[now]=0;
	return;
}
inline void pushup(int now){
	tree[now]=max(tree[now*2],tree[now*2+1]);
	return;
}
inline void update(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]=max(tree[now],val);
		tag[now]=max(tag[now],val);
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
inline int query(int now,int nowl,int nowr,int pos){
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr)return tree[now];
	int mid=(nowl+nowr)/2;
	if (pos<=mid)return query(now*2,nowl,mid,pos);
	return query(now*2+1,mid+1,nowr,pos);
}
inline int dfs(int now,int nowm){
	if (now>n)return 0;
	if (f[now][nowm]!=-1)return f[now][nowm];
	if (nowm==m)return f[now][nowm]=val[now]+dfs(nxt[now],nowm);
	return f[now][nowm]=min(val[now]+dfs(nxt[now],nowm),dfs(now+1,nowm+1));
}
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++){
		scanf("%lld%lld%lld%lld",&s,&t,&d,&w);
		update(1,1,n,s,t,w*(n+1)+d);
	}
	for (int i=1;i<=n;i++)
		val[i]=query(1,1,n,i)/(n+1),nxt[i]=query(1,1,n,i)%(n+1)+1;
	for (int i=1;i<=n;i++)
		nxt[i]=max(nxt[i],i+1);
	memset(f,-1,sizeof(f));
	cout<<dfs(1,0)<<endl;
	return 0;
}