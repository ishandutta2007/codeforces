#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, B, x, y, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> B >> x >> y;

        a[0] = 0;
        int s = 0;

        for(int i = 1; i <= n; i++)
        {
            if(a[i - 1] + x <= B)
                a[i] = a[i - 1] + x;
            else a[i] = a[i - 1] - y;

            s += a[i];
        }

        cout << s << "\n";
    }
}