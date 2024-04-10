#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n;

bool f(int x)
{
    int y = round(sqrt(x));

    return (y * y == x);
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

        if(n % 2 == 0 && (f(n) || f(n / 2)))
            cout << "YES\n";
        else cout << "NO\n";
    }
}