#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int t, n, a[105], b[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < 105; i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i]]++;
        }

        int x = 0, y = 0;

        while(b[x])
            x++;

        while(b[y] >= 2)
            y++;

        cout << x + y << "\n";
    }
}