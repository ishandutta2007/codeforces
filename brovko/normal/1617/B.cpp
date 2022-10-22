#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

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

        int F = 0;

        for(int c = 1; c <= min(n, 100ll); c++)
            for(int a = c; a <= min(n - c, 100 * c); a += c)
            {
                int b = n - a - c;

                if(F == 0 && a > 0 && b > 0 && c > 0 && a != b && a != c && b != c && __gcd(a, b) == c)
                {
                    cout << a << ' ' << b << ' ' << c << "\n";
                    F = 1;
                }
            }
    }
}