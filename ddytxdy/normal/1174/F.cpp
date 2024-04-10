#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,x,y,ver[N*2],nxt[N*2],head[N],tot,zh,s[N],sum,now,d[N],dd,f[N],ss[N];bool vis[N];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
int ask(char c,int x){
	int ret;
	printf("%c %d\n",c,x);cout.flush();
	scanf("%d",&ret);
	return ret;
}
void find(int x){
	printf("! %d\n",x);exit(0);
}
void dfs1(int x,int fa){
	f[x]=fa;ss[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		d[y]=d[x]+1;
		dfs1(y,x);
		ss[x]+=ss[y];
	}
}
void dfs2(int x,int fa){
	s[x]=1;int maxn=0;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(vis[y]||y==fa)continue;
		dfs2(y,x);
		s[x]+=s[y];maxn=max(maxn,s[y]);
	}
	int dat=max(maxn,sum-s[x]);
	if(dat<now)zh=x,now=dat;
}
int dfs3(int x,int fa){
	int ret=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(vis[y]||y==fa)continue;
		ret+=dfs3(y,x);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	x=1;sum=n;
	dfs1(1,0);
	dd=ask('d',1);
	if(!dd)find(1);
	while(1){
		now=1e9;
		sum=dfs3(x,0);
		dfs2(x,0);
		int disy=ask('d',zh);
		if(!disy)find(zh);
		if(d[zh]+disy==dd)vis[zh]=1,x=ask('s',zh);
		else vis[zh]=1,x=f[zh];
	}
	// for(int i=1;i<=)
	return 0;
}