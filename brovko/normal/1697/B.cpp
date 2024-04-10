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

    int n, q;
    cin >> n >> q;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.rbegin(), a.rend());

    vector <li> ps(n + 1);

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];

    while(q--)
    {
        int x, y;
        cin >> x >> y;

        cout << ps[x] - ps[x - y] << "\n";
    }
}