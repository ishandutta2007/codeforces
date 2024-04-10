#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

using li = long long;

using namespace std;
const int MOD = 1e9 + 7;

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> pos(n);

        for(int i = 0; i < n; i++)
            pos[a[i]] = i;

        int L = 1e9, R = -1e9, ans = 1;

        for(int i = 0; i < n; i++)
        {
            int j = pos[i];

            if(j > L && j < R)
                ans = mul(ans, R - L + 1 - i);

            L = min(L, j);
            R = max(R, j);
        }

        cout << ans << "\n";
    }
}