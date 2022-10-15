#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, m, t;
    cin >> n >> k >> m >> t;
    for (int i = 0; i < t; i++)
    {
        int e, p;
        cin >> e >> p;
        if (e == 0)
        {
            int len1 = p, len2 = n - len1;
            if (k <= len1)
            {
                n = len1;
            }
            else
            {
                n = len2;
                k -= len1;
            }
        }
        else
        {
            k += (p <= k);
            n++;
        }
        cout << n << " " << k << "\n";
    }

    return 0;
}