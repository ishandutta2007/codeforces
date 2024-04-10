#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> a(n), b(m);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = max(a[n - 1], a[0] * 2);

    if(b[0] <= x)
        cout << -1;
    else cout << x;
}