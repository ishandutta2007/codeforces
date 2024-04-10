#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int q, Max, Max2, x, y;
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> q;
    while(q--)
    {
        cin >> c >> x >> y;
        if(c=='+')
        {
            if(x>y)
                swap(x, y);
            Max=max(Max, y);
            Max2=max(Max2, x);
        }
        else
        {
           // cout << x << ' ' << y << ' ' << Max << ' ' << Max2 << endl;
            if(x>y)
                swap(x, y);
            if(x>=Max2 && y>=Max)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
}