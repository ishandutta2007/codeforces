#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, l, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        if((r + 1) / 2 >= l)
            cout << (r - 1) / 2 << "\n";
        else cout << r % l << "\n";
    }
}