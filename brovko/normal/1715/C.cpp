#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 1e5 + 5;

int n, a[N];

li f(int i)
{
    if(i < 0 || i >= n)
        return 0;

    if(i == 0 || a[i] != a[i - 1])
        return (i + 1) * 1ll * (n - i);

    return n - i;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    li ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += f(i);
    }

    while(m--)
    {
        int x, y;
        cin >> x >> y;

        x--;

        ans -= f(x) + f(x - 1) + f(x + 1);
        a[x] = y;
        ans += f(x) + f(x - 1) + f(x + 1);

//        for(int i = 0; i < n; i++)
//            cout << f(i) << ' ';

        cout << ans << "\n";
    }
}