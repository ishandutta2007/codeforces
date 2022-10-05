#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<cstdlib>  
#include<algorithm>  
#include<queue>  
#define F(i,j,n) for(int i=j;i<=n;i++)  
#define D(i,j,n) for(int i=j;i>=n;i--)  
#define ll long long  
#define pa pair<int,int>  
#define maxn 20000  
#define maxm 50000  
#define inf 1000000000  
using namespace std;  
struct edge_type  
{  
    int from,to,next,v,c;  
}e[maxm];  
int head[maxn],dis[maxn],p[maxn],a[105][105],w[105];  
int ans=0,cnt=1,s,t,n ;  
bool inq[maxn];  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}  
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
inline void add_edge(int x,int y,int v,int c)  
{  
    e[++cnt]=(edge_type){x,y,head[x],v,c};head[x]=cnt;  
    e[++cnt]=(edge_type){y,x,head[y],0,-c};head[y]=cnt;  
}  
inline bool spfa()  
{  
    queue<int>q;  
    memset(inq,false,sizeof(inq));  
    F(i,1,t) dis[i]=inf;  
    dis[s]=0;inq[s]=true;q.push(s);  
    while (!q.empty())  
    {  
        int x=q.front();inq[x]=false;q.pop();  
        for(int i=head[x];i;i=e[i].next)  
        {  
            int y=e[i].to;  
            if (e[i].v&&dis[y]>dis[x]+e[i].c)  
            {  
                dis[y]=dis[x]+e[i].c;  
                p[y]=i;  
                if (!inq[y]){inq[y]=true;q.push(y);}  
            }  
        }  
    }  
    return dis[t]!=inf;  
}  
inline void mcf()  
{  
    while (spfa())  
    {  
        int tmp=inf;  
        for(int i=p[t];i;i=p[e[i].from]) tmp=min(tmp,e[i].v);  
        ans+=tmp*dis[t];  
        for(int i=p[t];i;i=p[e[i].from]){e[i].v-=tmp;e[i^1].v+=tmp;}  
    }  
}  
int main()  
{  
    n=read(); 
    int m = read();
    F(i,1,n) F(j,1,n) a[i][j]=(i==j?0:2);
    F(i,1,m){
        int x,y;
        x=read(),y=read();
        a[x][y]=1,a[y][x]=0;
    }
    s=n*(n+1)+1;t=s+1;  
    F(i,1,n) F(j,1,n)  
    {   
        if (a[i][j]!=2) w[i]+=a[i][j];  
    }  
    F(i,1,n)  
    {  
        ans+=(w[i]-1)*w[i]/2;  
        int tmp=n*n+i;  
        F(j,0,n-1) add_edge(tmp,t,1,w[i]+j);  
    }  
    F(i,1,n-1) F(j,i+1,n) if (a[i][j]==2)  
    {  
        int tmp=(i-1)*n+j;  
        add_edge(s,tmp,1,0);  
        add_edge(tmp,n*n+i,1,0);  
        add_edge(tmp,n*n+j,1,0);  
    }  
    mcf();  
    F(i,2,cnt) if (e[i].from>=1&&e[i].from<=n*n&&e[i].to<=n*(n+1)&&!e[i].v)  
    {  
        int tmp=e[i].from;  
        int x=(tmp-1)/n+1,y=tmp-(x-1)*n;  
        if (e[i].to==n*n+y) swap(x,y);  
        a[x][y]=1;a[y][x]=0;  
    }  
    int mx=n*(n-1)*(n-2)/6-ans;  
    // printf("%d\n",mx);  
    F(i,1,n)  
    {  
        F(j,1,n) printf("%d",a[i][j]);  
        printf("\n");  
    }  
}