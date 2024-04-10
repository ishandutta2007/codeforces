#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> v[N];
vector<int> c(N,0);
vector<int> sz(N,0);
vector<int> big(N,0);
vector<array<int,2>> q[N];
vector<int> res(N,0);

void dfs(int a,int p=-1)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

array<map<int,int>,2> solve(int a,int p=-1)
{
    array<map<int,int>,2> t;
    if(sz[a]>1) t=solve(big[a],a);
    map<int,int> &m=t[0];
    map<int,int> &cnt=t[1];
    for(int to:v[a])
    {
        if(to==p||to==big[a]) continue;
        array<map<int,int>,2> x=solve(to,a);
        for(auto [col,num]:x[0])
        {
            for(int i=0;i<num;i++)
            {
                m[col]++;
                cnt[m[col]]++;
            }
        }
    }
    m[c[a]]++;
    cnt[m[c[a]]]++;
    for(auto [num,idx]:q[a])
    {
        if(cnt.find(num)!=cnt.end()) res[idx]=cnt[num];
    }
    return t;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        q[a].push_back({b,i});
    }
    dfs(1);
    solve(1);
    for(int i=1;i<=m;i++) printf("%d\n",res[i]);
    return 0;
}