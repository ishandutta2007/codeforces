#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e6+4;
struct edge{
	int v,nxt;
}e[N<<1];
int first[N<<1],cnt=0;
inline void add(int u,int v){
	e[++cnt].v=v;e[cnt].nxt=first[u];first[u]=cnt;
} 
int dfn[N<<1],low[N<<1],vis[N<<1],st[N<<1],scc[N<<1],ans[N],c[2];
int n,m,top,tim,cn,fl,co;
void tarjan(int x){
	dfn[x]=low[x]=++tim;
	vis[x]=1;st[++top]=x;
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		cn++;
		int ncn=0,u;
		do{
			ncn++;u=st[top--];
			scc[u]=cn;vis[u]=0;
		}while(u!=x);
		if(ncn==n)fl=1;
	}
} 
int main(){
	int T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=(n<<1);i++)
			first[i]=dfn[i]=0;
		c[0]=c[1]=cn=fl=cnt=top=tim=0;
		for(int i=1,u,v;i<=m;i++){
			u=read();v=read();
			if(u==v)continue;
			add(u,v);add(v+n,u+n);
		}
		for(int i=1;i<=(n<<1);i++)
			if(!dfn[i])tarjan(i);
		if(fl){puts("No");continue;}
		co=1;
		for(int i=1;i<=n;i++)
			if(scc[i]==1)co=0;
		for(int i=1;i<=n;i++){
			if(scc[i]==scc[i+n]){puts("No");fl=1;break;}
			if(scc[i+co*n]==1){ans[i]=co;c[co]++;}
			else{ans[i]=co^1;c[co^1]++;}
		}
		if(fl){puts("No");continue;}
		puts("Yes");
		printf("%d %d\n",c[0],c[1]);
		for(int i=1;i<=n;i++)
			if(!ans[i])printf("%d ",i);
		puts("");
		for(int i=1;i<=n;i++)
			if(ans[i])printf("%d ",i);
		puts("");
	} 
	return (0-0);
}