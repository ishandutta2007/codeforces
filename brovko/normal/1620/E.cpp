#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int q, t[500005], x[500005], y[500005], p[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> t[i] >> x[i];

        if(t[i] == 2)
            cin >> y[i];
    }

    for(int i = 0; i < 500005; i++)
        p[i] = i;

    vector <int> v;

    for(int i = q - 1; i >= 0; i--)
    {
        if(t[i] == 1)
            v.pb(p[x[i]]);
        else p[x[i]] = p[y[i]];
    }

    reverse(v.begin(), v.end());

    for(auto z:v)
        cout << z << ' ';
}