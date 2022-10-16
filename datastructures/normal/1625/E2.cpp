#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
struct BIT{
	int tree[300005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=300000;
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
int cnt;
int n,q;
char s[300005];
int sta[300005],tot,pre[300005];
int fa[300005],son_num[300005],idx,dfn[300005],dfo[300005],bfs_idx,bfs_id[300005];
int id_l[300005],id_r[300005];
int C2(int n){
	return n*(n-1)/2;
}
void del(int now){
	bit1.add(dfn[now],-1);
	if (fa[now]!=0){
		bit1.add(dfn[fa[now]],-C2(son_num[fa[now]]));
		son_num[fa[now]]--;
		bit1.add(dfn[fa[now]],C2(son_num[fa[now]]));
	}
	bit2.add(bfs_id[now],-1);
	return;
}
int ask1(int l,int r){
	return bit1.ask(r)-bit1.ask(l-1);
}
int ask2(int l,int r){
	return bit2.ask(r)-bit2.ask(l-1);
}
void dfs(int now,int l,int r){
	id_l[l]=now;
	id_r[r]=now;
	++idx;
	dfn[now]=idx;
	int qwq=r-1;
	while(qwq>l){
		while(qwq>l&&s[qwq]!=')')qwq--;
		if (qwq<=l)break;
		++cnt;
		fa[cnt]=now;
		son_num[now]++;
		dfs(cnt,pre[qwq],qwq);
		qwq=pre[qwq]-1;
	}
	qwq=r-1;
	while(qwq>l){
		while(qwq>l&&s[qwq]!=')')qwq--;
		if (qwq<=l)break;
		bfs_id[id_r[qwq]]=++bfs_idx;
		bit2.add(bfs_id[id_r[qwq]],1);
		qwq=pre[qwq]-1;
	} 
	dfo[now]=idx;
	bit1.add(dfn[now],1);
	bit1.add(dfn[now],C2(son_num[now]));
	return;
}
signed main(){
	cin>>n>>q;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (s[i]=='(')sta[++tot]=i;
		if (s[i]==')'){
			if (tot==0)continue;
			pre[i]=sta[tot];
			tot--;
		}
	}
	for (int i=n;i>=1;i--){
		if (pre[i]==0)continue;
		if (id_r[i]!=0)continue;
		++cnt;
		dfs(cnt,pre[i],i);
	}
	for (int i=n;i>=1;i--){
		if (pre[i]==0)continue;
		int id=id_r[i];
		if (bfs_id[id]!=0)continue;
		bfs_id[id]=++bfs_idx;
		bit2.add(bfs_id[id],1);
	}
	while(q--){
		int opt,l,r;
		scanf("%lld%lld%lld",&opt,&l,&r);
		if (opt==1)del(id_l[l]);
		else printf("%lld\n",ask1(dfn[id_r[r]],dfo[id_l[l]])+C2(ask2(bfs_id[id_r[r]],bfs_id[id_l[l]])));
	}
	return 0;
}