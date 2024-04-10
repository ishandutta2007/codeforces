#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005];

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

        int F = 1;

        while(n > 0)
        {
            int x = n - 1;

            while(x >= 0 && a[x] % (x + 2) == 0)
                x--;

            if(x < 0)
            {
                F = 0;
                break;
            }

            n--;

            for(int i = x; i < n; i++)
                a[i] = a[i + 1];
        }

        if(F)
            cout << "YES\n";
        else cout << "NO\n";
    }
}