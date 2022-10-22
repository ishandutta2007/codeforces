#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int L = 0, R = n / 2 + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;
        int F = 1;

        for(int i = 0; i < M; i++)
            if(a[n - M + i] < 2 * a[i])
                F = 0;

        if(F)
            L = M;
        else R = M;
    }

    cout << n - L;
}