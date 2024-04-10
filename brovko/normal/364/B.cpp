#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, d, a[55];
bitset <500005> b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    b[0] = 1;

    for(int i = 0; i < n; i++)
        b |= (b << a[i]);

    vector <int> v;

    for(int i = 0; i < 500005; i++)
        if(b[i])
            v.pb(i);

//    for(auto x:v)
//        cout << x << ' ';
//
//    cout << endl;

    int z = 0, ans = 0;

    while(true)
    {
        int x = z;

        while(z < v.size() && v[z] - v[x] <= d)
            z++;

        z--;

        if(z == x)
        {
            cout << v[z] << ' ' << ans;
            return 0;
        }

        ans++;
    }
}