#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct sam_node{
	int son[26],len,link;
	sam_node(){
		memset(son,0,sizeof(son));
		len=0,link=-1;
		return;
	}
}sam[2000005];
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
}trie[1000005];
int trie_cnt;
void trie_ins(string x){
	int now=0;
	for (int i=0;i<x.size();i++){
		if (trie[now].son[x[i]-'a']==0)trie[now].son[x[i]-'a']=++trie_cnt;
		now=trie[now].son[x[i]-'a'];
	}
	return;
}
int q[2000005],head,tail,pos[2000005];
vector<int> e[2000005];
int fa[2000005],top[2000005];
void build_sam(){
	head=tail=1;
	q[1]=0;
	while(head<=tail){
		int now=q[head];
		head++;
		for (int i=0;i<26;i++)
			if (trie[now].son[i]){
				pos[trie[now].son[i]]=sam_ins(i,pos[now]);
				q[++tail]=trie[now].son[i];
			}
	}
	for (int i=1;i<=sam_cnt;i++)e[sam[i].link].push_back(i);
	return;
}
int idx,dfn[2000005],dfo[2000005];
void dfs(int now,int f){
	dfn[now]=++idx;
	fa[now]=f;
	if (top[now]==0&&f!=-1)top[now]=top[f];
	for (int i=0;i<e[now].size();i++)dfs(e[now][i],now);
	dfo[now]=idx;
	return;
}
struct BIT{
	int tree[2000005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=2000000;
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
int vis[2000005],book[2000005];
int l[2000005];
struct node{
	int l,id;
	bool operator <(const node &x)const{
		return l<x.l;
	}
};
node make_node(int l,int id){
	node ans;
	ans.l=l,ans.id=id;
	return ans;
}
priority_queue<node> h;
int calc(string t){
	int ans=0;
	int now=0;
	for (int i=0;i<t.size();i++){
		now=sam[now].son[t[i]-'a'];
		int qwq;
		if (i!=t.size()-1)qwq=top[now];
		else qwq=top[fa[now]];
		if (qwq!=0){
			if (vis[qwq]==0){
				ans++;
				bit.add(dfn[qwq],1);
				vis[qwq]=1;
			}
			l[i]=i-sam[qwq].len+1;
		}
	}
	now=0;
	for (int i=0;i<t.size();i++){
		now=sam[now].son[t[i]-'a'];
		int qwq;
		if (i!=t.size()-1)qwq=top[now];
		else qwq=top[fa[now]];
		if (qwq!=0){
			if (bit.ask(dfn[qwq],dfo[qwq])>1){
				if (book[qwq]==0){
					ans--;
					book[qwq]=1;
				}
			}
		}
		if (l[i]!=-1){
			while((!h.empty())&&(h.top()).l>=l[i]){
				if (book[(h.top()).id]==0){
					ans--;
					book[(h.top()).id]=1;
				}
				h.pop();
			}
			h.push(make_node(l[i],qwq));
		}
	}
	while(!h.empty())h.pop();
	now=0;
	for (int i=0;i<t.size();i++){
		now=sam[now].son[t[i]-'a'];
		int qwq;
		if (i!=t.size()-1)qwq=top[now];
		else qwq=top[fa[now]];
		if (qwq!=0){
			if (vis[qwq]==1)bit.add(dfn[qwq],-1);
			vis[qwq]=book[qwq]=0;
			l[i]=-1;
		}
	}
	return ans;
}
int n;
string s[1000005];
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		trie_ins(s[i]);
	}
	build_sam();
	for (int i=1;i<=n;i++){
		int now=0;
		for (int j=0;j<s[i].size();j++)now=sam[now].son[s[i][j]-'a'];
		top[now]=now;
	}
	memset(l,-1,sizeof(l));
	dfs(0,-1);
	for (int i=1;i<=n;i++)ans+=calc(s[i]);
	cout<<ans<<endl;
	return 0;
}