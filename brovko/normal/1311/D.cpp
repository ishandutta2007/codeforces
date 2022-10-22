#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c;

        int A, B, C;

        int ans = 1e18;

        for(int i = 1; i <= b * 2; i++)
            for(int j = i; j <= c * 2; j += i)
            {
                int x = abs(a - i) + abs(b - j) + min(c % j, j - c % j);

                if(x < ans)
                {
                    ans = x;
                    A = i;
                    B = j;

                    if(c % j < j - c % j)
                        C = c / j * j;
                    else C = c / j * j + j;
                }
            }

        cout << ans << "\n";
        cout << A << ' ' << B << ' ' << C << "\n";
    }
}