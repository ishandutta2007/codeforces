#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, sol = 0, id_mx;
        ll k, big = 0, sum = 0;
        int skip = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            sum += x;
            big = max(big, x);
            if (x == big)
            {
                id_mx = i;
            }
            if (sum <= k && i > sol)
            {
                sol = i;
            }
            if (sum - big <= k && i - 1 > sol)
            {
                sol = i - 1;
                skip = id_mx;
            }
        }
        cout << skip << "\n";
    }
}