#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int mod=1000000007;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int p;
            cin >> p;
            a[p]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int p;
            cin >> p;
            b[p]=i;
        }
        vector<int> v[n+1];
        for(int i=1;i<=n;i++)
        {
            v[a[i]].push_back(b[i]);
            v[b[i]].push_back(a[i]);
        }
        vector<bool> vis(n+1,0);
        int res=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int now=i;
            vis[now]=1;
            while(1)
            {
                int nxt=v[now][0];
                if(vis[nxt]) nxt=v[now][1];
                if(vis[nxt]) break;
                now=nxt;
                vis[now]=1;
            }
            res=(res*2)%mod;
        }
        cout << res << "\n";
    }
    return 0;
}