#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair

using namespace std;

int t, n, a[200005], b[200005];

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

        for(int i = 0; i < n; i++)
            b[i] = a[i] - i - 1;

        int y = 1e9;
        int Max = n;

        for(int i = n - 1; i >= 0; i--)
        {
            y = min(y - 1, b[i]);

            if(y >= 1)
                Max--;
        }

        for(int i = 0; i < n; i++)
            b[i] = i - a[i] + n + 1;

        int Min = 0;
        y = 1e9;


        for(int i = 0; i < n; i++)
        {
            y = min(y - 1, b[i]);

            if(y >= 1)
                Min++;
        }

        cout << Min - Max + 1 << "\n";
    }
}