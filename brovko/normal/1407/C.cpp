#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, a[10005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    set <int> s;

    for(int i = 0; i < n; i++)
        s.insert(i + 1);

    for(int i = 0; i < n - 1; i++)
    {
        int f = 0, x = 0, y = 0;

        for(auto to:s)
        {
            f++;

            if(f == 1)
                x = to;

            if(f == 2)
                y = to;

            if(f == 3)
                break;
        }

        cout << "? " << x << ' ' << y << endl;

        int p;
        cin >> p;

        cout << "? " << y << ' ' << x << endl;

        int q;
        cin >> q;

        if(p > q)
        {
            a[x] = p;
            s.erase(x);
        }
        else
        {
            a[y] = q;
            s.erase(y);
        }
    }

    cout << "! ";

    for(int i = 1; i <= n; i++)
        if(a[i] == 0)
            cout << n << ' ';
        else cout << a[i] << ' ';

    cout << endl;
}