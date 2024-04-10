#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int q, l, r, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> q;
    while(q--)
    {
        cin >> l >> r >> d;
        if(d<l)
            cout << d;
        else cout << (r+d)/d*d;
        cout << "\n";
    }
}