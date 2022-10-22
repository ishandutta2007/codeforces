#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, q, a[100005], b[100005], x;
vector <int> v;

int f()
{
    int L = 0;
    int R = (int)v.size() - 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;
        if(v[M] >= -x)
            R = M;
        else L = M;
    }

    return min(abs(v[L] + x), abs(v[R] + x));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            x += a[i];
        else x -= a[i];
    }

    int y = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % 2)
            y += b[i];
        else y -= b[i];
    }

    v.push_back(y);

    for(int i = n; i < m; i++)
    {
        y += b[i - n];

        y = -y;

        if(n % 2 == 0)
            y += b[i];
        else y -= b[i];

        v.push_back(y);
    }

    sort(v.begin(), v.end());

    /*for(auto to:v)
        cout << to << ' ';
    cout << "\n";

    cout << "! " << x << "\n";*/

    cout << f() << "\n";

    while(q--)
    {
        int l, r, d;
        cin >> l >> r >> d;

        if(l % 2 == 0 && r % 2 == 0)
            x -= d;
        else if(l % 2 != 0 && r % 2 != 0)
            x += d;

        cout << f() << "\n";
    }
}