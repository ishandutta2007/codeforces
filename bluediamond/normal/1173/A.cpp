#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string sgn(int x)
{
    if (x == 0)
    {
        return "0";
    }
    if (x < 0)
    {
        return "-";
    }
    else
    {
        return "+";
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    int mn = x - y - z;
    int mx = x - y + z;

    if (sgn(mn) == sgn(mx))
    {
        cout << sgn(mn) << "\n";
    }
    else
    {
        cout << "?\n";
    }


}
/**

**/