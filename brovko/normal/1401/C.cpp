#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, a[100005], Fixed[100005];

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int Min = a[0];

        for(int i = 0; i < n; i++)
            Min = min(Min, a[i]);

        for(int i = 0; i < n; i++)
            {
                if(gcd(a[i], Min) == Min)
                    Fixed[i] = 0;
                else Fixed[i] = a[i];
            }

        sort(a, a + n);

        int f = 1;

        for(int i = 0; i < n; i++)
            if(Fixed[i] > 0 && Fixed[i] != a[i])
                f = 0;

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}