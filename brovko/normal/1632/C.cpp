#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int f(int x, int y)
{
    int ans = 0;

    for(int i = 29; i >= 0; i--)
    {
        if((x & (1 << i)) && (y & (1 << i)) == 0)
        {
            ans += (1 << i);

            return (ans | x);
        }
        else ans += ((1 << i) & (x | y));
    }

    return (ans | x);
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
        int a, b;
        cin >> a >> b;

        int ans = 1e9;

        for(int i = a; i <= b; i++)
        {
            ans = min(ans, i - a + f(i, b) - b + 1);
        }

        ans = min(ans, b - a);

        cout << ans << "\n";
    }
}