#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4,M=5e6+4;
int n,m,d,len,arr[M];
int hd[N],nx[N],to[N];
bool ok[M],ins[M];
int dfn[M],low[M],cmp[M];
int sta[M],SZ,cnt,tot,dp[M];
int tg[M],cur,val[M];
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	sta[++SZ]=x,ins[x]=1; 
	int u=x/d,t=x%d;
	for(int i=hd[u];i;i=nx[i]){
		int y=to[i]*d+(t+1)%d;if(!dfn[y])tarjan(y);
		if(ins[y])low[x]=min(low[x],low[y]);
	}
	if(dfn[x]==low[x]){
		++tot;for(;;){
			int w=sta[SZ--];
			cmp[w]=tot,arr[len++]=w;
			ins[w]=0;if(w==x)break;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		to[i]=--v,nx[i]=hd[--u],hd[u]=i;
	}
	for(int i=0;i<n;i++){
		char buf[55];scanf("%s",buf);
		for(int j=0;j<d;j++)ok[i*d+j]=buf[j]-'0';
	}
	for(int i=0;i<n*d;i++)if(!dfn[i])tarjan(i);
	for(int i=0;i<n;i++){
		++cur;for(int j=0;j<d;j++)if(ok[i*d+j]){
			int p=cmp[i*d+j];
			if(tg[p]!=cur)val[p]++,tg[p]=cur;
		}
	}
	for(int i=1;i<=tot;i++)dp[i]=val[i];
	for(int i=0;i<len;i++){
		int x=arr[i],u=x/d,t=x%d,T=(t+1)%d;
		for(int i=hd[u];i;i=nx[i])if(cmp[to[i]*d+T]!=cmp[x])
			dp[cmp[x]]=max(dp[cmp[to[i]*d+T]]+val[cmp[x]],dp[cmp[x]]);
	}
	printf("%d",dp[cmp[0]]);
}