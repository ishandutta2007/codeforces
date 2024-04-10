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
        int p;
        cin >> p;
        int n=(1<<p);
        vector<array<int,2>> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back({b,i});
            v[b].push_back({a,i});
        }
        vector<int> vc(n+1,0);
        vector<int> ec(n,0);
        vc[1]=(1<<p);
        int x=1;
        function<void(int,int,int)> dfs=[&](int a,int u,int d)
        {
            for(auto [to,id]:v[a])
            {
                if(to==u) continue;
                ec[id]=(1<<p)^x;
                vc[to]=x;
                if(d&1) swap(ec[id],vc[to]);
                x++;
                dfs(to,a,d+1);
            }
        };
        dfs(1,0,0);
        cout << "1\n";
        for(int i=1;i<=n;i++) cout << vc[i] << " \n"[i==n];
        for(int i=1;i<=n-1;i++) cout << ec[i] << " \n"[i==n-1];
    }
    return 0;
}