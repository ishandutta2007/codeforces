#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1)
    {
        cout << "1 1\n";
        cout << -a[0];

        cout << "\n1 1\n";
        cout << 0;

        cout << "\n1 1\n";
        cout << 0;

        return 0;
    }

    cout << 1 << ' ' << n << "\n";

    for(int i = 0; i < n; i++)
    {
        int x = n * (n - 2) * (a[i] % (n - 1));
        cout << x << ' ';
        a[i] += x;
    }

    cout << "\n";

    cout << 1 << ' ' << n - 1 << "\n";

    for(int i = 0; i < n - 1; i++)
    {
        cout << -a[i] << ' ';
    }

    cout << "\n";

    cout << n << ' ' << n << "\n" << -a[n - 1];
}