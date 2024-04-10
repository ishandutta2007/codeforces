#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[200005], st[200005][20], k[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        st[i][0] = a[i];

    for(int j = 1; j < 20; j++)
        for(int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        int g = 0, r = i;

        for(int j = 19; j >= 0; j--)
            if(r + (1 << j) <= n && __gcd(g, st[r][j]) >= r - i + (1 << j))
            {
                g = __gcd(g, st[r][j]);
                r += (1 << j);
            }

        if(g == r - i)
        {
            v.pb({r - 1, i});
        }
    }

    sort(v.begin(), v.end());

    int Max = -1e9;

    for(auto x:v)
    {
//        cout << x.x << ' ' << x.y << endl;

        if(x.y > Max)
        {
            Max = x.x;
            k[Max] = 1;
        }
    }

    for(int i = 1; i < n; i++)
        k[i] += k[i - 1];

    for(int i = 0; i < n; i++)
        cout << k[i] << ' ';
}