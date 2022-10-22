#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> v;

    map <int, int> m;

    for(int i = 0; i < n; i++)
    {
        if(m[a[i]] > 0)
        {
            v.pb(i + 1);
            m.clear();
        }
        else
        {
            m[a[i]]++;
        }
    }

    if(v.size() == 0)
    {
        cout << -1;
        return 0;
    }

    cout << v.size() << "\n";

    v[v.size() - 1] = n;

    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0)
            cout << 1 << ' ' << v[i] << "\n";
        else cout << v[i - 1] + 1 << ' ' << v[i] << "\n";
    }
}