#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b >= a)
        {
            cout << b << "\n";
        }
        else
        {
            if (d >= c)
            {
                cout << "-1\n";
            }
            else
            {
                ll t = c;
                c -= d;
                /// b + c * x >= a
                /// c * x >= a - b
                a -= b;
                ll full = a / c;
                if (a % c)
                {
                    full++;
                }
                cout << b + t * full << "\n";
            }
        }
    }
}