#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[25], b[25];
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back({a[i], i});
    }

    sort(v.begin(), v.end());

    for(int i = 1; i < v.size(); i++)
        if(v[i].first == v[i - 1].first)
    {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < v.size(); i++)
    {
        b[v[i].second] = v[(i + 1) % v.size()].second;
    }

    for(int i = 0; i < n; i++)
        cout << a[b[i]] << ' ';
}