#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen ("input", "r", stdin);

    int s, x1, x2, t1, t2, p, d;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    swap(t1, t2);
    int sol = abs(x1 - x2) * t1;
    int tram = 0;

    int p1 = p;
    int p2 = x1;

    if (d == -1)
    {
        if (p2 <= p1)
        {
            tram += t2 * (p1 - p2);
        }
        else
        {
            tram += t2 * (p1 + p2);
            d = 1;
        }
    }
    else
    {
        if (p1 <= p2)
        {
            tram += t2 * (p2 - p1);
        }
        else
        {
            tram += t2 * (s - p1 + s - p2);
            d = -1;
        }
    }

    p1 = x1;
    p2 = x2;

    if (d == -1)
    {
        if (p2 <= p1)
        {
            tram += t2 * (p1 - p2);
        }
        else
        {
            tram += t2 * (p1 + p2);
            d = 1;
        }
    }
    else
    {
        if (p1 <= p2)
        {
            tram += t2 * (p2 - p1);
        }
        else
        {
            tram += t2 * (s - p1 + s - p2);
            d = -1;
        }
    }

    sol = min(sol, tram);
    cout << sol << "\n";
}