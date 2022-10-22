#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;

int t, n, a[20];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int k = 0;

        for(int i = 0; i < n; i++)
        {
            while(a[i] % 2 == 0)
            {
                a[i] /= 2;
                k++;
            }
        }

        sort(a, a + n);

        for(int i = 0; i < k; i++)
            a[n - 1] *= 2;

        int s = 0;

        for(int i = 0; i < n; i++)
            s += a[i];

        cout << s << "\n";
    }
}