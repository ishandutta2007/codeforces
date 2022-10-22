#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(a[0] % 5 == 0)
        {
            for(int i = 0; i < n; i++)
                a[i] += a[i] % 10;

            bool F = 1;

            for(int i = 0; i < n - 1; i++)
                F &= (a[i] == a[i + 1]);

            cout << (F ? "YES\n" : "NO\n");
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                int x = 0;

                while(x++ < 10 && a[i] % 10 != 2)
                    a[i] += a[i] % 10;
            }

            bool F = 1;

            for(int i = 0; i < n - 1; i++)
                F &= ((a[i] - a[i + 1]) % 20 == 0);

            cout << (F ? "YES\n" : "NO\n");
        }
    }
}