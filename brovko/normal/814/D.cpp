#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x[1005], y[1005], r[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int k = 0;

        for(int j = 0; j < n; j++)
        {
            if(r[j] > r[i] && (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) < r[j] * r[j])
                k++;
        }

        if(k == 0 || k % 2)
            ans += r[i] * r[i];
        else ans -= r[i] * r[i];
    }

    cout << setprecision(20) << (ld)3.14159265358979323846 * ans;
}