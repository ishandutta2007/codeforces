#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        int m = min(p1, p2);

        p1 -= m;
        p2 -= m;

        int F = 0;

        for(int i = 0; i < p1; i++)
        {
            x1 *= 10;

            if(x1 > x2)
            {
                F = 1;
                break;
            }
        }

        for(int i = 0; i < p2; i++)
        {
            x2 *= 10;

            if(x2 > x1)
            {
                F = -1;
                break;
            }
        }

        if(F == 1 || F == 0 && x1 > x2)
            cout << ">\n";
        else if(F == 0 && x1 == x2)
            cout << "=\n";
        else cout << "<\n";
    }
}