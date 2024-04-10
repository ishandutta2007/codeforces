#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 210;

struct node{
    int v, next, use;
}edge[MAXN << 2];

bool bridge[MAXN];
int low[MAXN], dfn[MAXN], vis[MAXN];
int head[MAXN], pre[MAXN], ip, sol, Count,u[MAXN],v[MAXN],n,m,p[MAXN],i,viss[MAXN],s,ans=-1,j,t[MAXN];

void init(void){
    memset(head, -1, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(bridge, false, sizeof(bridge));
    Count = sol = ip = 0;
}

void addedge(int u, int v){
    edge[ip].v = v;
    edge[ip].use = 0;
    edge[ip].next = head[u];
    head[u] = ip++;
}
bool flag;
void tarjan(int u){
    vis[u] = 1;
    dfn[u] = low[u] = Count++;
    for(int i = head[u]; i != -1; i = edge[i].next){
        if(!edge[i].use){
            edge[i].use = edge[i ^ 1].use = 1;
            int v = edge[i].v;
            if(!vis[v]){
                pre[v] = u;
                tarjan(v);
                low[u] = min(low[u], low[v]);
                if(dfn[u] < low[v]){
                    sol++;
                    flag=0;
                }
            }else if(vis[v] == 1){
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    vis[u] = 2;
}
int main(void){
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d",&u[i],&v[i]);
	for(i=1;i<=m;i++)
		p[i]=i;
	for(int jo=1;jo<=20000;jo++)
	{
		for(i=1;i<=100;i++)
		{
			int x=rand()%m+1,y=rand()%m+1;
			swap(p[x],p[y]);
		}
		memset(viss,0,sizeof(viss));
		for(i=1;i<=m;i++)
		{
			init();
			viss[i]=1;
			for(j=1;j<=m;j++)
				if(viss[j]==0)
				{
					addedge(u[p[j]], v[p[j]]);
					addedge(v[p[j]], u[p[j]]);
				}
			flag=1;
			tarjan(1);
			for(j=1;j<=n;j++)
				if(vis[j]==0)
					flag=0;
			if(!flag)
				viss[i]=0;
		}
		s=0;
		for(i=1;i<=m;i++)
			if(viss[i]==1)
				s++;
		if(ans<s)
		{
			ans=s;
			int y=0;
			for(i=1;i<=m;i++)
				if(viss[i]==0)
					t[++y]=p[i];
		}
	}
	cout<<m-ans<<endl;
	for(i=1;i<=m-ans;i++)
		printf("%d %d\n",u[t[i]],v[t[i]]);
    return 0;
}