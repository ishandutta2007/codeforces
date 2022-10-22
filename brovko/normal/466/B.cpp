#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;

    int x = 3e9, y = 3e9;

    for(int i = a; i <= a + 1000000; i++)
    {
        int B = max(b, (6 * n + i - 1) / i);

        if(i * B < x * y)
        {
            x = i;
            y = B;
        }
    }

    for(int i = b; i <= b + 1000000; i++)
    {
        int A = max(a, (6 * n + i - 1) / i);

        if(i * A < x * y)
        {
            x = A;
            y = i;
        }
    }

    cout << x * y << "\n" << x << ' ' << y;
}