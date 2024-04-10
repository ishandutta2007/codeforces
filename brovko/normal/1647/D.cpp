#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, x, d;

int lp(int x)
{
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return i;

    return 1;
}

bool g(int x)
{
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0 && i % d != 0 && x / i % d != 0)
            return 1;

    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x >> d;

        int N = x;
        int k = 0;

        while(N % d == 0)
        {
            N /= d;
            k++;
        }

        if(k >= 2 && lp(N) > 1 || k >= 3 && lp(d) > 1 && g(N * d) || k >= 4 && lp(d) > 1)
            cout << "YES\n";
        else cout << "NO\n";
    }
}