#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

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

        if(a > b)
            swap(a, b);

        if(b > c)
            swap(b, c);

        if(a > b)
            swap(a, b);

        if(c == a + b || a % 2 == 0 && b == c || c % 2 == 0 && a == b)
            cout << "YES\n";
        else cout << "NO\n";
    }
}