#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct BIT{
	int tree[1048576],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=1048575;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		pos++;
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int mex(){
		int pos=0;
		for (int i=19;i>=0;i--)
			if (tree[pos+(1<<i)]==(1<<i))pos+=(1<<i);
		return pos;
	}
}bit;
int t,n;
vector<int> e[1000005];
int isroot[1000005],depth[1000005],sz[1000005],son[1000005];
int mnd[1000005],mxd[1000005],sg[1000005],cnt[1000005],vis[1000005],val[1000005];
void dfs1(int now,int d){
	depth[now]=d;
	sz[now]=1;
	if (e[now].size()==0)mnd[now]=d,mxd[now]=d;
	for (int i=0;i<e[now].size();i++){
		dfs1(e[now][i],d+1);
		if (mnd[now]==0)mnd[now]=mnd[e[now][i]],mxd[now]=mxd[e[now][i]];
		else mnd[now]=min(mnd[now],mnd[e[now][i]]),mxd[now]=max(mxd[now],mxd[e[now][i]]);
		sz[now]+=sz[e[now][i]];
		if (sz[e[now][i]]>sz[son[now]])son[now]=e[now][i];
	}
	return;
}
void upd(int now,int mxd){
	if (vis[depth[now]]!=0){
		cnt[val[depth[now]]]--;
		if (cnt[val[depth[now]]]==0)bit.add(val[depth[now]],-1);
	}
	vis[depth[now]]++;
	val[depth[now]]^=sg[now];
	cnt[val[depth[now]]]++;
	if (cnt[val[depth[now]]]==1)bit.add(val[depth[now]],1);
	if (depth[now]<=mxd){
		for (int i=0;i<e[now].size();i++)
			upd(e[now][i],mxd);
	}
	return;
}
void clear(int l,int r){
	for (int i=l;i<=r;i++){
		if (vis[i]==0)continue;
		vis[i]=0;
		cnt[val[i]]--;
		if (cnt[val[i]]==0)bit.add(val[i],-1);
		val[i]=0;
	}
	return;
}
void dfs2(int now,int ish){
	for (int i=0;i<e[now].size();i++)
		if (e[now][i]!=son[now])dfs2(e[now][i],0);
	if (son[now]){
		dfs2(son[now],1);
		if (mnd[son[now]]>mnd[now])clear(mnd[now]+2,mnd[son[now]]+1);
	}
	for (int i=0;i<e[now].size();i++)
		if (e[now][i]!=son[now])upd(e[now][i],mnd[now]);
	int fg=1;
	for (int i=0;i<e[now].size();i++)
		if (mnd[e[now][i]]!=mnd[now])fg=0;
	if (mnd[now]==mxd[now]&&cnt[0]==0)bit.add(0,1);
	sg[now]=bit.mex();
	if (mnd[now]==mxd[now]&&cnt[0]==0)bit.add(0,-1);
	if (vis[depth[now]]!=0){
		cnt[val[depth[now]]]--;
		if (cnt[val[depth[now]]]==0)bit.add(val[depth[now]],-1);
	}
	vis[depth[now]]++;
	val[depth[now]]^=sg[now];
	cnt[val[depth[now]]]++;
	if (cnt[val[depth[now]]]==1)bit.add(val[depth[now]],1);
	if (ish==0)clear(depth[now],mnd[now]+1);
	return;
}
int main(){
	cin>>t;
	while(t--){
		n=read();
		for (int i=1;i<=n;i++){
			int x=read();
			if (x==0)isroot[i]=1;
			if (x!=0)e[x].push_back(i);
		}
		int qwq=0;
		for (int i=1;i<=n;i++)
			if (isroot[i]){
				dfs1(i,1);
				dfs2(i,0);
				qwq^=sg[i];
			}
		if (qwq!=0)puts("YES");
		else puts("NO");
		for (int i=1;i<=n;i++)isroot[i]=son[i]=mnd[i]=mxd[i]=sg[i]=0;
		for (int i=0;i<=n+1;i++)e[i].clear();
	}
	return 0;
}