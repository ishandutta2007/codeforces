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
int du[N],v[N];
vector<int> g[N];
int n,m,flag;
void dfs(int x)
{
    if (v[x])return;
    v[x]=1;
    if (du[x]!=2)flag=0;
    for(auto p:g[x])dfs(p);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
        du[x]++; du[y]++;
    }
    for(int i=1;i<=n;i++)v[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
        if (!v[i])
        {
            flag=1;
            dfs(i);
            if (flag)ans++;
        }
    cout<<ans<<endl;
}