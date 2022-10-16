#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct sam_node{
	int son[26],len,link;
	sam_node(){
		memset(son,0,sizeof(son));
		len=0,link=-1;
		return;
	}
}sam[400005];
int check_tot,check_s[10005];
int sam_cnt,last;
int ins(char x){
	int now=++sam_cnt;
	sam[now].len=sam[last].len+1;
	int p=last;
	while(p!=-1&&sam[p].son[x-'a']==0){
		sam[p].son[x-'a']=now;
		p=sam[p].link;
	}
	if (p==-1){
		sam[now].link=0;
		return now;
	}
	int q=sam[p].son[x-'a'];
	if (sam[q].len==sam[p].len+1){
		sam[now].link=q;
		return now;
	}
	int clone=++sam_cnt;
	sam[clone]=sam[q];
	sam[clone].len=sam[p].len+1;
	sam[now].link=sam[q].link=clone;
	while(p!=-1&&sam[p].son[x-'a']==q){
		sam[p].son[x-'a']=clone;
		p=sam[p].link;
	}
	return now;
}
int n,endpos[400005];
char s[400005];
int u[400005],v[400005],first[400005],nxt[400005];
struct tree_node{
	int l,r,val;
	tree_node(){
		l=r=val=0;
		return;
	}
}tree[24000005];
int tree_cnt,root[400005];
void tree_update(int &now,int nowl,int nowr,int pos){
	int pre=now;
	now=++tree_cnt;
	tree[now]=tree[pre];
	tree[now].val++;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)tree_update(tree[now].l,nowl,mid,pos);
	else tree_update(tree[now].r,mid+1,nowr,pos);
	return;
}
void update(int &now,int pos){
	tree_update(now,1,sam_cnt,pos);
	return;
}
int tree_query(int now,int nowl,int nowr,int lt,int rt){
	if (now==0)return 0;
	if (nowl>=lt&&nowr<=rt)return tree[now].val;
	int mid=(nowl+nowr)/2,s=0;
	if (mid>=lt)s+=tree_query(tree[now].l,nowl,mid,lt,rt);
	if (mid+1<=rt)s+=tree_query(tree[now].r,mid+1,nowr,lt,rt);
	return s;
}
int query(int now,int l,int r){
	return tree_query(now,1,sam_cnt,l,r);
}
int tree_merge(int nowl,int nowr,int x,int y){
	if (x==0)return y;
	if (y==0)return x;
	if (nowl==nowr){
		int z=++tree_cnt;
		tree[z].val=tree[x].val+tree[y].val;
		return z;
	}
	int z=++tree_cnt,mid=(nowl+nowr)/2;
	tree[z].val=tree[x].val+tree[y].val;
	tree[z].l=tree_merge(nowl,mid,tree[x].l,tree[y].l);
	tree[z].r=tree_merge(mid+1,nowr,tree[x].r,tree[y].r);
	return z;
}
int merge(int x,int y){
	return tree_merge(1,sam_cnt,x,y);
}
void dfs1(int now){
	for (int i=first[now];i;i=nxt[i])
		dfs1(v[i]),root[now]=merge(root[now],root[v[i]]);
	if (endpos[now]!=-1)update(root[now],endpos[now]);
	return;
}
int f[400005],ans,c[400005],tot,lastpos;
void dfs2(int now){
	if (now==0){
		for (int i=first[now];i;i=nxt[i])
			dfs2(v[i]);
		return;
	}
	int qwqpos=lastpos;
	if (tot>0){
		while(lastpos<tot&&query(root[c[lastpos+1]],endpos[now]-sam[now].len+1+sam[c[lastpos+1]].len-1,endpos[now])>=2)lastpos++;
		f[now]=f[c[lastpos]]+1;
	}
	else f[now]=1;
	ans=max(ans,f[now]);
	c[++tot]=now;
	for (int i=first[now];i;i=nxt[i])
		dfs2(v[i]);
	tot--;
	lastpos=qwqpos;
	return;
}
int main(){
	cin>>n;
	scanf("%s",s+1);
	memset(endpos,-1,sizeof(endpos));
	for (int i=1;i<=n;i++){
		int now=ins(s[i]);
		last=now;
		endpos[now]=i;
	}
	for (int i=1;i<=sam_cnt;i++){
		u[i]=sam[i].link,v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	dfs1(0);
	for (int i=1;i<=sam_cnt;i++){
		int now=i;
		while(sam[now].link!=0&&endpos[now]!=-1&&endpos[sam[now].link]==-1){
			endpos[sam[now].link]=endpos[now];
			now=sam[now].link;
		}
	}
	dfs2(0);
	cout<<ans<<endl;
	return 0;
}