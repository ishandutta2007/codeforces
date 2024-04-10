#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
vector<int> g[1100];
int v[1100],du[1100];
int query(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int t; scanf("%d",&t);
    return t;
}
int main() 
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
        du[x]++; du[y]++;
    }
    for(int i=1;i<=n;i++)v[i]=1;
    for(int i=1;i<=n/2;i++)
    {
        int x=-1,y=-1;
        for(int i=1;i<=n;i++)
            if (v[i] && du[i]==1)
            {
                if (x==-1)x=i; else y=i;
            }
        int t=query(x,y);
        if (t==x || t==y)
        {
            printf("! %d\n",t); 
            fflush(stdout); 
            return 0;
        }
        v[x]=0; v[y]=0;
        for(auto p:g[x])du[p]--;
        for(auto p:g[y])du[p]--;
    }
    for(int i=1;i<=n;i++)
        if (v[i]){ printf("! %d\n",i); fflush(stdout); return 0; }
    return 0;
}