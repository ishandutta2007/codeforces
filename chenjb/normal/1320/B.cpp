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
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n,m;
vector<int> g[410000];
int k,p[410000];
int d[410000],q[410000],cnt[410000];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[y].pb(x);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&p[i]);
    memset(d,255,sizeof(d));
    int head=0,tail=1;
    d[p[k]]=0; q[1]=p[k];
    while (head<tail)
    {
        int x=q[++head];
        for(auto y:g[x])
            if (d[y]==-1)
            {
                d[y]=d[x]+1;
                q[++tail]=y;
            }
    }
    for(int i=1;i<=n;i++)
        for(auto p:g[i])
            if (d[p]==d[i]+1)cnt[p]++;
    int ans1=0,ans2=0;
    for(int i=1;i<k;i++)
        if (d[p[i]]!=d[p[i+1]]+1)ans1++,ans2++;
        else if (cnt[p[i]]>1)ans2++;
    printf("%d %d\n",ans1,ans2);
    return 0;
}