#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define M 1000000

int u[2*M],v[2*M],first[M],next[2*M],deg[M],sz;
int q[M]; //queue
bool vis[M];

void add(int U,int V)
{
    u[sz] = U, v[sz] = V;
    next[sz] = first[U];
    first[U] = sz;
    sz++;
}
int cnt; // number of points with odd degree
void dfs(int x)
{
    int front = 0, rear = 1;
    q[front]  = x;
    vis[x] = 1;
    while(front < rear)
    {
        int t = q[front++];
        if(deg[t] % 2 == 1) cnt++;
        vis[t] = 1;
        for(int k = first[t]; k != -1; k = next[k])
        {
            if(!vis[v[k]])
            {
                q[rear++] = v[k];
                vis[v[k]] = 1;
            }
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        sz = 0;
        memset(first,-1,sizeof(first));
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        int U,V;
        for(int k = 0; k < m ; k++)
        {
            scanf("%d%d",&U,&V);
            U--,V--;
            deg[U]++, deg[V]++;
            add(U,V);
            add(V,U);
        }
        int ans = 0,t = 0,od = 0;
        for(int k = 0; k < n; k++)
        {
            if(!vis[k] && (first[k]!=-1||k==0))
            {
                t++;
                cnt = 0;
                dfs(k);
                if(cnt)ans += cnt/2,od++;
                else ans++;
            }
        }
        if(t== 1 && od ==0) ans--;
        printf("%d\n",ans);

    }
    return 0;
}