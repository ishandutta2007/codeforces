#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
long long h[100005],p[100005],total_p[100005],used[100005],bad[100005],good[100005];
vector <int> v[100005];
long long dfs(int x)
{
    total_p[x]=p[x];
    for(int i=0;i<v[x].size();i++)
        if(used[v[x][i]]==0) {
            used[v[x][i]] = 1;
            total_p[x] += dfs(v[x][i]);
        }
    return total_p[x];
}
int check(int x)
{
    long long cnt=0;
    if(good[x]+bad[x]!=total_p[x]||good[x]<0||bad[x]<0||good[x]>total_p[x]||bad[x]>total_p[x])
        return 0;
    for(int i=0;i<v[x].size();i++)
        if(used[v[x][i]]==0)
        {
            cnt+=bad[v[x][i]];
            used[v[x][i]]=1;
            if(good[v[x][i]]>good[x])
            {
                //cout<<bad[x]<<" "<<bad[v[x][i]]<<" "<<p[x]<<endl;
                //cout<<x<<" "<<v[x][i]<<endl;
                return 0;
            }
            if(check(v[x][i])==0) return 0;
        }
    if(bad[x]-cnt>p[x]) return 0;
    return 1;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,x,y;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++) used[i]=0;
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        used[1]=1;
        dfs(1);
        for(int i=1;i<=n;i++)
        {
            //printf("%lld ",total_p[i]);
            bad[i]=(total_p[i]-h[i])/2;
            good[i]=bad[i]+h[i];
            used[i]=0;
            //printf("%lld %lld\n",good[i],bad[i]);
        }
        //printf("\n");
        //for(int i=1;i<=n;i++) printf("%d %d\n",good[i],bad[i]);
        used[1]=1;
        if(check(1)) printf("YES\n");
        else printf("NO\n");
    }
}