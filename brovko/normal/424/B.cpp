#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, s, x[1005], y[1005], k[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> k[i];

    ld L = 0, R = 1e9;

    for(int i = 0; i < 100; i++)
    {
        ld M = (L + R) / 2;

        int cnt = s;

        for(int j = 0; j < n; j++)
        {
            if(x[j] * x[j] + y[j] * y[j] <= M * M)
                cnt += k[j];
        }

        if(cnt >= 1000000)
            R = M;
        else L = M;
    }

    if(R > 1e8)
        cout << -1;
    else
    cout << setprecision(20) << R;
}