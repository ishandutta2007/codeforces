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
        vector<int> p(n+1,0);
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
            if(p[i]!=i) c[p[i]]++;
        }
        vector<bool> vis(n+1,0);
        vector<vector<int>> res;
        for(int i=1;i<=n;i++)
        {
            if(c[i]>=1||vis[i]) continue;
            int a=i;
            vector<int> path;
            do
            {
                path.push_back(a);
                vis[a]=1;
                a=p[a];
            }while(!vis[a]&&a!=0);
            ranges::reverse(path);
            res.push_back(path);
        }
        cout << res.size() << "\n";
        for(vector<int> path:res)
        {
            cout << path.size() << "\n";
            for(int a:path) cout << a << " ";
            cout << "\n";
        }
    }
    return 0;
}