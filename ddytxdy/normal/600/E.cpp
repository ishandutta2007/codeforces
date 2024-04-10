#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,c[N],ver[N*2],nxt[N*2],head[N],tot,son[N],sz[N],num[N],st[N],tp;LL sum[N],ans[N];
void Add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x,int ff){
	sz[x]=1;
	for(int i=head[x],y;i;i=nxt[i])if((y=ver[i])!=ff)
		dfs(y,x),sz[x]+=sz[y],sz[y]>sz[son[x]]?son[x]=y:0;
}
set<int>s;
void add(int x,int y){if(!sum[x])s.insert(x);sum[x]+=y;if(!sum[x])s.erase(x);}
void dfs3(int x,int ff){
	add(num[c[x]],-c[x]);add(++num[c[x]],c[x]);st[++tp]=c[x];
	for(int i=head[x],y;i;i=nxt[i])if((y=ver[i])!=ff)dfs3(y,x);
}
void dfs2(int x,int ff){
	for(int i=head[x],y;i;i=nxt[i]){
		if((y=ver[i])==ff||y==son[x])continue;
		dfs2(y,x);
		while(tp){
			int c=st[tp--];
			add(num[c],-c);add(--num[c],c);
		}
	}
	if(son[x])dfs2(son[x],x);
	for(int i=head[x],y;i;i=nxt[i])
		if((y=ver[i])!=ff&&y!=son[x])dfs3(y,x);
	add(num[c[x]],-c[x]);add(++num[c[x]],c[x]);st[++tp]=c[x];
	ans[x]=sum[*--s.end()];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)sum[0]+=i;
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		Add(x,y);Add(y,x);
	}
	dfs(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}