#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n,m,q;
namespace EX_SAM{
	struct sam_node{
		int son[26],len,link;
		sam_node(){
			memset(son,0,sizeof(son));
			len=0,link=-1;
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
	}trie[100005];
	int trie_cnt,pos[100005];
	string s[100005];
	int q[100005],head,tail;
	struct tree_node{
		int l,r,val;
		tree_node(){
			l=r=val=0;
			return;
		}
	}tree[7200005];
	int tree_cnt,root[200005];
	int merge(int x,int y,int nowl,int nowr){
		int z=++tree_cnt;
		if (x==0){
			tree[z]=tree[y];
			return z;
		}
		if (y==0){
			tree[z]=tree[x];
			return z;
		}
		if (nowl==nowr){
			tree[z].val=tree[x].val+tree[y].val;
			return z;
		}
		int mid=(nowl+nowr)/2;
		tree[z].l=merge(tree[x].l,tree[y].l,nowl,mid);
		tree[z].r=merge(tree[x].r,tree[y].r,mid+1,nowr);
		tree[z].val=tree[tree[z].l].val+tree[tree[z].r].val;
		return z;
	}
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
	int tree_ask(int now,int nowl,int nowr,int lt,int rt){
		if (now==0)return 0;
		if (nowl>=lt&&nowr<=rt)return tree[now].val;
		int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s+=tree_ask(tree[now].l,nowl,mid,lt,rt);
		if (mid+1<=rt)s+=tree_ask(tree[now].r,mid+1,nowr,lt,rt);
		return s;
	}
	vector<int> id[200005],e[200005];
	void dfs(int now){
		for (int i=0;i<(int)e[now].size();i++){
			dfs(e[now][i]);
			root[now]=merge(root[now],root[e[now][i]],1,m);
		}
		for (int i=0;i<(int)id[now].size();i++)ins(root[now],1,m,id[now][i]);
		return;
	}
	void init(){
		for (int i=1;i<=m;i++){
			cin>>s[i];
			int now=0;
			for (int j=0;j<(int)s[i].size();j++){
				if (trie[now].son[s[i][j]-'a']==0)trie[now].son[s[i][j]-'a']=++trie_cnt;
				now=trie[now].son[s[i][j]-'a'];
			}
		}
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
		for (int i=1;i<=m;i++){
			int now=0;
			for (int j=0;j<(int)s[i].size();j++){
				now=trie[now].son[s[i][j]-'a'];
				id[pos[now]].push_back(i);
			}
		}
		for (int i=1;i<=sam_cnt;i++)e[sam[i].link].push_back(i);
		dfs(0);
		return;
	}
	int ask(int id,int l,int r){
		return tree_ask(root[id],1,m,l,r);
	}
}
namespace TREE{
	int u[200005],v[200005],first[100005],nxt[200005];
	char w[200005];
	int fa[100005],depth[100005],sz[100005],son[100005],top[100005],idx,dfn[100005],dfo[100005];
	char s[100005];
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
		for (int i=first[now];i;i=nxt[i])
			if (v[i]==son[now]){
				dfs2(v[i],now,t);
				s[dfn[v[i]]]=w[i];
			}
		for (int i=first[now];i;i=nxt[i])
			if (v[i]!=f&&v[i]!=son[now]){
				dfs2(v[i],now,v[i]);
				s[dfn[v[i]]]=w[i];
			}
		dfo[now]=idx;
		return;
	}
	void init(){
		for (int i=1;i<n;i++){
			cin>>u[i]>>v[i]>>w[i];
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		s[1]='a';
		dfs1(1,0,1);
		dfs2(1,0,1);
		return;
	}
	int lca(int a,int b){
		while(top[a]!=top[b]){
			if (depth[top[a]]<depth[top[b]])swap(a,b);
			a=fa[top[a]];
		}
		if (depth[a]>depth[b])swap(a,b);
		return a;
	}
}
namespace DAG{
	ll f[200005],g[200005];
	int id[200005];
	bool cmp(int a,int b){
		return EX_SAM::sam[a].len<EX_SAM::sam[b].len;
	}
	int idx,dfn[200005],nfd[200005],bot[200005];
	char s[200005];
	void dfs(int now){
		dfn[now]=++idx;
		nfd[idx]=now;
		int c=-1,qwq;
		for (int i=0;i<26;i++){
			int v=EX_SAM::sam[now].son[i];
			if (v==0)continue;
			if (g[v]*2>g[now]&&f[now]*2>f[v]&&dfn[v]==0)c=v,qwq=i;
		}
		if (c==-1)bot[now]=idx;
		else{
			dfs(c);
			s[dfn[c]]=qwq+'a';
			bot[now]=bot[c];
		}
		for (int i=0;i<26;i++){
			int v=EX_SAM::sam[now].son[i];
			if (v==0||v==c||dfn[v]!=0)continue;
			dfs(v);
			s[dfn[v]]=i+'a';
		}
		return;
	}
	void init(){
		for (int i=0;i<=EX_SAM::sam_cnt;i++)id[i]=i;
		sort(id,id+EX_SAM::sam_cnt+1);
		f[0]=1;
		for (int i=0;i<=EX_SAM::sam_cnt;i++){
			int now=id[i];
			for (int j=0;j<26;j++)
				if (EX_SAM::sam[now].son[j]!=0)f[EX_SAM::sam[now].son[j]]+=f[now];
		}
		for (int i=EX_SAM::sam_cnt;i>=0;i--){
			int now=id[i];
			g[now]=1;
			for (int j=0;j<26;j++)
				if (EX_SAM::sam[now].son[j]!=0)g[now]+=g[EX_SAM::sam[now].son[j]];
		}
		for (int i=1;i<=EX_SAM::sam_cnt+1;i++)s[i]='a';
		dfs(0);
		return;
	}
}
namespace LCP{
	int n,m;
	struct sam_node{
		int son[26],len,link;
		sam_node(){
			memset(son,0,sizeof(son));
			len=0,link=-1;
		}
	}sam[400005];
	char s1[400005],s2[400005];
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
		sam[now].link=sam[q].link=clone;
		while(p!=-1&&sam[p].son[x]==q){
			sam[p].son[x]=clone;
			p=sam[p].link;
		}
		return now;
	}
	int pos[400005],pre[400005],pre_len[400005],suf[400005],suf_len[400005];
	int u[400005],v[400005],first[400005],nxt[400005];
	int fa[400005],depth[400005],sz[400005],son[400005],top[400005],idx,dfn[400005],dfo[400005];
	void dfs1(int now,int f,int d){
		fa[now]=f,depth[now]=d;
		sz[now]=1;
		son[now]=-1;
		for (int i=first[now];i;i=nxt[i])
			if (v[i]!=f){
				dfs1(v[i],now,d+1);
				sz[now]+=sz[v[i]];
				if (son[now]==-1||sz[v[i]]>sz[son[now]])son[now]=v[i];
			}
		return;
	}
	void dfs2(int now,int f,int t){
		top[now]=t;
		dfn[now]=++idx;
		if (son[now]!=0)dfs2(son[now],now,t);
		for (int i=first[now];i;i=nxt[i])
			if (v[i]!=f&&v[i]!=son[now])dfs2(v[i],now,v[i]);
		dfo[now]=idx;
		return;
	}
	int lca(int a,int b){
		while(top[a]!=top[b]){
			if (depth[top[a]]<depth[top[b]])swap(a,b);
			a=fa[top[a]];
		}
		if (depth[a]>depth[b])swap(a,b);
		return a;
	}
	void init(){
		for (int i=n;i>=1;i--)pos[i]=sam_ins(s1[i]-'a',pos[i+1]);
		for (int i=1;i<=sam_cnt;i++){
			u[i]=sam[i].link,v[i]=i;
			nxt[i]=first[u[i]],first[u[i]]=i;
		}
		dfs1(0,-1,1);
		dfs2(0,-1,0);
		int now=0,nowlen=0;
		for (int i=1;i<=m;i++){
			while(now!=-1&&sam[now].son[s2[i]-'a']==0)now=sam[now].link,nowlen=sam[now].len;
			if (now!=-1)now=sam[now].son[s2[i]-'a'],nowlen++;
			else now=0,nowlen=0;
			pre[i]=now,pre_len[i]=nowlen;
		}
		now=0,nowlen=0;
		for (int i=m;i>=1;i--){
			while(now!=-1&&sam[now].son[s2[i]-'a']==0)now=sam[now].link,nowlen=sam[now].len;
			if (now!=-1)now=sam[now].son[s2[i]-'a'],nowlen++;
			else now=0,nowlen=0;
			suf[i]=now,suf_len[i]=nowlen;
		}
		return;
	}
	int lcp(int x,int y){
		return min(suf_len[y],sam[lca(pos[x],suf[y])].len);
	}
	int lcs(int x,int y){
		return min(pre_len[y],sam[lca(pos[x],pre[y])].len);
	}
}
int tot,l[100005],r[100005];
int find(int x,int y){
	int z=TREE::lca(x,y);
	tot=0;
	while(TREE::top[x]!=TREE::top[z]){
		++tot;
		l[tot]=TREE::dfn[x];
		r[tot]=TREE::dfn[TREE::top[x]];
		x=TREE::fa[TREE::top[x]];
	}
	if (x!=z){
		++tot;
		l[tot]=TREE::dfn[x];
		r[tot]=1+TREE::dfn[z];
	}
	int _tot=tot;
	while(TREE::top[y]!=TREE::top[z]){
		++tot;
		l[tot]=TREE::dfn[TREE::top[y]];
		r[tot]=TREE::dfn[y];
		y=TREE::fa[TREE::top[y]];
	}
	if (y!=z){
		++tot;
		l[tot]=1+TREE::dfn[z];
		r[tot]=TREE::dfn[y];
	}
	for (int i=_tot+1,j=tot;i<j;i++,j--)
		swap(l[i],l[j]),swap(r[i],r[j]);
	int now=0;
	for (int i=1;i<=tot;i++){
		int x=l[i],y=r[i];
		if (l[i]<=r[i]){
			while(x<=y){
				int len=min(min(y-x+1,DAG::bot[now]-DAG::dfn[now]),LCP::lcp(DAG::dfn[now]+1,x));
				if (len==0){
					if (EX_SAM::sam[now].son[TREE::s[x]-'a']==0)return -1;
					now=EX_SAM::sam[now].son[TREE::s[x]-'a'];
					x++;
				}
				else{
					x+=len;
					now=DAG::nfd[DAG::dfn[now]+len];
				}
			}
		}
		else{
			while(x>=y){
				int len=min(min(x-y+1,DAG::bot[now]-DAG::dfn[now]),LCP::lcs(DAG::dfn[now]+1,x));
				if (len==0){
					if (EX_SAM::sam[now].son[TREE::s[x]-'a']==0)return -1;
					now=EX_SAM::sam[now].son[TREE::s[x]-'a'];
					x--;
				}
				else{
					x-=len;
					now=DAG::nfd[DAG::dfn[now]+len];
				}
			}
		}
	}
	return now;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	TREE::init();
	EX_SAM::init();
	DAG::init();
	LCP::n=EX_SAM::sam_cnt+1,LCP::m=n;
	for (int i=1;i<=LCP::n;i++)LCP::s1[i]=DAG::s[i];
	for (int i=1;i<=LCP::m;i++)LCP::s2[i]=TREE::s[i];
	LCP::init();
	while(q--){
		int x,y,l,r;
		cin>>x>>y>>l>>r;
		int p=find(x,y);
		if (p!=-1)cout<<EX_SAM::ask(p,l,r)<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
//mod zjf