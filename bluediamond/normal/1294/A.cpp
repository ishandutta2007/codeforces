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
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int s = (a + b + c + n);
        if (s % 3)
        {
            cout << "NO\n";
            continue;
        }
        s /= 3;
        a = s - a;
        b = s - b;
        c = s - c;
        if (a >= 0 && b >= 0 && c >= 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}