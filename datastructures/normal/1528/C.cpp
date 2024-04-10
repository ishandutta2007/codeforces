#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct BIT{
	int tree[3000005],maxn;
	BIT(){
		maxn=300000;
		memset(tree,0,sizeof(tree));
		return;
	}
	inline int lowbit(register int x){
		return x&(-x);
	}
	inline void add(register int pos,register int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int ask(register int l,register int r){
		register int ans=0;
		while(r)ans+=tree[r],r-=lowbit(r);
		l--;
		while(l)ans-=tree[l],l-=lowbit(l);
		return ans;
	}
}bit;
int t,n,u[300005],v[300005],first[300005],nxt[300005];
vector <int>e[300005];
int idx,l[300005],r[300005],fa[300005][25];
int c[300005],ans;
inline void dfs1(register int now,register int f){
	l[now]=++idx,fa[now][0]=f;
	for (register int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs1(v[i],now);
	}
	r[now]=idx;
	return;
}
inline void dfs2(register int now,register int f){
	register int x=now,fg=0;
	for (register int i=20;i>=0;i--)
		if (fa[x][i]!=0&&bit.ask(l[fa[x][i]],r[fa[x][i]])==0)x=fa[x][i];
	x=fa[x][0];
	if (c[x]==1){
		fg=1;
		c[x]=0,bit.add(l[x],-1);
	}
	c[now]=1,bit.add(l[now],1);
	ans=max(ans,bit.ask(1,n));
	for (register int i=0,j=e[now].size();i<j;i++){
		if (e[now][i]==f)continue;
		dfs2(e[now][i],now);
	}
	if (fg==1)c[x]=1,bit.add(l[x],1);
	c[now]=0,bit.add(l[now],-1);
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (register int i=2;i<=n;i++){
			register int x;
			scanf("%d",&x);
			e[x].push_back(i);
		}
		for (register int i=2;i<=n;i++){
			scanf("%d",&u[i]);
			v[i]=i;
			nxt[i]=first[u[i]],first[u[i]]=i;
		}
		idx=ans=0;
		dfs1(1,0);
		dfs2(1,0);
		cout<<ans<<endl;
		for (register int i=1;i<=n;i++){
			for (register int j=0;j<=20;j++)fa[i][j]=0;
			first[i]=nxt[i]=0;
			e[i].clear();
		}
	}
	return 0;
}