#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
ll a[maxn], n, b, k, s, r;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> b >> s;
        r = s - b * k;
        if (!(r >= 0))
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            fill(a + 1, a + 1 + n, 0);
            a[1] = b * k;
            for (int i = 1; i <= n; ++i)
            {
                a[i] += r >= k ? k - 1 : r;
                r = r >= k ? r - k + 1 : 0;
            }
            if (r )
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                for (int i = 1; i <= n; ++i)
                    cout << a[i] << ' ';
                cout << endl;
            }
        }
    }
    return 0;
}