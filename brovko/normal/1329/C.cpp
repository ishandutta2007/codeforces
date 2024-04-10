#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = (1 << 22) + 5;

int t, h, g, a[N];

void f(int i)
{
    int l = 2 * i, r = 2 * i + 1;

    if(a[l] == 0 && a[r] == 0)
        a[i] = 0;

    else if(a[l] > a[r])
    {
        a[i] = a[l];
        f(l);
    }
    else
    {
        a[i] = a[r];
        f(r);
    }
}

bool good(int i)
{
    if(a[2 * i] == 0 && a[2 * i + 1] == 0)
        return (i >= (1 << g));

    if(a[2 * i] > a[2 * i + 1])
        return good(2 * i);

    return good(2 * i + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> h >> g;

        for(int i = 1; i < (1 << h); i++)
            cin >> a[i];

//        {
//            f(1);
//
//            for(int i = 1; i <= (1 << h); i++)
//                cout << a[i] << ' ';
//
//            cout << endl;
//        }
//
//        return 0;

        vector <int> v;
        int ans = 0;

        for(int i = 1; i < (1 << h); i++)
            ans += a[i];

        for(int i = 1; i < (1 << h); i++)
            if(a[i])
            {
                while(good(i))
                {
                    ans -= a[i];
                    v.push_back(i);
                    f(i);
                }
            }

        cout << ans << "\n";

        for(auto x:v)
            cout << x << ' ';

        cout << "\n";

        for(int i = 1; i < (1 << h); i++)
            a[i] = 0;
    }
}