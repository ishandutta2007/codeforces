#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define magic 300
#define M 600000
#define N 200001
using namespace std;
vector<int> g[200];
long long a[200];
int du[200];
int n;
bool cmp(int x,int y)
{
    return du[x]<du[y];
}
int ans[200],v[200];
int q[200];
void dfs(int x,int dep)
{
    ans[dep]=x;
    v[x]=1;
    if (dep==n)
    {
        for(int i=1;i<=n;i++)printf("%lld%c",a[ans[i]],i==n?'\n':' ');
        exit(0);
    }
    for(auto p:g[x])
        if (!v[p])dfs(p,dep+1);
    v[x]=0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                if (a[i]*2==a[j]){ du[i]++; g[i].pb(j); }
                if (a[j]*3==a[i]){ du[i]++; g[i].pb(j); }
            }
    for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end(),cmp);
    for(int i=1;i<=n;i++)q[i]=i;
    sort(q+1,q+n+1,cmp);
    for(int i=1;i<=n;i++)dfs(q[i],1);
    return 0;
}