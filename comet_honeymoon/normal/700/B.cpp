#include<bits/stdc++.h>
using namespace std;

const int maxN=200005;
int N,K;
bool flg[maxN];
int lnk[maxN];
int pre[maxN<<1],tgt[maxN<<1],cnt;
void add_E(int u,int v){
	pre[++cnt]=lnk[u],tgt[cnt]=v,lnk[u]=cnt;
}

long long ans;
int siz[maxN];
void dfs(int x,int f){
	siz[x]=flg[x];
	for(int e=lnk[x];e;e=pre[e]) if(tgt[e]!=f)
		dfs(tgt[e],x),ans+=min(siz[tgt[e]],K-siz[tgt[e]]),siz[x]+=siz[tgt[e]];
}

int main(){
	scanf("%d%d",&N,&K);K*=2;
	for(int i=1;i<=K;i++){int x;scanf("%d",&x);flg[x]=1;}
	for(int i=1;i<N;i++){int u,v;scanf("%d%d",&u,&v);add_E(u,v);add_E(v,u);}
	dfs(1,0);
	printf("%lld\n",ans);
}