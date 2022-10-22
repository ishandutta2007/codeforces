#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[5005], b[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    ld Min=1e9;

    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        Min=min(Min, (ld)a[i]/b[i]);
    }
    cout << setprecision(20) << m*Min;
}