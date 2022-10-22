#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, p[200005], q[200005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> p[i];

        cin >> s;

        vector <pair <int, int> > v, u;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                v.pb({p[i], i});
            else u.pb({p[i], i});
        }

        sort(u.begin(), u.end());
        sort(v.begin(), v.end());

        int ans = 0;

        for(int i = 0; i < u.size(); i++)
            q[u[i].y] = ++ans;

        for(int i = 0; i < v.size(); i++)
            q[v[i].y] = ++ans;

        for(int i = 0; i < n; i++)
            cout << q[i] << ' ';

        cout << "\n";
    }
}