#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
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
	int ask(int l,int r){
		int ans=0;
		while(r)ans+=tree[r],r-=lowbit(r);
		l--;
		while(l)ans-=tree[l],l-=lowbit(l);
		return ans;
	}
}bit;
int n,u[400005],v[400005],first[200005],nxt[400005];
int fa[200005],depth[200005],sz[200005],son[200005],top[200005],idx,dfn[200005],nfd[200005],dfo[200005];
int opt,x,cnt,book[200005];
int c[200005],tot;
int tree[1000005][2],tag[1000005];
ll trees[1000005];
int son_id[200005],fa_id[200005];
ll s[1000005];
ll sum;
int getsz(int x){
	return bit.ask(dfn[x],dfo[x]);
}
int wid(int x){
	if (x<n)return x;
	return x-n;
}
void dfs1(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	sz[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		fa_id[v[i]]=wid(i);
		dfs1(v[i],now,d+1);
		if (sz[v[i]]>sz[son[now]])son[now]=v[i],son_id[now]=wid(i);
		sz[now]+=sz[v[i]];
	}
	return;
}
void dfs2(int now,int f,int t){
	top[now]=t;
	++idx;
	dfn[now]=idx;
	nfd[idx]=now;
	if (son[now])dfs2(son[now],now,t);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f&&v[i]!=son[now])dfs2(v[i],now,v[i]);
	dfo[now]=idx;
	return;
}
void dfs3(int now,int f){
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		if (getsz(v[i])%2==1)c[++tot]=wid(i);
		dfs3(v[i],now);
	}
	return;
}
void pushdown(int now){
	if (tag[now]==0)return;
	tag[now*2]^=1,tag[now*2+1]^=1;
	trees[now*2]=s[now*2]-trees[now*2];
	trees[now*2+1]=s[now*2+1]-trees[now*2+1]; 
	swap(tree[now*2][0],tree[now*2][1]);
	swap(tree[now*2+1][0],tree[now*2+1][1]);
	tag[now]=0;
	return;
}
void pushup(int now){
	tree[now][0]=max(tree[now*2][0],tree[now*2+1][0]);
	tree[now][1]=max(tree[now*2][1],tree[now*2+1][1]);
	trees[now]=trees[now*2]+trees[now*2+1];
	return;
}
void build(int now,int nowl,int nowr){
	if (nowl==nowr){
		s[now]=son_id[nfd[nowl]];
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	s[now]=s[now*2]+s[now*2+1];
	return;
}
void upd(int now,int nowl,int nowr,int lt,int rt){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		trees[now]=s[now]-trees[now];
		swap(tree[now][0],tree[now][1]);
		tag[now]^=1;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)upd(now*2,nowl,mid,lt,rt);
	if (mid+1<=rt)upd(now*2+1,mid+1,nowr,lt,rt);
	pushup(now);
	return;
}
void add(int now,int nowl,int nowr,int pos,int qwq,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr){
		tree[now][qwq]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)add(now*2,nowl,mid,pos,qwq,val);
	else add(now*2+1,mid+1,nowr,pos,qwq,val);
	pushup(now);
	return;
}
void work(int x){
	while(x){
		if (x!=top[x])upd(1,1,n,dfn[top[x]],dfn[fa[x]]);
		x=top[x];
		if (fa[x]!=0){
			int fg;
			if (getsz(x)%2==1)fg=1;
			else fg=-1;
			sum+=fg*fa_id[x];
			if (getsz(son[fa[x]])%2==1)add(1,1,n,dfn[fa[x]],1,fg);
			else add(1,1,n,dfn[fa[x]],0,fg);
		}
		x=fa[x];
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	bit.add(dfn[1],1);
	cnt++;
	book[1]=1;
	build(1,1,n);
	while(1){
		int opt,x;
		cin>>opt;
		if (opt==1){
			cin>>x;
			bit.add(dfn[x],1);
			cnt++;
			work(x);
			book[x]=1;
			if (tree[1][0]<=1&&tree[1][1]==0&&cnt%2==0)cout<<trees[1]+sum<<endl;
			else cout<<0<<endl;
		}
		if (opt==2){
			if (tree[1][0]<=1&&tree[1][1]==0&&cnt%2==0){
				cout<<cnt/2<<' ';
				tot=0;
				dfs3(1,0);
				sort(c+1,c+1+tot);
				for (int i=1;i<=tot;i++)cout<<c[i]<<' ';
				cout<<endl;
			}
			else cout<<0<<endl;
		}
		if (opt==3)return 0;
		fflush(stdout);
	}
	return 0;
}