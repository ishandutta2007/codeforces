#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
int n,k;
string t[200005];
struct trie_node{
	int son[26];
	trie_node(){
		memset(son,0,sizeof(son));
		return;
	}
}trie[200005];
int trie_cnt;
void trie_ins(int id){
	int now=0;
	for (int i=0;i<t[id].size();i++){
		if (trie[now].son[t[id][i]-'a']==0)trie[now].son[t[id][i]-'a']=++trie_cnt;
		now=trie[now].son[t[id][i]-'a'];
	}
	return;
}
struct sam_node{
	int son[26];
	int link,len;
	sam_node(){
		memset(son,0,sizeof(son));
		link=-1,len=0;
		return;
	}
}sam[200005];
int sam_cnt;
int sam_ins(int x,int last){
	int now=++sam_cnt;
	sam[now].len=sam[last].len+1;
	int p=last;
	while(p!=-1&&sam[p].son[x]==0){
		sam[p].son[x]=now;
		p=sam[p].link;
	}
	if (p==-1){
		sam[now].link=0;
		return now;
	}
	int q=sam[p].son[x];
	if (sam[q].len==sam[p].len+1){
		sam[now].link=q;
		return now;
	}
	int clone=++sam_cnt;
	sam[clone]=sam[q];
	sam[clone].len=sam[p].len+1;
	sam[q].link=sam[now].link=clone;
	while(p!=-1&&sam[p].son[x]==q){
		sam[p].son[x]=clone;
		p=sam[p].link;
	}
	return now;
}
int pos[200005];
int q[200005],head,tail;
vector<int> e[200005];
vector<int> ins[200005];
int fa[200005][25];
struct tree_node{
	int l,r,cnt;
	tree_node(){
		l=r=cnt=0;
		return;
	}
}tree[6000005];
int tree_cnt;
int root[200005];
int val[200005];
int merge(int x,int y,int nowl,int nowr){
	if (x==0)return y;
	if (y==0)return x;
	int z=++tree_cnt;
	if (nowl==nowr){
		tree[z].cnt=1;
		return z;
	}
	int mid=(nowl+nowr)/2;
	tree[z].l=merge(tree[x].l,tree[y].l,nowl,mid);
	tree[z].r=merge(tree[x].r,tree[y].r,mid+1,nowr);
	tree[z].cnt=tree[tree[z].l].cnt+tree[tree[z].r].cnt;
	return z;
}
void update(int &now,int nowl,int nowr,int pos){
	int pre=now;
	now=++tree_cnt;
	tree[now]=tree[pre];
	if (nowl==nowr){
		tree[now].cnt=1;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)update(tree[now].l,nowl,mid,pos);
	else update(tree[now].r,mid+1,nowr,pos);
	tree[now].cnt=tree[tree[now].l].cnt+tree[tree[now].r].cnt;
	return;
}
void dfs(int now){
	fa[now][0]=sam[now].link;
	for (int i=1;i<=20;i++)
		if (fa[now][i-1]!=-1)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (int i=0;i<e[now].size();i++){
		dfs(e[now][i]);
		root[now]=merge(root[now],root[e[now][i]],1,n);
	}
	for (int i=0;i<ins[now].size();i++)
		update(root[now],1,n,ins[now][i]);
	val[now]=tree[root[now]].cnt;
	return;
}
void build_sam(){
	head=tail=1;
	q[1]=0;
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=0;i<26;i++)
			if (trie[now].son[i]!=0){
				pos[trie[now].son[i]]=sam_ins(i,pos[now]);
				q[++tail]=trie[now].son[i];
			}
	}
	for (int i=1;i<=sam_cnt;i++)e[sam[i].link].push_back(i);
	for (int i=1;i<=n;i++){
		int now=0;
		for (int j=0;j<t[i].size();j++){
			now=trie[now].son[t[i][j]-'a'];
			ins[pos[now]].push_back(i);
		}
	}
	dfs(0);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>t[i];
		trie_ins(i);
	}
	build_sam();
	for (int i=1;i<=n;i++){
		ll ans=0;
		int now=0;
		for (int j=0;j<t[i].size();j++){
			now=trie[now].son[t[i][j]-'a'];
			if (val[pos[now]]>=k){
				ans+=sam[pos[now]].len;
				continue;
			}
			int qwq=pos[now];
			for (int w=20;w>=0;w--)
				if (fa[qwq][w]!=-1&&val[fa[qwq][w]]<k)qwq=fa[qwq][w];
			ans+=sam[sam[qwq].link].len;
		}
		cout<<ans<<' ';
	}
	cout<<endl;
	return 0;
}