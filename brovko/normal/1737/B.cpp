#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int f(int r)
{
    int ans = 0;

    int L = 0, R = 2e9;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(M * M <= r)
            L = M;
        else R = M;
    }

    ans += L;

    L = 0, R = 2e9;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(M * (M + 1) <= r)
            L = M;
        else R = M;
    }

    ans += L;

    L = 0, R = 2e9;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(M * (M + 2) <= r)
            L = M;
        else R = M;
    }

    ans += L;

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int l, r;
        cin >> l >> r;

        cout << f(r) - f(l - 1) << "\n";
    }
}