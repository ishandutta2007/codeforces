/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

int n;

struct Direction
{
    int a, b;
    int sga, sgb;
};

bool operator < (const Direction &u, const Direction &v)
{
    return make_pair(1LL * u.a * v.b, make_pair(u.sga, u.sgb)) < make_pair(1LL * v.a * u.b, make_pair(v.sga, v.sgb));
}

map <Direction, int> mp;

Direction inv (Direction d)
{
    d.sga *= -1;
    d.sgb *= -1;
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll ans = 0;
        mp.clear();
        for(int i = 1; i <= n; i++)
        {
            int xa, ya, xb, yb;
            cin >> xa >> ya >> xb >> yb;
            Direction d;
            d.a = abs(xa - xb);
            d.b = abs(ya - yb);
            if(xa < xb)
                d.sga = -1;
            else if(xa > xb)
                d.sga = +1;
            else
                d.sga = 0;
            if(ya < yb)
                d.sgb = -1;
            else if(ya > yb)
                d.sgb = +1;
            else
                d.sgb = 0;
            ans += mp[inv(d)];
            mp[d]++;
        }
        cout << ans << "\n";
    }
    return 0;
}