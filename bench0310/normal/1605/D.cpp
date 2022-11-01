#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> u[2];
        vector<int> x(n+1,-1);
        function<void(int)> dfs=[&](int a)
        {
            u[x[a]].push_back(a);
            for(int to:v[a])
            {
                if(x[to]==-1)
                {
                    x[to]=(x[a]^1);
                    dfs(to);
                }
            }
        };
        x[1]=0;
        dfs(1);
        if(u[0].size()>u[1].size()) swap(u[0],u[1]);
        int sz=u[0].size();
        auto msb=[&](int a)->int{return (31-__builtin_clz(a));};
        array<int,2> idx={0,0};
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int b=1-((sz>>msb(i))&1);
            p[u[b][idx[b]++]]=i;
        }
        for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
    }
    return 0;
}