#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[100005], b[100005];
string s[100005];
vector <pair <int, int> > v[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> s[i] >> a[i] >> b[i];

        v[a[i]].push_back({b[i], i});
    }

    for(int i = 1; i <= m; i++)
        {
            sort(v[i].rbegin(), v[i].rend());

            if(v[i].size() > 2 && v[i][1].first == v[i][2].first)
                cout << "?\n";
            else cout << s[v[i][0].second] << ' ' << s[v[i][1].second] << "\n";
        }
}