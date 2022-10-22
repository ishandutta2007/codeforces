#include<bits/stdc++.h>
#define N 100050
#define mod 1000000007
using namespace std;
int n,m,pow_2[N+5],S,T,pre[N+5],st[N+5],cnt;
vector<pair<int,int> > e[N+5];
namespace chairman_tree
{
    int tot,root[N+5];
    struct node
    {
        int sum,hash,lson,rson;
    }t[N<<5];
    #define mid ((l+r)>>1)
    inline void push_up(int x,int l,int r)
    {
        t[x].sum=t[t[x].lson].sum+t[t[x].rson].sum;
        t[x].hash=(t[t[x].lson].hash+1ll*t[t[x].rson].hash*pow_2[mid-l+1])%mod;
    }
    inline bool insert(int last,int &x,int l,int r,int p)
    {
        if(l>=p && t[last].sum==r-l+1) return 0;
        x=++tot;bool ret;
        if(l==r) return t[x].sum=t[x].hash=1,1;
        if(p>mid) t[x].lson=t[last].lson,ret=insert(t[last].rson,t[x].rson,mid+1,r,p);
        else if((ret=insert(t[last].lson,t[x].lson,l,mid,p))) t[x].rson=t[last].rson;
        else ret=insert(t[last].rson,t[x].rson,mid+1,r,p);
        return push_up(x,l,r),ret;
    }
    inline bool compare(int x,int y)
    {
        if(t[x].hash==t[y].hash) return 1;
        if(!t[x].sum || !t[y].sum) return t[x].sum;
        if(t[t[x].rson].hash==t[t[y].rson].hash)
            return compare(t[x].lson,t[y].lson);
        return compare(t[x].rson,t[y].rson);
    }
}
using namespace chairman_tree;
struct val
{
    int x;
    inline val(int x):x(x) {}
    inline bool operator<(const val &b) const
    {
        return compare(root[x],root[b.x]);
    }
};
inline bool dijkstra()
{
    #define y edge.first
    #define w edge.second
    static bool vis[N+5];
    priority_queue<val> q;
    q.push(S);
    while(!q.empty())
    {
        int x=q.top().x;q.pop();
        if(vis[x]) continue;
        vis[x]=1;int temp;
        if(x==T) return 1;
        for(pair<int,int> edge:e[x])
            if(!vis[y])
            {
                insert(root[x],temp,0,N,w);
                if(!root[y] || compare(root[y],temp))
                    pre[y]=x,root[y]=temp,q.push(y);
            }
    }
    return 0;
    #undef y
    #undef w
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1,u,v,w;i<=m;++i)
    {
        scanf("%d %d %d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    pow_2[0]=1;for(int i=1;i<=N;++i)
        pow_2[i]=(pow_2[i-1]<<1)%mod;
    scanf("%d %d",&S,&T);
    if(!dijkstra()) puts("-1");
    else
    {
        printf("%d\n",t[root[T]].hash);
        for(int x=T;x!=S;x=pre[x]) st[++cnt]=x;
        st[++cnt]=S,printf("%d\n",cnt);
        for(int i=cnt;i;--i) printf("%d ",st[i]);
    }
    return 0;
}