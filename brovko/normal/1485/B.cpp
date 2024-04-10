#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, q, k, a[100005], ps[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    ps[0] = 0;

    for(int i = 1; i < n; i++)
    {
        ps[i] = ps[i - 1] + a[i + 1] - a[i - 1] - 2;
    }

    while(q--)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        if(l == r)
            cout << k - 1 << "\n";
        else cout << a[l + 1] - 2 + k - a[r - 1] - 1 + ps[r - 1] - ps[l] << "\n";
    }
}