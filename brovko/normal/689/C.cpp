#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int m;

int f(int n)
{
    int ans = 0;

    for(int k = 2; k * k * k <= n; k++)
        ans += n / (k * k * k);

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;

    int L = 0;
    int R = 1e18;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(f(M) >= m)
            R = M;
        else L = M;
    }

    if(f(R) == m)
        cout << R;
    else cout << -1;
}