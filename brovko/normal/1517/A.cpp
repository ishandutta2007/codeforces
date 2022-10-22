#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n;

int f(int x)
{
    if(x == 0)
        return 0;

    return x % 10 + f(x / 10);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n % 2050 != 0)
            cout << -1 << "\n";
        else cout << f(n / 2050) << "\n";
    }
}