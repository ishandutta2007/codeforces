#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[105];

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

        sort(a, a + n);

        if(a[0] < 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << 101 << "\n";

            for(int i = 0; i < 101; i++)
                cout << i << ' ';

            cout << "\n";
        }
    }
}