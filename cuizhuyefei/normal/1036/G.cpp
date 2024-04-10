#include<bits/stdc++.h>
#define L(i,u) for(int i=head[u];i;i=nxt[i])
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int N = 2333333;
int n,m,head[N],to[N],nxt[N],edgenum,ind[N],oud[N],dy[N],dfn,a[30];
void add(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
inline int dfs(int u){
	int res=dy[u]?(1<<(dy[u]-1)):0;
	L(i,u)res|=dfs(to[i]);return res;
}
int main(){
	scanf("%d%d",&n,&m);rep(i,1,m){
		int u,v;scanf("%d%d",&u,&v);add(u,v);ind[v]++;oud[u]++;
	}
	rep(i,1,n)if(!oud[i])dy[i]=++dfn;dfn=0;
	rep(i,1,n)if(!ind[i])a[++dfn]=dfs(i);
	rep(s,1,(1<<dfn)-2){
		int cnt=0,num=0;
		rep(i,1,dfn)num+=(s>>i-1)&1,cnt+=(s&a[i])==a[i];
		if(cnt>=num){puts("NO");return 0;}
	}
	puts("YES");return 0;
}