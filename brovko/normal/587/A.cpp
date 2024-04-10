#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[1000005], b[1000105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[a[i]]++;

    int ans = 0;

    for(int i = 0; i <= 1000100; i++)
    {
        b[i + 1] += b[i] / 2;
        b[i] %= 2;
        ans += b[i];
    }

    cout << ans;
}