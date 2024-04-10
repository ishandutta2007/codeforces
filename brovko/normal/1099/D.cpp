#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, p[100005], s[100005], a[100005];
vector <int> g[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=2;i<=n;i++)
    {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)
        cin >> s[i];

    for(int i=1;i<=n;i++)
        if(s[i]==-1)
    {
        s[i]=s[p[i]];
        if(g[i].size()!=0)
        {
            int x=1e9;
            for(auto to:g[i])
            {
                x=min(x, s[to]);
            }
            if(x<s[i])
            {
                cout << -1;
                return 0;
            }
            s[i]=x;
        }
    }

    a[1]=s[1];
    for(int i=2;i<=n;i++)
        a[i]=s[i]-s[p[i]];
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=a[i];
    cout << ans;
}