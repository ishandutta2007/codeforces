#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, r, b, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> r >> b >> d;

        if(abs(r - b) > min(r, b) * d)
            cout << "NO\n";
        else cout << "YES\n";
    }
}