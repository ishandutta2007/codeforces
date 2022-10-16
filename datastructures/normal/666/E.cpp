#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct sam_node{
	int son[26],len,link;
	sam_node(){
		memset(son,0,sizeof(son));
		len=0,link=-1;
		return;
	}
}sam[1200005];
int sam_cnt;
int check_tot;
char check_s[100005];
void check_sam(int now){
	if (check_tot){
		for (int i=1;i<=check_tot;i++)cout<<check_s[i];cout<<endl;
	}
	for (int i=0;i<26;i++){
		if (sam[now].son[i]){
			check_s[++check_tot]='a'+i;
			check_sam(sam[now].son[i]);
			--check_tot;
		}
	}
	return;
}
int sam_ins(int last,int x){
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
	sam[now].link=sam[q].link=clone;
	while(p!=-1&&sam[p].son[x]==q){
		sam[p].son[x]=clone;
		p=sam[p].link;
	}
	return now;
}
struct trie_node{
	int son[26];
	trie_node(){
		memset(son,0,sizeof(son));
		return;
	}
}trie[600005];
int trie_cnt;
void trie_ins(string s){
	int now=0;
	for (int i=0;i<s.size();i++){
		if (trie[now].son[s[i]-'a']==0)trie[now].son[s[i]-'a']=++trie_cnt;
		now=trie[now].son[s[i]-'a'];
	}
	return;
}
int que[600005],head,tail;
int id[1200005];
void build_sam(){
	head=tail=1;
	que[head]=0;
	while(head<=tail){
		int now=que[head];
		head++;
		for (int i=0;i<26;i++)
			if (trie[now].son[i]!=0){
				id[trie[now].son[i]]=sam_ins(id[now],i);
				que[++tail]=trie[now].son[i];
			}
	}
	return;
} 
string s,t[50005];
int n,m,len[50005],q,l,r,pl,pr;
int endpos[500005];
int u[1200005],v[1200005],first[1200005],nxt[1200005],fa[1200005][21];
void get_endpos(){
	int now=0;
	for (int i=0;i<n;i++){
		now=sam[now].son[s[i]-'a'];
		endpos[i+1]=now;
	}
	return;
}
void pre_dfs(int now){
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (int i=first[now];i;i=nxt[i]){
		fa[v[i]][0]=now;
		pre_dfs(v[i]);
	}
	return;
}
void get_parent_tree(){
	for (int i=1;i<=sam_cnt;i++){
		u[i]=sam[i].link,v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	pre_dfs(0);
	return;
}
int up(int now,int len){
	for (int i=20;i>=0;i--)
		if (sam[fa[now][i]].len>=len)now=fa[now][i];
	return now;
}
struct tree_node{
	int l,r,val;
	tree_node(){
		l=r=val=0;
		return;
	}
}tree[10000005];
int tree_cnt,root[1200005];
void pushup(int now){
	tree[now].val=max(tree[tree[now].l].val,tree[tree[now].r].val);
	return;
}
int tree_merge(int nowl,int nowr,int x,int y){
	if (x==0)return y;
	if (y==0)return x;
	if (nowl==nowr){
		int z=++tree_cnt;
		tree[z]=tree[x];
		tree[z].val+=tree[y].val;
		return z;
	}
	int z=++tree_cnt,mid=(nowl+nowr)/2;
	tree[z].l=tree_merge(nowl,mid,tree[x].l,tree[y].l);
	tree[z].r=tree_merge(mid+1,nowr,tree[x].r,tree[y].r);
	pushup(z);
	return z;
}
int merge(int x,int y){
	return tree_merge(1,m,x,y);
}
void tree_add(int &now,int nowl,int nowr,int pos){
	int pre=now;
	now=++tree_cnt;
	tree[now]=tree[pre];
	if (nowl==nowr){
		tree[now].val++;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)tree_add(tree[now].l,nowl,mid,pos);
	else tree_add(tree[now].r,mid+1,nowr,pos);
	pushup(now);
	return;
}
void add(int &now,int pos){
	tree_add(now,1,m,pos);
}
int tree_ask(int now,int nowl,int nowr,int lt,int rt){
	if (nowl>=lt&&nowr<=rt)return tree[now].val;
	int mid=(nowl+nowr)/2,s=0;
	if (mid>=lt)s=max(s,tree_ask(tree[now].l,nowl,mid,lt,rt));
	if (mid+1<=rt)s=max(s,tree_ask(tree[now].r,mid+1,nowr,lt,rt));
	return s;
}
int ask(int now,int l,int r){
	return tree_ask(now,1,m,l,r);
}
vector<int> ins_id[1200005];
void sgt_ins(string s,int id){
	int now=0;
	for (int i=0;i<s.size();i++){
		now=sam[now].son[s[i]-'a'];
		ins_id[now].push_back(id);
	}
	return;
}
void dfs(int now){
	for (int i=first[now];i;i=nxt[i]){
		dfs(v[i]);
		root[now]=merge(root[now],root[v[i]]);
	}
	for (int i=0,len=ins_id[now].size();i<len;i++)add(root[now],ins_id[now][i]);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	n=s.size();
	trie_ins(s);
	cin>>m;
	for (int i=1;i<=m;i++){
		cin>>t[i];
		len[i]=t[i].size();
		trie_ins(t[i]);
	}
	build_sam();
	get_endpos();
	get_parent_tree();
	for (int i=1;i<=m;i++)sgt_ins(t[i],i);
	dfs(0);
	cin>>q;
	while(q--){
		cin>>l>>r>>pl>>pr;
		int now=endpos[pr];
		now=up(now,pr-pl+1);
		int ansid=-1,ansval=0;
		ansval=ask(root[now],l,r);
		int lt=l,rt=r;
		while(lt<=rt){
			int mid=(lt+rt)/2;
			if (ask(root[now],l,mid)==ansval)ansid=mid,rt=mid-1;
			else lt=mid+1;
		}
		printf("%d %d\n",ansid,ansval);
	}
	return 0;
}