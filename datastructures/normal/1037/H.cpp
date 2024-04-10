#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct sam_node{
	int son[26],len,link;
	sam_node(){
		memset(son,0,sizeof(son));
		len=0,link=-1;
		return;
	}
}sam[500005];
int sam_cnt,last;
void sam_ins(char x){
	int now=++sam_cnt;
	sam[now].len=sam[last].len+1;
	int p=last;
	while(p!=-1&&sam[p].son[x-'a']==0){
		sam[p].son[x-'a']=now;
		p=sam[p].link;
	}
	if (p==-1){
		sam[now].link=0;
		last=now;
		return;
	}
	int q=sam[p].son[x-'a'];
	if (sam[q].len==sam[p].len+1){
		sam[now].link=q;
		last=now;
		return;
	}
	int clone=++sam_cnt;
	sam[clone]=sam[q];
	sam[clone].len=sam[p].len+1;
	sam[now].link=sam[q].link=clone;
	while(p!=-1&&sam[p].son[x-'a']==q){
		sam[p].son[x-'a']=clone;
		p=sam[p].link;
	}
	last=now;
	return;
}
struct tree_node{
	int l,r,val;
	tree_node(){
		l=r=val=0;
		return;
	}
}tree[20000005];
int tree_cnt;
int root[500005];
void ins(int &now,int nowl,int nowr,int pos){
	int pre=now;
	now=++tree_cnt;
	tree[now]=tree[pre];
	tree[now].val++;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)ins(tree[now].l,nowl,mid,pos);
	else ins(tree[now].r,mid+1,nowr,pos);
	return;
}
int ask(int now,int nowl,int nowr,int lt,int rt){
	if (now==0)return 0;
	if (nowl>=lt&&nowr<=rt)return tree[now].val;
	int mid=(nowl+nowr)/2,s=0;
	if (mid>=lt)s+=ask(tree[now].l,nowl,mid,lt,rt);
	if (mid+1<=rt)s+=ask(tree[now].r,mid+1,nowr,lt,rt);
	return s;
}
int merge(int x,int y,int nowl,int nowr){
	if (x==0)return y;
	if (y==0)return x;
	if (nowl==nowr){
		int z=++tree_cnt;
		tree[z].val=tree[x].val+tree[y].val;
		return z;
	}
	int mid=(nowl+nowr)/2;
	int z=++tree_cnt;
	tree[z].l=merge(tree[x].l,tree[y].l,nowl,mid);
	tree[z].r=merge(tree[x].r,tree[y].r,mid+1,nowr);
	tree[z].val=tree[tree[z].l].val+tree[tree[z].r].val;
	return z;
}
int n,q,l,r;
char s[500005],t[500005];
int pos[500005];
vector<int> e[500005];
void dfs(int now){
	for (int i=0;i<(int)e[now].size();i++){
		dfs(e[now][i]);
		root[now]=merge(root[now],root[e[now][i]],1,n);
	}
	if (pos[now]!=0)ins(root[now],1,n,pos[now]);
	return;
}
int qwq[500005];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		sam_ins(s[i]);
		pos[last]=i;
	}
	for (int i=1;i<=sam_cnt;i++)e[sam[i].link].push_back(i);
	dfs(0);
	cin>>q;
	while(q--){
		scanf("%d%d",&l,&r);
		scanf("%s",t+1);
		int m=strlen(t+1);
		m++;
		t[m]='a'-1;
		int now=0;
		for (int i=1;i<=m;i++)qwq[i]=-1;
		for (int i=1;i<=m;i++){
			qwq[i]=now;
			now=sam[now].son[t[i]-'a'];
			if (now==0)break;
		}
		int fg=0;
		for (int i=m;i>=1;i--){
			if (qwq[i]==-1)continue;
			int id=-1;
			for (int j=t[i]-'a'+1;j<26;j++){
				if (sam[qwq[i]].son[j]==0)continue;
				int awa=sam[qwq[i]].son[j];
				if (l+i-1<=r&&ask(root[awa],1,n,l+i-1,r)>0){
					id=j;
					break;
				}
			}
			if (id!=-1){
				for (int j=1;j<i;j++)putchar(t[j]);
				putchar('a'+id);
				puts("");
				fg=1;
				break; 
			}
		}
		if (fg==0)puts("-1");
	}
	return 0;
}