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
        for(int i=2;i<=n;i++)
        {
            int p;
            cin >> p;
            v[p].push_back(i);
        }
        string s;
        cin >> s;
        s="$"+s;
        int res=0;
        function<int(int)> dfs=[&](int a)->int
        {
            int x=(s[a]=='W'?1:-1);
            for(int to:v[a]) x+=dfs(to);
            res+=(x==0);
            return x;
        };
        dfs(1);
        cout << res << "\n";
    }
    return 0;
}