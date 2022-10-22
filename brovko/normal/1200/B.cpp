#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, m, k, h[105], f;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> t;
    while(t--)
    {
        f=0;
        cin >> n >> m >> k;
        for(int i=0;i<n;i++)
            cin >> h[i];
        for(int i=0;i<n-1;i++)
            {
                m+=min(h[i], h[i]-(h[i+1]-k));
                if(m<0)
                    f++;
            }
        if(f)
            cout << "NO\n";
        else cout << "YES\n";
    }
}