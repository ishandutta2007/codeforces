#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[105], b[105], used[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            if(used[j] == 0 && abs(a[i] - b[j]) <= 1)
            {
                used[j] = 1;
                ans++;
                break;
            }
    }

    cout << ans;
}