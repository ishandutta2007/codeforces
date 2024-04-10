#include<bits/stdc++.h>
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
const int maxn=100010;
int n,head[maxn],cnt,out[maxn],dep[maxn];double ans;
struct Edge{int nxt,to;}edge[maxn<<1];
void add_edge(int x,int y){edge[++cnt].nxt=head[x];edge[cnt].to=y;head[x]=cnt;}
void dfs(int x,int fa,double exp){
    int flag=0;dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=edge[i].nxt){
        int v=edge[i].to;if(v==fa)continue;flag=1;
        if(fa==0)dfs(v,x,exp*(1.0/out[x]));else dfs(v,x,exp*(1.0/(out[x]-1)));
    }if(!flag)ans+=(double)(dep[x]-1)*exp;
}
int main()
{
    n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        add_edge(u,v);add_edge(v,u);out[v]++;out[u]++;
    }dfs(1,0,1);printf("%.9lf",ans);
    return 0;
}