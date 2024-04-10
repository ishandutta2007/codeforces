#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if(n == 4)
    {
        cout << "3 5";
        return 0;
    }

    if(n <= 2)
    {
        cout << -1;
        return 0;
    }

    if(n % 2)
    {
        cout << n * n / 2 << ' ' << n * n / 2 + 1;
    }
    else cout << n * n / 4 - 1 << ' ' << n * n / 4 + 1;
}