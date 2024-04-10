#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[100005];

void f(int l, int r)
{
    if(k >= 2 * n - 1)
        return;

    int m = (l + r) / 2;

    if(2 * (r - l - 1) + k <= 2 * n - 1)
    {
        for(int i = l; i < m; i++)
            swap(a[i], a[l + r - i - 1]);

        k += 2 * (r - l - 1);

        return;
    }

    f(l, m);
    f(m, r);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        a[i] = n - i;

    f(0, n);

    //cout << k << ' ';

    if(k == 2 * n - 1)
    {
        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';
    }
    else cout << -1;
}