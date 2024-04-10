#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cout << n - (n + 1) / 3 << "\n";

    if(n == 1)
    {
        cout << "1 1";
        return 0;
    }

    while(n % 3 != 2)
    {
        cout << n << ' ' << n << "\n";
        n--;
    }

    int x = -1;
    n -= (n + 1) / 3;

    for(int i = 1; i <= n; i++)
    {
        x += 2;

        if(x > n)
            x = 2;

        cout << i << ' ' << x << "\n";
    }
}