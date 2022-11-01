#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
const int L=19;
vector<int> v[N];
int depth[N];
int p[N][L];
int cnt[N];
int add[N];
int e[N];
vector<array<int,2>> z[N];
ll res=0;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<L;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=L-1;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=L-1;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

int up(int a,int d)
{
    for(int i=L-1;i>=0;i--) if(depth[p[a][i]]>=d) a=p[a][i];
    return a;
}

void go(int a)
{
    res+=((ll)e[a]*z[a].size());
    int sum=0;
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        go(to);
        sum+=cnt[to];
    }
    for(auto [x,y]:z[a])
    {
        res+=(sum+add[a]);
        if(x!=a) res-=cnt[x];
        if(y!=a) res-=cnt[y];
    }
    cnt[a]+=sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int m;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        int l=lca(a,b);
        for(int x:{a,b})
        {
            int u=up(x,depth[l]+1);
            if(depth[x]>=depth[l]+2)
            {
                cnt[x]++;
                add[x]++;
                cnt[u]--;
            }
            else if(u!=l) e[u]++;
        }
        z[l].push_back({up(a,depth[l]+1),up(b,depth[l]+1)});
    }
    go(1);
    vector<int> c(n+2*m+1,0);
    auto pairs=[&](int x)->ll{return ((ll)x*(x-1)/2);};
    for(int i=1;i<=n;i++)
    {
        int id=n+1;
        set<int> s;
        vector<array<int,2>> tmp;
        for(auto &[x,y]:z[i])
        {
            if(x==i) x=id++;
            if(y==i) y=id++;
            c[x]++;
            c[y]++;
            s.insert(x);
            s.insert(y);
            tmp.push_back({min(x,y),max(x,y)});
        }
        int sz=z[i].size();
        res+=pairs(sz);
        for(int t:s) res-=pairs(c[t]);
        sort(tmp.begin(),tmp.end());
        int l=0;
        while(l<sz)
        {
            int r=l;
            while(r+1<sz&&tmp[r+1]==tmp[l]) r++;
            res+=pairs(r-l+1);
            l=r+1;
        }
        for(int t:s) c[t]=0;
    }
    cout << res << "\n";
    return 0;
}