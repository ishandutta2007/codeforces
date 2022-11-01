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
        for(int i=1;i<=n;i++)
        {
            int k;
            cin >> k;
            for(int j=1;j<=k;j++)
            {
                int a;
                cin >> a;
                v[i].push_back(a);
            }
        }
        bool ok=1;
        vector<int> c(n+1,-1);
        int res=0;
        function<void(int)> dfs=[&](int a)
        {
            if(c[a]==0) ok=0;
            if(c[a]!=-1) return;
            c[a]=0;
            int d=1;
            for(int to:v[a])
            {
                dfs(to);
                d=max(d,c[to]+(to>a));
            }
            c[a]=d;
            res=max(res,d);
        };
        for(int i=1;i<=n;i++) dfs(i);
        if(!ok) res=-1;
        cout << res << "\n";
    }
    return 0;
}