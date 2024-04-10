#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int x = 2;

        if(n % 3 == 1)
            x = 1;

        while(n > 0)
        {
            n -= x;
            cout << x;
            x = 3 - x;
        }

        cout << "\n";
    }
}