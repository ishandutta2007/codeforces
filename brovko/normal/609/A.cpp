#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(m > 0)
        {
            m -= a[i];
            ans++;
        }
    }

    cout << ans;
}