#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll m = max(max(a, b), c);
        if (2 * m <= a + b + c + 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

}