#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[100005], d[100005];
vector <int> u[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> v;

    for(int i = 0; i < n; i++)
        if(i == 0 || a[i] != a[i - 1])
            v.pb(a[i]);

    n = v.size();
    
    if(n == 1)
    {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        {
            d[v[i]] -= abs(v[i] - v[i - 1]);
            u[v[i]].pb(v[i - 1]);
        }

        if(i < n - 1)
        {
            d[v[i]] -= abs(v[i] - v[i + 1]);
            u[v[i]].pb(v[i + 1]);
        }
    }

    for(int i = 1; i <= m; i++)
        sort(u[i].begin(), u[i].end());

    for(int i = 0; i < n; i++)
    {
        int M = u[v[i]][(int)u[v[i]].size() / 2];

        if(i > 0)
        {
            d[v[i]] += abs(M - v[i - 1]);
        }

        if(i < n - 1)
        {
            d[v[i]] += abs(M - v[i + 1]);
        }
    }

    int ans = 0;

    for(int i = 1; i < n; i++)
        ans += abs(v[i] - v[i - 1]);

    int Min = 0;

//    for(int i = 1; i <= m; i++)
//        cout << d[i] << ' ';
//
//    cout << endl;
//
//    cout << ans << endl;

    for(int i = 1; i <= m; i++)
        Min = min(Min, d[i]);

    cout << ans + Min;
}