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
        vector<int> q(n+1,0);
        for(int i=1;i<=n;i++) cin >> q[i];
        vector<int> r(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            r[a]=i;
        }
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=r[q[i]];
        vector<bool> vis(n+1,0);
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int a=i;
            int s=0;
            while(!vis[a])
            {
                s++;
                vis[a]=1;
                a=p[a];
            }
            c+=(s/2);
        }
        ll res=0;
        for(int i=1;i<=c;i++) res+=(2*(n+1-2*i));
        cout << res << "\n";
    }
    return 0;
}