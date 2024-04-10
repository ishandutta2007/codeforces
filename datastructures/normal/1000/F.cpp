#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,m,a[500005],book[500005],to[500005],nxt[500005],ans[500005];
vector <int>c[500005],id[500005];
struct SGT{
	int id[2000005];
	inline void pushup(int now){
		if (nxt[id[now*2+1]]>nxt[id[now*2]])id[now]=id[now*2+1];
		else id[now]=id[now*2];
		return;
	}
	inline void tree_update(int now,int nowl,int nowr,int pos,int val){
		if (nowl==nowr){
			nxt[pos]=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (pos<=mid)tree_update(now*2,nowl,mid,pos,val);
		else tree_update(now*2+1,mid+1,nowr,pos,val);
		pushup(now);
		return;
	}
	inline void update(int pos,int val){
		tree_update(1,1,n,pos,val);
		return;
	}
	inline int tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl>=lt&&nowr<=rt)return id[now];
		int mid=(nowl+nowr)/2,s=0,mx=0;
		if (mid>=lt){
			int nowid=tree_query(now*2,nowl,mid,lt,rt);
			if (nxt[nowid]>mx)mx=nxt[nowid],s=nowid;
		}
		if (mid+1<=rt){
			int nowid=tree_query(now*2+1,mid+1,nowr,lt,rt);
			if (nxt[nowid]>mx)mx=nxt[nowid],s=nowid;
		}
		return s;
	}
	inline int query(int l,int r){
		return tree_query(1,1,n,l,r);
	}
	inline void build(int now,int nowl,int nowr){
		if (nowl==nowr){
			id[now]=nowl;
			return;
		}
		int mid=(nowl+nowr)/2;
		build(now*2,nowl,mid);
		build(now*2+1,mid+1,nowr);
		pushup(now);
		return;
	}
	SGT(){
		memset(id,0,sizeof(id));
		return;
	}
}sgt;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	cin>>m;
	for (int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		c[l].push_back(r),id[l].push_back(i);
	}
	for (int i=1;i<=n;i++)book[i]=n+1;
	for (int i=n;i>=1;i--)to[i]=book[a[i]],book[a[i]]=i;
	sgt.build(1,1,n);
	for (int i=n;i>=1;i--){
		if (to[i]<=n)sgt.update(to[i],0);
		sgt.update(i,to[i]-1);
		for (int j=0,len=c[i].size();j<len;j++){
			int now=sgt.query(i,c[i][j]);
			ans[id[i][j]]=(nxt[now]>=c[i][j])?a[now]:0; 
		}
	}
	for (int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}