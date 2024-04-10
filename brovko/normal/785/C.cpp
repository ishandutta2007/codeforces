#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int L = 0;
    int R = 2e9;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int k = n - m - M * (M + 1) / 2;

        if(k <= 0)
            R = M;
        else L = M;
    }

    cout << min(R + m, n);
}