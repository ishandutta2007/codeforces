#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, cnt, a[205];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> cnt;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = -1e9;

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            vector <int> v, u;

            for(int k = 0; k < n; k++)
                if(k >= i && k <= j)
                    v.pb(a[k]);
                else u.pb(a[k]);

            sort(v.begin(), v.end());
            sort(u.rbegin(), u.rend());

            for(int i = 0; i < min({cnt, (int)v.size(), (int)u.size()}); i++)
                if(v[i] < u[i])
                    swap(v[i], u[i]);

            int s = 0;

            for(auto x:v)
                s += x;

            ans = max(ans, s);
        }

    cout << ans;
}