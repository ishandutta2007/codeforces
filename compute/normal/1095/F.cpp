#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
const int maxn=2e5+7;
struct Edge{
    int from,to;
    long long cost;
    bool operator<(const Edge &a)const{
        return cost<a.cost;
    }
}edge[maxn];
PII arr[maxn];
int n,m;
int far[maxn];
void init()
{
    for(int i=0;i<=n;i++)
        far[i]=i;
}
int Find(int x)
{
    if(x==far[x]) return x;
    return far[x]=Find(far[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y) return ;
    far[y]=x;
}
long long solve()
{
    priority_queue<PII,vector<PII>,greater<PII> > q;
    init();
    for(int i=1;i<=n;i++)
        q.push(arr[i]);
    int index=q.top().second;
    long long ori=q.top().first;
    q.pop();
    sort(edge,edge+m);
    long long ans=0;
    for(int i=0;i<m;i++)
    {
        while(!q.empty()&&Find(index)==Find(q.top().second)) q.pop();
        long long cur=ori+q.top().first;
        if(Find(edge[i].from)==Find(edge[i].to)) continue;
        if(cur<edge[i].cost)
        {
            Union(q.top().second,index);
            ans+=cur;
            i--;
        }
        else{
            Union(edge[i].from,edge[i].to);
            ans+=edge[i].cost;
        }
    }
    while(!q.empty())
    {
        if(Find(index)==Find(q.top().second)) q.pop();
        else{
            long long cur=ori+q.top().first;
            Union(q.top().second,index);
            ans+=cur;
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i].first);
        arr[i].second=i;
    }
    long long cost;
    for(int i=0,u,v;i<m;i++)
    {
        scanf("%d%d%lld",&edge[i].from,&edge[i].to,&edge[i].cost);
    }
    long long ans=solve();
    printf("%lld\n",ans);
}