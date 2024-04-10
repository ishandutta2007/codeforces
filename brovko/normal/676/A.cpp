#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0;
    int r = n - 1;

    while(a[l] != 1 && a[l] != n)
        l++;

    while(a[r] != 1 && a[r] != n)
        r--;

    cout << max(r, n - 1 - l);
}