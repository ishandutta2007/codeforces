#include <bits/stdc++.h>

using namespace std;

bool ok(int t, int s, int x)
{
    x -= t;
    if (x < 0)
    {
        return 0;
    }
    if (x == 0)
    {
        return 1;
    }
    if (x == 1)
    {
        return 0;
    }
    return (x % s <= 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, s, x;
    cin >> t >> s >> x;

    if (ok(t, s, x))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

}