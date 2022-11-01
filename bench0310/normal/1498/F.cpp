#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> gifts(n+1,0);
    for(int i=1;i<=n;i++) cin >> gifts[i];
    vector<array<int,40>> x(n+1);
    for(int i=1;i<=n;i++) x[i].fill(0);
    vector<int> depth(n+1,0);
    int m=2*k;
    function<void(int,int)> dfs1=[&](int a,int p)
    {
        if(p!=0) depth[a]=depth[p]+1;
        x[a][0]=gifts[a];
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs1(to,a);
            for(int j=0;j<m;j++) x[a][(j+1)%m]^=x[to][j];
        }
    };
    dfs1(1,0);
    auto reroot=[&](int a,int b) //b becomes root
    {
        for(int j=0;j<m;j++) x[a][(j+1)%m]^=x[b][j];
        for(int j=0;j<m;j++) x[b][(j+1)%m]^=x[a][j];
    };
    vector<int> res(n+1,-1);
    function<void(int,int)> dfs2=[&](int a,int p)
    {
        int t=0;
        for(int i=k;i<m;i++) t^=x[a][i];
        res[a]=(t!=0);
        for(int to:v[a])
        {
            if(to==p) continue;
            reroot(a,to);
            dfs2(to,a);
        }
        if(p!=0) reroot(a,p);
    };
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}