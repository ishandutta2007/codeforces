//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define N 200100
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int n,tt,st[N],g[N][2],h[N][2],du[N],c[N<<1][2],a[N],tot1,tot2,tot3,k1[N],k2[N],p,tot,k3[N];

int solve(int p, int op, int pr)
{
	if(g[p][op])return h[p][op];
	g[p][op]=1;
	int d=du[p]-(p>1);
	if(!d){
		if(!op){
			return h[p][op]=1;
		}
		return 0;
	}
	for(int o=a[p]; o; o=c[o][1]){
		if(c[o][0]==pr)continue;
		solve(c[o][0],0,p);
		solve(c[o][0],1,p);
	}
	tot1=tot2=tot3=0;
	for(int o=a[p]; o; o=c[o][1]){
		if(c[o][0]==pr)continue;
		int u=c[o][0];
		if(!h[u][0]&&!h[u][1]){
			puts("NO");
			exit(0);
		}
		if(!h[u][0]){
			k2[++tot2]=u;
		}else{
			if(!h[u][1]){
				k1[++tot1]=u;
			}else {
				k3[++tot3]=u;
			}
		}
	}
	if(tot3)
		return h[p][op]=1;
	d-=tot2;
	if((d&1)==op)return h[p][op]=1;else return h[p][op]=0;
}

void dfs(int p, int op, int pr)
{
	int d=du[p]-(p>1);
	if(!d){
		st[++tt]=p;
		return;
	}
//zhan// a[n] //N
//    int t=0;
    int t=0;
    for(int o=a[p]; o; o=c[o][1]){
		if(c[o][0]==pr)continue;
		int u=c[o][0];
		if(!h[u][0]){
			dfs(c[o][0],1,p);
			--d;
		}else if(h[u][1])t=u;
	}
	if((d&1)==op){
		st[++tt]=p;
		for(int o=a[p]; o; o=c[o][1]){
			if(c[o][0]==pr)continue;
		    int u=c[o][0];//
		    if(h[u][0])dfs(u,0,p);
		}
		return; 
	}
	dfs(t,1,p);
	st[++tt]=p;
	for(int o=a[p]; o; o=c[o][1]){
			if(c[o][0]==pr||c[o][0]==t)continue;
		    int u=c[o][0];
		    if(h[u][0])dfs(u,0,p);
		}
}

int main()
{
	n=read();
	for(int i=1; i<=n; ++i){
		p=read();
		if(p){
			c[++tot][0]=i; c[tot][1]=a[p]; a[p]=tot; 
			c[++tot][0]=p; c[tot][1]=a[i]; a[i]=tot;
			++du[p]; ++du[i]; 
		}
	}
	if(!solve(1,0,0))
	{
		puts("NO");
		exit(0);
	}
	puts("YES");
	dfs(1,0,0);
	for(int i=1; i<=tt; ++i)
	printf("%d\n",st[i]); 
}