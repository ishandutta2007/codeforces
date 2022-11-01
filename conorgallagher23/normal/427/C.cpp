#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5,M=3e5+5,P=1e9+7,Inf=2e9;
struct Edge{int to,nxt;}e[M];
int n,m,fst[N],tote,w[N],mi[N],cnt[N],dfn[N],low[N],id,st[N],tp,bel[N],tot;
void chkmi(int &x,int y){x=x<y?x:y;}
void adde(int u,int v){e[++tote]=(Edge){v,fst[u]};fst[u]=tote;}
void update(int u,int scc){
	bel[u]=tot;
	if(w[u]<mi[scc])mi[scc]=w[u],cnt[scc]=1;
	else if(w[u]==mi[scc])cnt[scc]++;
}
void tarjan(int u){
	dfn[u]=low[u]=++id;st[++tp]=u;
	for(int i=fst[u],v;i;i=e[i].nxt){
		v=e[i].to;
		if(!dfn[v])tarjan(v),chkmi(low[u],low[v]);
		else if(!bel[v])chkmi(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		tot++;mi[tot]=Inf;
		while(st[tp]!=u)update(st[tp--],tot);
		update(st[tp--],tot);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),adde(u,v);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	LL ansmi=0,ans=1;
	for(int i=1;i<=tot;i++)ansmi+=(LL)mi[i],ans=(LL)ans*cnt[i]%P;
	printf("%lld %lld\n",ansmi,ans);
	return 0;
}