#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b;
    int ans = 0;

    while(n > 0)
    {
        if(b < min(m, n) * a)
        {
            n -= m;
            ans += b;
        }
        else
        {
            n--;
            ans += a;
        }
    }

    cout << ans;
}