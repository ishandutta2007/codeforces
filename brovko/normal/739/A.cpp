#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, l[100005], r[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int mex = 1e9;

    for(int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];

        mex = min(mex, r[i] - l[i] + 1);
    }

    cout << mex << "\n";

    for(int i = 0; i < n; i++)
        cout << i % mex << ' ';
}