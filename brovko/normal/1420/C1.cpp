#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, q, a[300005], Min[300005], Max[300005];

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> q;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        Min[n - 1] = 0;
        Max[n - 1] = a[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            Min[i] = min(Min[i + 1], a[i] - Max[i + 1]);
            Max[i] = max(Max[i + 1], a[i] - Min[i + 1]);
        }

        cout << Max[0] << "\n";
    }
}