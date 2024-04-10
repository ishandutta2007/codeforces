#include<bits/stdc++.h>
#define int long long
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
using namespace std;
deque<int> Q;
int ans=0,res=0,n,S,T,cnt=0;
int d[5003],a[5003];
bool inq[5003],vis[5003];
struct Edge{
    int to,cap,cost,next;
}e[100003];
void addedge(int u,int v,int w,int c)
{
    e[cnt].to=v;e[cnt].cap=w;e[cnt].cost=c;e[cnt].next=a[u],a[u]=cnt++;
}
bool bfs(){
    for(int i=0;i<=n;i++) d[i]=1000000000000000ll;
    memset(inq,0,sizeof(inq));
    d[T]=0,Q.push_back(T),inq[T]=true;
    while(!Q.empty()){
        int u=Q.front();
		Q.pop_front(),inq[u]=false;
        for(int p=a[u]; p!=-1; p=e[p].next)
		{
            int v=e[p].to;
            if(e[p^1].cap && d[v]>d[u]-e[p].cost)
			{
                d[v]=d[u]-e[p].cost;
                if(!inq[v])
				{
                    inq[v]=true;
                    if(Q.empty() || d[v]>=d[Q.front()]) Q.push_back(v); else Q.push_front(v);
                    //Happy  Time! 
                }
            }
        }
    }
    return d[S]<d[0];
}
int dfs(int u,int f)
{
    vis[u]=true;
    if(u==T || f==0)return f;
    int used=0;
    for(int p=a[u]; p!=-1; p=e[p].next)
	{
        int v=e[p].to;
        if((!vis[v]) && e[p].cap && d[v]==d[u]-e[p].cost){
            int w=f-used;
            w=dfs(v,min(e[p].cap,w));
            e[p].cap-=w,e[p^1].cap+=w,used+=w;
            if(used==f) return used;
        }
    }
    return used;
}
int A[5003],B[5003],K,TT;
signed main(){
    n=read(),K=read(),S=n+1,TT=n+2,T=n+3;
	for(int i=1; i<=n; i++) A[i]=read();
	for(int i=1; i<=n; i++) B[i]=read();
    memset(a,0xff,sizeof(a));
    for(int i=1; i<=n; i++)
	{
        addedge(S,i,1,A[i]),addedge(i,S,0,-A[i]);
        addedge(i,TT,1,B[i]),addedge(TT,i,0,-B[i]);
    	if(i!=n) addedge(i,i+1,1000000,0),addedge(i+1,i,0,0);
	}
	addedge(TT,T,K,0),addedge(T,TT,0,0);
	n=n+3;
    while(bfs())
	{
        vis[T]=1;
        while(vis[T])
		{
            memset(vis,0,sizeof(vis));
            int flow=dfs(S,1000000000000000ll);
            res+=d[S]*flow;
            ans+=flow;
        }
    }
    printf("%lld",res);
    return 0;
}