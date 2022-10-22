#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, c, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int Max = 0;

    for(int i = 1; i < n; i++)
        Max = max(Max, a[i - 1] - a[i]);

    cout << max(0ll, Max - c);
}