#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
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

        int x = 1;

        while(x * (x + 1) / 2 < n)
            x++;

        int y = x * (x + 1) / 2;

        if(n == y - 1)
            cout << x + 1;

        else cout << x;

        cout << "\n";
    }
}