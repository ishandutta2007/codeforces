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
        vector<int> d(n+1,0);
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            d[a]++; d[b]++;
        }
        vector<int> c(n+1,1);
        function<void(int,int)> dfs=[&](int a,int p)
        {
            for(int to:v[a])
            {
                if(to!=p)
                {
                    c[to]=-c[a];
                    dfs(to,a);
                }
            }
        };
        dfs(1,0);
        for(int i=1;i<=n;i++) cout << c[i]*d[i] << " \n"[i==n];
    }
    return 0;
}