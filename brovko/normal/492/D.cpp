#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x, y, a;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;

    while(n--)
    {
        cin >> a;

        int L = 0, R = 1e18;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(M / x + M / y >= a)
                R = M;
            else L = M;
        }

        if(R % x == 0 && R % y == 0)
            cout << "Both\n";
        else if(R % x == 0)
            cout << "Vova\n";
        else cout << "Vanya\n";
    }
}