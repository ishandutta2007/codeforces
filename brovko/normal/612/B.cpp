#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[200005], b[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]] = i;
    }

    int ans = 0;

    for(int i = 2; i <= n; i++)
        ans += abs(b[i] - b[i - 1]);

    cout << ans;
}