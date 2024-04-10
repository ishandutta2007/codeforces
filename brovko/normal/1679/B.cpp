#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> t(n);

    li ans = 0, T = 0, X = 0, tx = -1;

    for(int i = 0; i < n; i++)
        ans += a[i];

    while(q--)
    {
        T++;

        int _;
        cin >> _;

        if(_ == 1)
        {
            int i, x;
            cin >> i >> x;
            i--;

            int val = a[i];

            if(tx > t[i])
                val = X;

            ans += x - val;
            a[i] = x;
            t[i] = T;
        }
        else
        {
            int x;
            cin >> x;

            ans = x * 1ll * n;
            tx = T;
            X = x;
        }

        cout << ans << "\n";
    }
}