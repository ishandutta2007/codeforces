#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define N 5005
#define INF 1000000000
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
typedef long long LL;
vector<int> G[N],S[N];
int d1[N],d2[N];
struct Store
{
    int c,k,p;
    bool operator<(const Store &t) const
    {
        return p<t.p;
    }
}s[N];

void BFS(int st)
{
    memset(d1,-1,sizeof(d1));
    memset(d2,-1,sizeof(d2));
    d1[st]=0;
    queue<int> q;
    q.push(st);
    int x,v,i;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0;i<S[x].size();i++)
            d2[S[x][i]]=d1[x];
        for(i=0;i<G[x].size();i++)
        {
            v=G[x][i];
            if(d1[v]==-1)
            {
                d1[v]=d1[x]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n,m,a,b,i,w,q,g,r,qa,L,R,mid,rel;
    LL sum,now;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin>>w;
    for(i=1;i<=w;i++)
        scanf("%d%d%d",&s[i].c,&s[i].k,&s[i].p);
    sort(s+1,s+1+w);
    for(i=1;i<=w;i++)
        S[s[i].c].push_back(i);
    cin>>q;
    while(q--)
    {
        scanf("%d%d%d",&g,&r,&qa);
        BFS(g);
        L=0,R=n,rel=-1;
        while(L<=R)
        {
            mid=(L+R)>>1;
            now=r;
            sum=0;
            for(i=1;i<=w;i++)
                if(d2[i]<=mid&&d2[i]!=-1)
                {
                    if(s[i].k>=now)
                    {
                        sum+=now*s[i].p;
                        now=0;
                    }
                    else
                    {
                        sum+=(LL)s[i].k*s[i].p;
                        now-=s[i].k;
                    }
                }
            //debug(sum);
            if(now||sum>qa)
                L=mid+1;
            else
            {
                rel=mid;
                R=mid-1;
            }
        }
        printf("%d\n",rel);
    }
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/