#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair

using namespace std;

int t, n, a[55];

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

        int x = 0, y = 0;

        for(int i = 0; i < n; i++)
            if(i % 2 == 0)
                x += a[i];
            else y += a[i];

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0 && x <= y || i % 2 != 0 && x > y)
                a[i] = 1;
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}