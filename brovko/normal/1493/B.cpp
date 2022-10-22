#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, h, m;
string s;
vector <int> r;

int f(int x, int y)
{
    if(r[y % 10] == -1 || r[y / 10] == -1 || r[x % 10] == -1 || r[x / 10] == -1)
        return 0;

    int x1 = r[y % 10] * 10 + r[y / 10];
    int y1 = r[x % 10] * 10 + r[x / 10];

    if(x1 < h && y1 < m)
        return 1;

    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    r = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

    cin >> t;

    while(t--)
    {
        cin >> h >> m >> s;

        int x = s[0] * 10 + s[1] - '0' * 11;
        int y = s[3] * 10 + s[4] - '0' * 11;

        while(f(x, y) == 0)
        {
            x = (x + (y + 1) / m) % h;
            y = (y + 1) % m;
        }

        cout << x / 10 << x % 10 << ':' << y / 10 << y % 10 << "\n";
    }
}