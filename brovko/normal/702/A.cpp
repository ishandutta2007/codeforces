#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = 1;
    int ans = 0;

    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[i - 1])
        {
            x++;
        }
        else
        {
            ans = max(ans, x);
            x = 1;
        }
    }

    ans = max(ans, x);

    cout << ans;
}