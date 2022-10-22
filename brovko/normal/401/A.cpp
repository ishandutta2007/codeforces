#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    cout << (abs(s) + x - 1) / x;
}