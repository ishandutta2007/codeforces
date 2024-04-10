#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a[2005], b[2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> b[i];

    vector <pair <int, int> > v;
    ll s1 = 0, s2 = 0;

    for(int i = 0; i < n; i++)
        s1 += a[i];

    for(int i = 0; i < m; i++)
        s2 += b[i];

    ll ans = abs(s1 - s2);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(abs((s1 - a[i] + b[j]) - (s2 - b[j] + a[i])) < ans)
            {
                ans = abs((s1 - a[i] + b[j]) - (s2 - b[j] + a[i]));
                v = {mp(i, j)};
            }

    vector <vector <int> > p2, q2;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < i; j++)
        {
            p2.pb({b[i] + b[j], i, j});
        }

    sort(p2.begin(), p2.end());

    for(auto to:p2)
        if(q2.size() == 0 || q2.rbegin()[0] != to)
            q2.pb(to);

    swap(p2, q2);

    if(p2.size() > 0)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < i; j++)
    {
        vector <int> to = {a[i] + a[j], i, j};
        int L = -1, R = p2.size() - 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(abs((s1 - to[0] + p2[M][0]) - (s2 - p2[M][0] + to[0])) < abs((s1 - to[0] + p2[M + 1][0]) - (s2 - p2[M + 1][0] + to[0])))
               R = M;
               else L = M;
        }

        if(abs((s1 - to[0] + p2[R][0]) - (s2 - p2[R][0] + to[0])) < ans)
        {
            ans = abs((s1 - to[0] + p2[R][0]) - (s2 - p2[R][0] + to[0]));
            v = {mp(to[1], p2[R][1]), mp(to[2], p2[R][2])};
        }
    }

    cout << ans << "\n" << v.size() << "\n";

    for(auto to:v)
        cout << to.x + 1 << ' ' << to.y + 1 << "\n";
}