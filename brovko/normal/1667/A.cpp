#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 1e18;

    for(int i = 0; i < n; i++)
    {
        int x = 0, s = 0;

        for(int j = i - 1; j >= 0; j--)
        {
            assert(x <= 0);

            int k = -x / a[j] + 1;
            x = -k * a[j];
            s += k;

//            cout << k << ' ' << x << ' ' << j << endl;
        }

        x = 0;

        for(int j = i + 1; j < n; j++)
        {
            assert(x >= 0);

            int k = x / a[j] + 1;
            x = k * a[j];
            s += k;
        }

        ans = min(ans, s);

//        cout << s << ' ';
    }

    cout << ans;
}