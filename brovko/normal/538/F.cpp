#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[200005], y, t[200005], ans[200005];
vector <pair <int, int> > V[200005];

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i <= y; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> v;

    for(int i = 0; i < n; i++)
        v.pb(a[i]);

    sort(v.begin(), v.end());
    map <int, int> m;

    for(int i = 0; i < n; i++)
    {
        if(i == 0 || v[i] != v[i - 1])
            y++;

        m[v[i]] = y - 1;
    }

    for(int i = 0; i < n; i++)
        a[i] = m[a[i]];


    for(int k = 1; k < n; k++)
    {
        for(int i = 0; k * i + 1 < n; i++)
            if(a[i] > 0)
            {
                V[k * i].pb({-k, a[i]});
                V[min(n - 1, k * i + k)].pb({k, a[i]});
            }
    }

    for(int i = 0; i < n; i++)
    {
        inc(a[i], 1);

        for(auto p:V[i])
        {
            int k = p.x, z = p.y;

            if(k < 0)
                ans[-k] -= sum(z - 1);
            else ans[k] += sum(z - 1);
        }
    }

    for(int k = 1; k < n; k++)
        cout << ans[k] << ' ';
}