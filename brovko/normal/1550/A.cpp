#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;

int t, s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;

        int x = 1;

        while(x * x < s)
            x++;

        cout << x << "\n";
    }
}