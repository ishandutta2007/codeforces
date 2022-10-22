#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define li long long

using namespace std;

int n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i + 1];

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans += abs(a[i] - a[i + 1]);

    cout << ans;
}