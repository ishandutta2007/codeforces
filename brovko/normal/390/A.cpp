#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x[100005], y[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    set <int> a, b;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        a.insert(x[i]);
        b.insert(y[i]);
    }

    cout << min(a.size(), b.size());
}