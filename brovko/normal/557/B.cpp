#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, w, a[400005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;

    for(int i = 0; i < 2 * n; i++)
        cin >> a[i];

    sort(a, a + 2 * n);

    ld x = min((ld)a[0], (ld)a[n] / 2);

    cout << setprecision(20) << min((ld)w, 3 * n * x);
}