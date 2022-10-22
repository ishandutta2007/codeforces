#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[100005], b[105];

int f(int x)
{
    int ans = 0;

    while(x)
    {
        ans++;
        x /= 2;
    }

    return ans;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        for(int i = 0; i < 105; i++)
            b[i] = 0;

        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            b[f(a[i])]++;

        int ans = 0;

        for(int i = 0; i < 105; i++)
            ans += b[i] * (b[i] - 1) / 2;

        cout << ans << "\n";
    }
}