#include<cstdio>
#include<cstring>
using namespace std;
inline void readi(int &x);
const int maxn=1000005;
int n,m,S,T,d[maxn],f[maxn];
int adj[maxn*2],next[maxn*2],tot;
int head[maxn],rhead[maxn];
bool vis[maxn];
int q[maxn*4],qh,qt;
void addedge(int *head,int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;}
int main()
{
    readi(n),readi(m);
    for(int i=1,u,v;i<=m;i++)
    {
        readi(u),readi(v);
        addedge(head,u,v);
        addedge(rhead,v,u);
        d[u]++;
    }
    readi(S),readi(T);
    memset(f,-1,n+1<<2);
    f[T]=0;qh=qt=maxn*2;
    q[++qt]=T;
    for(int u,v,i;qh<qt;)
    {
        u=q[++qh];
        if(u==S)break;
        if(!vis[u])
        {
            vis[u]=1;
            for(i=rhead[u];i;i=next[i])
            {
                v=adj[i];
                if(--d[v]==0)
                {
                    if(f[v]==-1||f[u]<f[v])
                    {
                        f[v]=f[u];
                        q[qh--]=v;
                    }
                }
                else if(f[v]==-1)
                {
                    f[v]=f[u]+1;
                    q[++qt]=v;
                }
            }
        }
    }
    printf("%d\n",f[S]);
    return 0;
}
inline void readi(int &x)
{char c;for(c=getchar();c>'9'||c<'0';c=getchar());
x=c^'0';for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+(c^'0');}