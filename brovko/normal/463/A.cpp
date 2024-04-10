#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, s, a[105], b[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int ans = -1;

    for(int i = 0; i < n; i++)
        if(100 * a[i] + b[i] <= 100 * s)
            ans = max(ans, (100 - b[i]) % 100);

    cout << ans;
}