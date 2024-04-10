#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x[100005], h[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> h[i];

    int ans = 0, X = -1e9;

    for(int i = 0; i < n; i++)
    {
        if(x[i] - X > h[i])
        {
            ans++;
            X = x[i];
        }
        else if(i == n - 1 || x[i + 1] - x[i] > h[i])
        {
            ans++;
            X = x[i] + h[i];
        }
        else X = x[i];
    }

    cout << ans;
}