#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, a[200005], t[200005], b[200005], c[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.pb({a[i], i});
    }

    sort(v.rbegin(), v.rend());

    int ans = 0;

    for(auto to:v)
    {
        int y = to.y;
        b[y] = a[y];

        for(int i = 0; i < n; i++)
        {
            c[i + 1] = c[i] + b[i];
        }

        int Min = 0;

        for(int i = 0; i < n; i++)
            Min = min(Min, c[i + 1]);

        if(Min < 0)
            b[y] = 0;
        else ans++;
    }

    cout << ans;
}