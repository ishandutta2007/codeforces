#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct BIT{
	int tree[200005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=200000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit1,bit2;
int n,m,u[400005],v[400005],first[200005],nxt[400005];
int fa[200005],depth[200005],sz[200005],son[200005],top[200005],idx,dfn[200005],dfo[200005],nfd[200005];
int ord_tot,ord[200005],log_2[400005],mnd[400005][25];
void dfs1(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	sz[now]=1;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f){
			dfs1(v[i],now,d+1);
			sz[now]+=sz[v[i]];
			if (sz[v[i]]>sz[son[now]])son[now]=v[i];
		}
	return;
}
void dfs2(int now,int f,int t){
	top[now]=t;
	dfn[now]=++idx;
	nfd[idx]=now;
	ord[now]=++ord_tot;
	mnd[ord_tot][0]=depth[now];
	if (son[now]!=0){
		dfs2(son[now],now,t);
		++ord_tot;
		mnd[ord_tot][0]=depth[now];
	}
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f&&v[i]!=son[now]){
			dfs2(v[i],now,v[i]);
			++ord_tot;
			mnd[ord_tot][0]=depth[now];
		}
	dfo[now]=idx;
	return;
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if (depth[top[a]]<depth[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if (depth[a]<depth[b])return a;
	return b;
}
int up(int now,int k){
	if (depth[now]<=k)return 1;
	while(k>depth[now]-depth[top[now]]){
		k-=depth[now]-depth[top[now]]+1;
		now=fa[top[now]];
	}
	now=nfd[dfn[now]-k];
	return now;
}
int getmn(int x,int y){
	int l=ord[x],r=ord[y];
	if (l>r)swap(l,r);
	int w=log_2[r-l+1];
	return min(mnd[l][w],mnd[r-(1<<w)+1][w]);
}
int dis(int x,int y){
	return depth[x]+depth[y]-2*getmn(x,y);
}
struct node1{
	int x,y,z;
	node1(){
		x=y=z=0;
		return;
	}
}tree[1000005];
int cnt[200005];
node1 merge(node1 a,node1 b){
	if (a.x==0)return b;
	if (b.x==0)return a;
	node1 ans;
	if (a.z>b.z)ans=a;
	else ans=b;
	int d=dis(a.x,b.x);
	if (d>ans.z)ans.x=a.x,ans.y=b.x,ans.z=d;
	d=dis(a.x,b.y);
	if (d>ans.z)ans.x=a.x,ans.y=b.y,ans.z=d;
	d=dis(a.y,b.x);
	if (d>ans.z)ans.x=a.y,ans.y=b.x,ans.z=d;
	d=dis(a.y,b.y);
	if (d>ans.z)ans.x=a.y,ans.y=b.y,ans.z=d;
	return ans;
}
void upd(int now,int nowl,int nowr,int pos,int val){
	if (nowl==nowr){
		cnt[pos]+=val;
		if (val==1&&cnt[pos]==1)tree[now].x=tree[now].y=nfd[pos],tree[now].z=0;
		if (val==-1&&cnt[pos]==0)tree[now].x=tree[now].y=tree[now].z=0;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)upd(now*2,nowl,mid,pos,val);
	else upd(now*2+1,mid+1,nowr,pos,val);
	tree[now]=merge(tree[now*2],tree[now*2+1]);
	return;
}
node1 ask(int now,int nowl,int nowr,int lt,int rt){
	if (nowl>=lt&&nowr<=rt)return tree[now];
	node1 ans;
	int mid=(nowl+nowr)/2;
	if (mid>=lt)ans=merge(ans,ask(now*2,nowl,mid,lt,rt));
	if (mid+1<=rt)ans=merge(ans,ask(now*2+1,mid+1,nowr,lt,rt));
	return ans;
}
struct node2{
	int id,d;
	bool operator <(const node2 &x)const{
		if (d==x.d)return id<x.id;
		return d<x.d;
	}
	bool operator ==(const node2 &x)const{
		if (id==x.id&&d==x.d)return 1;
		return 0;
	}
};
node2 make_node2(int id,int d){
	node2 ans;
	ans.id=id,ans.d=d;
	return ans;
}
priority_queue<node2> h,del;
int tot,l[200005],r[200005];
int main(){
	cin>>n>>m;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	for (int i=2;i<=ord_tot;i++)log_2[i]=log_2[i/2]+1;
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<=ord_tot;i++)
			mnd[i][j]=min(mnd[i][j-1],mnd[i+(1<<(j-1))][j-1]);
	for (int i=1;i<=m;i++){
		int opt=read();
		if (opt==1){
			int x=read(),y=read();
			int l=lca(x,y);
			h.push(make_node2(l,depth[l]));
			bit1.add(dfn[l],1),bit1.add(dfo[l]+1,-1);
			bit2.add(dfn[x],1),bit2.add(dfn[y],1),bit2.add(dfn[l],-1);
			if (fa[l]!=0)bit2.add(dfn[fa[l]],-1);
			upd(1,1,n,dfn[l],1);
		}
		if (opt==2){
			int x=read(),y=read();
			int l=lca(x,y);
			del.push(make_node2(l,depth[l]));
			bit1.add(dfn[l],-1),bit1.add(dfo[l]+1,1);
			bit2.add(dfn[x],-1),bit2.add(dfn[y],-1),bit2.add(dfn[l],1);
			if (fa[l]!=0)bit2.add(dfn[fa[l]],1);
			upd(1,1,n,dfn[l],-1);
		}
		if (opt==3){
			int d=read();
			while((!del.empty())&&(h.top()==del.top()))h.pop(),del.pop();
			int x=up((h.top()).id,d);
			int y=up(x,d);
			int fg=1;
			if (bit1.ask(dfn[y])!=bit2.ask(dfo[y])-bit2.ask(dfn[y]-1))fg=0;
			int now=x;
			tot=0;
			++tot,l[tot]=n+1,r[tot]=n+1;
			++tot,l[tot]=dfn[now],r[tot]=dfo[now];
			now=fa[now];
			while(now){
				++tot;
				l[tot]=dfn[top[now]],r[tot]=dfn[now];
				now=fa[top[now]];
			}
			node1 qwq;
			for (int i=tot;i>1;i--)
				if (r[i]+1<=l[i-1]-1)qwq=merge(qwq,ask(1,1,n,r[i]+1,l[i-1]-1));
			if (qwq.x!=0&&(dis(x,qwq.x)>d||dis(x,qwq.y)>d))fg=0;
			if (fg==1)puts("Yes");
			else puts("No");
		}
	}
	return 0;
}