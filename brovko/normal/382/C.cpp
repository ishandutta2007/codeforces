#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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
        
    sort(a, a + n);

    if(n == 1)
    {
        cout << -1;
        return 0;
    }

    if(n == 2 && (a[0] + a[1]) % 2 == 0 && a[0] != a[1])
    {
        cout << "3\n" << 2 * a[0] - a[1] << ' ' << (a[0] + a[1]) / 2 << ' ' << 2 * a[1] - a[0];
        return 0;
    }

    set <int> d;

    for(int i = 1; i < n; i++)
        d.insert(a[i] - a[i - 1]);

    if(d.size() == 1)
    {
        if(a[0] == a[1])
            cout << "1\n" << a[0];
        else cout << "2\n" << a[0] - (a[1] - a[0]) << ' ' << a[n - 1] + (a[1] - a[0]);

        return 0;
    }

    for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] != (*d.begin()))
        {
            a[n] = (a[i] + a[i - 1]) / 2;
            break;
        }

    int ans = a[n];

    sort(a, a + n + 1);

    for(int i = 1; i <= n; i++)
        if(a[i] - a[i - 1] != (*d.begin()))
        {
            cout << 0;
            return 0;
        }

    cout << "1\n" << ans;
}