#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = (int) 1e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, sol = INF, fd;
        cin >> n >> x >> y;
        for (int f = 1; f <= 50; f++)
        {
            for (int d = 1; d <= 50; d++)
            {
                if (x >= f && y >= f && (x - f) % d == 0 && (y - f) % d == 0 && (y - f) / d < n)
                {
                    if (f + d * (n - 1) < sol)
                    {
                        sol = f + d * (n - 1);
                        fd = d;
                    }
                }
            }
        }
        sol += fd;
        for (int i = 1; i <= n; i++)
        {
            cout << (sol -= fd) << " ";
        }
        cout << "\n";
    }
}