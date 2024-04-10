#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct BIT{
	int tree[200005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=200000;
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
}bit;
int n,k,l[200005],r[200005];
char s[200005];
int fa[200005],depth[200005],tot,id[200005],idx,dfn[200005],dfo[200005];
int len,c[200005];
int isd[200005],isr[200005];
void add(int pos){
	bit.add(dfn[pos],1);
	bit.add(dfo[pos]+1,-1);
	return;
}
int ask(int pos){
	return depth[pos]-bit.ask(dfn[pos]);
}
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
void dfs(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	++idx;
	dfn[now]=idx;
	if (l[now]!=0)dfs(l[now],now,d+1);
	id[++tot]=now;
	if (r[now]!=0)dfs(r[now],now,d+1);
	dfo[now]=idx;
	return;
}
void del(int now){
	if (isr[now]==1)return;
	if (isd[now]==1)return;
	isd[now]=1;
	if (l[now]!=0)del(l[now]);
	if (r[now]!=0)del(r[now]);
	return;
}
void work(int now){
	while(now!=0&&isr[now]==0)isr[now]=1,k--,add(now),now=fa[now];
	return;
}
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	dfs(1,0,1);
	for (int i=1;i<=n;i++){
		int now=id[i];
		if (len==0||s[now]==s[c[len]])c[++len]=now;
		else if (s[now]<s[c[len]]){
			sort(c+1,c+1+len,cmp);
			for (int i=1;i<=len;i++)
				if (isr[c[i]]==0)del(c[i]);
			len=0;
			c[++len]=now;
		}
		else if (s[now]>s[c[len]]){
			sort(c+1,c+1+len,cmp);
			for (int i=1;i<=len;i++)
				if (isd[c[i]]==0&&ask(c[i])<=k)work(c[i]);
			len=0;
			c[++len]=now;
		}
	}
	for (int i=1;i<=tot;i++){
		int now=id[i];
		putchar(s[now]);
		if (isr[now])putchar(s[now]);
	}
	puts("");
	return 0;
}