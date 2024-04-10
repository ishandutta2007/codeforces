#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;

    for(int i = 1; i < n; i++)
    {
        b[i] = a[i] - a[i - 1];
        s += max(0ll, b[i]);
    }

    cout << (s + a[0] + 1 + (int)1e18) / 2 - (int)5e17 << "\n";

    int q;
    cin >> q;

    while(q--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        l--;
        r--;

        if(l == 0)
            a[0] += x;
        else
        {
            s -= max(0ll, b[l]);
            b[l] += x;
            s += max(0ll, b[l]);
        }

        if(r < n - 1)
        {
            s -= max(0ll, b[r + 1]);
            b[r + 1] -= x;
            s += max(0ll, b[r + 1]);
        }

        cout << (s + a[0] + 1 + (int)1e18) / 2 - (int)5e17 << "\n";
    }
}