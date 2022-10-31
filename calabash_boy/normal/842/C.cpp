#include <bits/stdc++.h>
using namespace std;
int n,v,u;
#define maxn 200030
struct Edge{
    int v,nxt;
}edge[maxn*2];

int cnt=0,head[maxn];
int pre[maxn][50];
int preGCD[1000],num[maxn],tot,res[maxn];

int gcd(int a,int b){
   return b==0?a:gcd(b,a%b);
}

void addedge(int u,int v){
    edge[tot].v=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}

void dfs(int u,int fa,int tgcd){
    int SOTRE;
    SOTRE=cnt;
    for (int i=0; i<cnt; i++){
        pre[u][i] = preGCD[i];
        preGCD[i] = gcd(preGCD[i], num[u]);
        res[u] = max(res[u],preGCD[i]);
    }
    preGCD[cnt++] = tgcd;
    res[u] = max(res[u],tgcd);
    sort(preGCD,preGCD+cnt);
    cnt=unique(preGCD,preGCD+cnt) - preGCD;
    tgcd=gcd(tgcd,num[u]);
    res[u] = max(res[u],tgcd);
    for (int i=head[u]; ~i; i=edge[i].nxt){
        int v=edge[i].v;
        if (v==fa) continue;
        dfs(v,u,tgcd);
    }
    cnt=SOTRE;
    for (int i=0; i<cnt; i++)
        preGCD[i]=pre[u][i];
}
int main(){
	tot=0;
    cin>>n;
    for (int i=1; i<=n; i++){
    	        scanf("%d",&num[i]);
    }


    memset(res,0,sizeof(res));
    memset(head,-1,sizeof(head));
    for (int i=1; i<n; i++){
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,-1,0);
    for (int i=1; i<=n; i++){
    	  printf("%d%c",res[i]," \n"[i==n]);
    }

    return 0;
}