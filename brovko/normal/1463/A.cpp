#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair

using namespace std;

int t, a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c;

        if((a + b + c) % 9 == 0 && (a + b + c) / 9 <= min({a, b, c}))
            cout << "YES\n";
        else cout << "NO\n";
    }
}