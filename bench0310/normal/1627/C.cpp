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
        vector<array<int,2>> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back({b,i});
            v[b].push_back({a,i});
        }
        bool ok=1;
        int a=0;
        for(int i=1;i<=n;i++)
        {
            ok&=(v[i].size()<=2);
            if(v[i].size()==1) a=i;
        }
        if(ok)
        {
            vector<bool> vis(n+1,0);
            vector<int> res(n,0);
            int x=2;
            while(!vis[a])
            {
                vis[a]=1;
                for(auto [b,id]:v[a])
                {
                    if(!vis[b])
                    {
                        res[id]=x;
                        x^=1;
                        a=b;
                        break;
                    }
                }
            }
            for(int i=1;i<=n-1;i++) cout << res[i] << " \n"[i==n-1];
        }
        else cout << "-1\n";
    }
    return 0;
}