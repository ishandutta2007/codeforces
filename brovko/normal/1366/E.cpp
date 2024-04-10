#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 998244353;

int n, m, a[200005], b[200005], l[200005], r[200005];

int mul(int x, int y)
{
    return x * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];
        
    int f = 0;
        
    for(int i = 0; i < n; i++)
        if(a[i] == b[0])
            f = 1;
        
    if(f == 0)
    {
        cout << 0;
        return 0;
    }

    int j = m - 1;

    for(int i = n - 1; i >= 0; i--)
    {
        while(a[i] < b[j])
        {
            l[j] = i;
            j--;

            if(j < 0)
            {
                cout << 0;
                return 0;
            }
        }

        if(a[i] == b[j] && r[j] == 0)
            r[j] = i;
    }

    /*for(int i = 0; i < m; i++)
        cout << l[i] << ' ' << r[i] << "\n";*/

    int ans = 1;

    for(int i = 1; i < m; i++)
    {
        if(r[i] == 0)
        {
            cout << 0;
            return 0;
        }

        ans = mul(ans, r[i] - l[i]);
    }

    cout << ans;
}