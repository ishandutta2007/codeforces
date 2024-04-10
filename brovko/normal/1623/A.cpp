#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a, b, c, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {

        cin >> n >> m >> a >> b >> c >> d;

        int ans = 0, dr = 1, dc = 1;

        while(a != c && b != d)
        {
            if(a == n)
                dr = -1;

            if(a == 1)
                dr = 1;

            if(b == m)
                dc = -1;

            if(b == 1)
                dc = 1;

            a += dr;
            b += dc;
            ans++;
        }

        cout << ans << "\n";

    }
}