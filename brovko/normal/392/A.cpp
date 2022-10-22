#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;

int q(int x)
{
    int L = 0, R = 1e9;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(M * M <= x)
            L = M;
        else R = M;
    }

    return L;
}

int f(int x)
{
    ld y = sqrt((ld)n * n - (ld)x * x);
    y += 1e-8;

    return y;

//    return q(n * n - x * x);
}

int g(int x)
{
    return f(x - 1) - f(x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    if(n == 0)
    {
        cout << 1;
        return 0;
    }

    int x = n;
    int ans = 4 * n;

    while(2 * x * x >= n * n)
    {
        ans += 4 * max(0ll, g(x) - 1);
        x--;
    }

    cout << ans;
}