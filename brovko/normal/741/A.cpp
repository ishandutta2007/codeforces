#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105], x[105], used[105];

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    int ans = 1;

    for(int i = 0; i < n; i++)
        if(used[i] == 0)
        {
            int y = i;

            while(used[y] == 0)
            {
                used[y] = 1;
                y = a[y];
                x[i]++;
            }

            if(y != i)
            {
                cout << -1;
                return 0;
            }

            if(x[i] % 2)
                ans = lcm(ans, x[i]);
            else ans = lcm(ans, x[i] / 2);
        }

    cout << ans;
}