#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> v[N];
vector<int> col(N);
vector<int> sz(N);
vector<long long> res(N);
vector<int> cnt(N);

void dfs0(int a,int p=-1)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs0(to,a);
        sz[a]+=sz[to];
    }
}

map<int,int> dfs(int a,int p=-1)
{
    int idx=0;
    for(int to:v[a]) if(to!=p&&sz[to]>sz[idx]) idx=to;
    map<int,int> m;
    if(idx) m=dfs(idx,a);
    res[a]=res[idx];
    cnt[a]=cnt[idx];
    auto update=[&](int id,int val)->void
    {
        m[id]+=val;
        if(m[id]==cnt[a]) res[a]+=id;
        else if(m[id]>cnt[a])
        {
            cnt[a]=m[id];
            res[a]=id;
        }
    };
    for(int to:v[a])
    {
        if(to==p||to==idx) continue;
        map<int,int> t=dfs(to,a);
        for(pair<int,int> b:t) update(b.first,b.second);
    }
    update(col[a],1);
    return m;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&col[i]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs0(1);
    dfs(1);
    for(int i=1;i<=n;i++) printf("%I64d%c",res[i]," \n"[i==n]);
    return 0;
}