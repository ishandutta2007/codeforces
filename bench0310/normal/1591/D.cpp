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
        vector<bool> q(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
            q[p[i]]=1;
        }
        bool ok=1;
        for(int i=1;i<=n;i++) ok&=q[i];
        bool res=[&]()->bool
        {
            if(!ok) return 1;
            int even=0;
            vector<bool> vis(n+1,0);
            for(int i=1;i<=n;i++)
            {
                if(vis[i]) continue;
                int a=i;
                int len=0;
                while(!vis[a])
                {
                    len++;
                    vis[a]=1;
                    a=p[a];
                }
                even+=((len%2)==0);
            }
            return ((even%2)==0);
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}