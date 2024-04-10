#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if(k > 1e9 || n < k * (k + 1) / 2)
    {
        cout << -1;
        return 0;
    }

    int Max = 1;

    for(int i = 1; i * i <= n; i++)
        if(n % i == 0)
    {
        if(n / i >= k * (k + 1) / 2)
            Max = max(Max, i);

        if(i >= k * (k + 1) / 2)
            Max = max(Max, n / i);
    }

    for(int i = 1; i < k; i++)
        {
            cout << i * Max << ' ';
            n -= i * Max;
        }

    cout << n;
}