#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define p3 pair <ld, pair <ld, ld> >

using namespace std;

int t, n, k;

int p(int a, int b)
{
    int ans = 0;
    int z = 1;

    while(a > 0 || b > 0)
    {
        int c = (a + b) % k;
        ans += z * c;

        z *= k;
        a /= k;
        b /= k;
    }

    return ans;
}

int m(int a, int b)
{
    int ans = 0;
    int z = 1;

    while(a > 0 || b > 0)
    {
        int c = ((a - b) % k + k) % k;
        ans += z * c;

        z *= k;
        a /= k;
        b /= k;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        int y = 0;

        for(int i = 0; i < n; i++)
        {
            int x = p(y, i);

            cout << x << endl;

            int r;
            cin >> r;

            if(r == 1)
            {
                i = n;
                continue;
            }

            y = m(y, x);
        }
    }
}