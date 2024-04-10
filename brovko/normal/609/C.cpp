#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    for(int i = 0; i < n; i++)
    {
        int x = s / (n - i);
        s -= x;
        b[i] = x;
    }

    sort(a, a + n);

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans += max(0ll, a[i] - b[i]);

    cout << ans;
}