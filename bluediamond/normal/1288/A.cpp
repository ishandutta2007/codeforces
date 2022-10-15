#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        bool ok = 0;
        for (int s = sqrt(d) - 1; s <= sqrt(d) + 1; s++)
        {
            if (s + 1 > 0 && s + (d + s) / (s + 1) <= n)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}