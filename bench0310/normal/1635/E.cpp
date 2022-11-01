#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    vector<array<int,3>> edges(m);
    for(auto &[t,a,b]:edges)
    {
        cin >> t >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    auto out=[&](){cout << "NO\n";exit(0);};
    vector<int> c(n+1,-1);
    function<void(int)> dfs=[&](int a)
    {
        for(int to:v[a])
        {
            if(c[to]==-1)
            {
                c[to]=(c[a]^1);
                dfs(to);
            }
            if(c[a]==c[to]) out();
        }
    };
    for(int i=1;i<=n;i++)
    {
        if(c[i]==-1)
        {
            c[i]=0;
            dfs(i);
        }
    }
    vector<int> u[n+1];
    vector<int> in(n+1,0);
    for(auto [t,a,b]:edges)
    {
        if(c[a]==1) swap(a,b);
        if(t==1)
        {
            u[a].push_back(b);
            in[b]++;
        }
        else
        {
            u[b].push_back(a);
            in[a]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
    int tcnt=0;
    vector<int> x(n+1,0);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        x[a]=(++tcnt);
        for(int to:u[a]) if((--in[to])==0) q.push(to);
    }
    for(int i=1;i<=n;i++) if(x[i]==0) out();
    cout << "YES\n";
    for(int i=1;i<=n;i++) cout << "LR"[c[i]] << " " << x[i] << "\n";
    return 0;
}