#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back


using namespace std;

int t, n, a[505];

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

        int x = 0;

        while(x < n && a[x] == x + 1)
            x++;

        int y = 0;

        for(int i = 0; i < n; i++)
            if(a[i] == x + 1)
                y = i;

        if(x < n)
            reverse(a + x, a + y + 1);

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}