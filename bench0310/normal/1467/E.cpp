#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(18,0));
vector<int> tin(N,0);
vector<int> tout(N,0);
vector<int> bad(N,0);
int tcnt=1;

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    tin[a]=tcnt++;
    for(int i=1;i<18;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
    tout[a]=tcnt-1;
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=17;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=17;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

int up(int a,int d)
{
    for(int i=17;i>=0;i--) if(depth[p[a][i]]>=d) a=p[a][i];
    return a;
}

void add(int l,int r)
{
    bad[l]++;
    bad[r+1]--;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<array<int,2>> h;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        h.push_back({a[i],i});
    }
    sort(h.begin(),h.end());
    int id=1;
    for(int i=0;i<n;i++)
    {
        if(i>0&&h[i][0]!=h[i-1][0]) id++;
        a[h[i][1]]=id;
    }
    for(int i=1;i<=n-1;i++)
    {
        int b,c;
        cin >> b >> c;
        v[b].push_back(c);
        v[c].push_back(b);
    }
    vector<int> occ[n+1];
    for(int i=1;i<=n;i++) occ[a[i]].push_back(i);
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        sort(occ[i].begin(),occ[i].end(),[](const int &b,const int &c){return (tin[b]<tin[c]);});
        int sz=occ[i].size();
        if(sz==1) continue;
        for(int j=0;j<sz;j++)
        {
            int b=occ[i][j];
            int c=occ[i][(j+1)%sz];
            int l=lca(b,c);
            if(l!=b&&l!=c)
            {
                add(tin[b],tout[b]);
                add(tin[c],tout[c]);
            }
            else
            {
                if(c==l) swap(b,c);
                int x=up(c,depth[b]+1);
                add(1,tin[x]-1);
                add(tout[x]+1,n);
                add(tin[c],tout[c]);
            }
        }
    }
    int now=0;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        now+=bad[i];
        res+=(now==0);
    }
    cout << res << "\n";
    return 0;
}