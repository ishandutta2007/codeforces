#include <bits/stdc++.h>
using namespace std;
const int N=50005;
int n,q,h[N],a[N];
struct edge{
	int to,next;
}e[N*2];
void addedge(int x,int y){
	static int cnt;
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
int prt[N],dep[N];
struct node{
	int son[2];
	void clear(){son[0]=son[1]=0;}
}tr[N*8];
int tot=1,mx[256];
void insert(int val){
	int x=1;
	for(int i=7;~i;i--){
		int t=val>>i&1;
		if(!tr[x].son[t])tr[tr[x].son[t]=++tot].clear();
		x=tr[x].son[t];
	}
}
int ask(int val){
	int x=1,ret=0,tmp=0;
	for(int i=7;~i;i--){
		int t=(val>>i&1)^1;
		if(tr[x].son[t])ret|=1<<i,x=tr[x].son[t],tmp|=t<<i;
		else x=tr[x].son[t^1],tmp|=(t^1)<<i;
	}
	return ret<<8|mx[tmp];
}
int f[N][256],nxt[N];
void dfs(int x,int fa){
	prt[x]=fa;dep[x]=dep[fa]+1;
	if(dep[x]>=256){
		tot=1;tr[1].clear();
		memset(mx,0,sizeof(mx));
		for(int j=0,i=x;j<256;j++,i=prt[i]){
			int val=(dep[x]-dep[i])^a[i];
			mx[val>>8]=max(mx[val>>8],val&255);
			insert(val>>8);
			if(j==255)nxt[x]=prt[i];
		}
		for(int i=0;i<256;i++)f[x][i]=ask(i);
	}
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		dfs(y,x);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);addedge(y,x);
	}
	dfs(1,0);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=0,now=y;
		for(int tmp=0;dep[now]-255>=dep[x];now=nxt[now]){
			ans=max(ans,f[now][tmp]);tmp++;
		}
		while(dep[now]>=dep[x]){
			ans=max(ans,a[now]^(dep[y]-dep[now]));
			now=prt[now];
		}
		cout<<ans<<"\n";
	}
}