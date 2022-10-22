#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a[25], used[25];

int f(int x)
{
    int y = 1, ans = 0;

    for(int z = 0; z < 18; z++)
    {
        y *= 10;

        if(used[z])
            y = 1;

        ans += y * (x % 10);
        x /= 10;
    }

    return ans;
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
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < 15; i++)
            used[i] = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            used[a[i]] = 1;
        }

        int ans = (int)1e18 - 1, x = 1e17;
//        cout << f(ans) << endl;

        for(int i = 17; i >= 0; i--)
        {
            int cnt = 0;

            while(f(ans) > k && cnt++ < 9)
                ans -= x;

            if(f(ans) <= k)
                ans += x;

            x /= 10;
        }

        cout << ans << "\n";
    }
}