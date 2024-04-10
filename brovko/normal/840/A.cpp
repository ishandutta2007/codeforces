#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], b[200005], c[200005];
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
    }

    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        v.push_back({b[i], i});
    }

    sort(v.begin(), v.end());
    sort(a, a + n);

    for(int i = 0; i < n; i++)
    {
        c[v[i].second] = a[n - 1 - i];
    }

    for(int i = 0; i < n; i++)
        cout << c[i] << ' ';
}