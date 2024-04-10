#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[205];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < 2 * n; i++)
        cin >> a[i];

    sort(a, a + 2 * n);

    if(a[n - 1] == a[n])
        cout << "NO";
    else cout << "YES";
}