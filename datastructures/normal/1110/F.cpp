#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define int long long
#define inf 1000000000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write_num(int x){
	if (x==0)return;
	write_num(x/10);
	putchar(x%10+'0');
	return;
}
void write(int x){
	if (x==0)putchar('0');
	else write_num(x);
	puts("");
	return;
}
struct SGT{
	int tree[2000005],tag[2000005],maxn;
	SGT(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		maxn=500000;
		return;
	}
	void pushup(int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	void pushdown(int now){
		tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	void tree_update(int now,int nowl,int nowr,int lt,int rt,int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	void update(int l,int r,int val){
		tree_update(1,1,maxn,l,r,val);
		return;
	}
	int tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2,s=inf;
		if (mid>=lt)s=min(s,tree_query(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=min(s,tree_query(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	int query(int l,int r){
		return tree_query(1,1,maxn,l,r);
	}
}sgt;
int n,q,u[500005],v[500005],w[500005],first[500005],nxt[500005];
int l[500005],r[500005];
vector<int> ql[500005],qr[500005],qid[500005];
int ans[500005];
void dfs1(int now,int d){
	l[now]=r[now]=now;
	int sonnum=0;
	for (int i=first[now];i;i=nxt[i]){
		dfs1(v[i],d+w[i]);
		r[now]=max(r[now],r[v[i]]);
		sonnum++;
	}
	if (sonnum>0)sgt.update(now,now,inf);
	else sgt.update(now,now,d);
	return;
}
void dfs2(int now){
	for (int i=0,len=ql[now].size();i<len;i++)ans[qid[now][i]]=sgt.query(ql[now][i],qr[now][i]);
	for (int i=first[now];i;i=nxt[i]){
		sgt.update(1,n,w[i]);
		sgt.update(l[v[i]],r[v[i]],-2*w[i]);
		dfs2(v[i]);
		sgt.update(l[v[i]],r[v[i]],2*w[i]);
		sgt.update(1,n,-w[i]);
	}
	return;
}
signed main(){
	cin>>n>>q;
	for (int i=2;i<=n;i++){
		u[i]=read(),w[i]=read();
		v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	for (int i=1;i<=q;i++){
		int x,y,z;
		x=read(),y=read(),z=read();
		ql[x].push_back(y),qr[x].push_back(z),qid[x].push_back(i);
	}
	dfs1(1,0);
	dfs2(1);
	for (int i=1;i<=q;i++)write(ans[i]);
	return 0;
}