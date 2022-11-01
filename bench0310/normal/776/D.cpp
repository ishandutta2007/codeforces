#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> vr[N];
vector<bool> vis(N,0);
vector<int> comp(N,0);
vector<int> ord;

void dfs1(int a)
{
    vis[a]=1;
    for(int to:v[a]) if(vis[to]==0) dfs1(to);
    ord.push_back(a);
}

void dfs2(int a,int id)
{
    comp[a]=id;
    for(int to:vr[a]) if(comp[to]==0) dfs2(to,id);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> r(n+1,0);
    for(int i=1;i<=n;i++) cin >> r[i];
    vector<array<int,2>> x(n+1,{0,0});
    for(int i=1;i<=m;i++)
    {
        int c;
        cin >> c;
        for(int j=0;j<c;j++)
        {
            int a;
            cin >> a;
            x[a][(x[a][0]!=0)]=i;
        }
    }
    auto add=[&](int a,int b)
    {
        v[a].push_back(b);
        vr[b].push_back(a);
    };
    auto neg=[](int a)
    {
        return (2*(a/2)+1-(a&1));
    };
    for(int i=1;i<=n;i++)
    {
        auto [a,b]=x[i];
        vector<array<int,2>> cnf={{2*a,2*b+r[i]},{2*a+1,2*b+1-r[i]}};
        for(auto [c,d]:cnf)
        {
            add(neg(c),d);
            add(neg(d),c);
        }
    }
    for(int i=2;i<=2*m+1;i++) if(vis[i]==0) dfs1(i);
    reverse(ord.begin(),ord.end());
    int id=1;
    for(int a:ord) if(comp[a]==0) dfs2(a,id++);
    bool ok=1;
    for(int i=1;i<=m;i++)
    {
        ok&=(comp[2*i]!=comp[2*i+1]);
    }
    if(ok==1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}