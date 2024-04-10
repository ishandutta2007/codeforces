#include<bits/stdc++.h>
using namespace std;
 
int T;
int N,M;
 
int lnk[1000005];
int pre[1000005],tgt[1000005],cnt;
void add_E(int u,int v){
	pre[++cnt]=lnk[u],tgt[cnt]=v,lnk[u]=cnt;
}
 
int DFN[1000005],LOW[1000005],idx;
int stk[1000005],len,tot;
bool in_stk[1000005];
int clr[1000005];
void Tarjan(int x){
	DFN[x]=LOW[x]=++idx;
	in_stk[x]=1;stk[++len]=x;
	for(int e=lnk[x];e;e=pre[e])
		if(!DFN[tgt[e]]) Tarjan(tgt[e]),LOW[x]=min(LOW[x],LOW[tgt[e]]);
		else if(in_stk[tgt[e]]) LOW[x]=min(LOW[x],DFN[tgt[e]]);
	if(DFN[x]==LOW[x]){
		int y;tot++;do{y=stk[len--];clr[y]=tot;in_stk[y]=0;}while(x!=y);
	}
}
 
int deg[1000005];
 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		while(M--){
			int u,v;scanf("%d%d",&u,&v);
			if(u!=v) add_E(u,v);
		}
		for(int i=1;i<=N;i++) if(!DFN[i]) Tarjan(i);
		if(tot==1){printf("No\n");}
		else{
			printf("Yes\n");
			for(int i=1;i<=N;i++)
			for(int e=lnk[i];e;e=pre[e])
				if(clr[i]!=clr[tgt[e]])
					deg[clr[i]]++;
			int lst=0;
			for(int i=1;i<=tot;i++) if(!deg[i]) lst=i;
			int ans1=0,ans2=0;
			for(int i=1;i<=N;i++) ans1+=(clr[i]==lst),ans2+=(clr[i]!=lst);
			printf("%d %d\n",ans1,N-ans1);
			for(int i=1;i<=N;i++) if(clr[i]==lst) printf("%d ",i);printf("\n");
			for(int i=1;i<=N;i++) if(clr[i]!=lst) printf("%d ",i);printf("\n");
		}
		for(int i=1;i<=N;i++) lnk[i]=0,DFN[i]=LOW[i]=0,deg[i]=0;
		cnt=0;idx=0;tot=0;
	}
}