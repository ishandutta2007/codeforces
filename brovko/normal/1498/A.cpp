#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n;

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int sum(int x)
{
    if(x == 0)
        return 0;

    return x % 10 + sum(x / 10);
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

        while(gcd(n, sum(n)) == 1)
            n++;

        cout << n << "\n";
    }
}