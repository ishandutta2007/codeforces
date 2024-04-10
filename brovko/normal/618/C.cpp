#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, x[100005], y[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector <vector <int> > v;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        v.pb({x[i], y[i], i});
    }

    sort(v.begin(), v.end());

    cout << v[0][2] + 1 << ' ' << v[1][2] + 1 << ' ';

    for(int i = 2; i < n; i++)
    {
        if((v[i][0] - v[0][0]) * (v[1][1] - v[0][1]) != (v[i][1] - v[0][1]) * (v[1][0] - v[0][0]))
        {
            cout << v[i][2] + 1;
            return 0;
        }
    }
}