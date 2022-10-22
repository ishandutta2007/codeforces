#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, a[100005], s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }

    if(s + n - 1 == x)
        cout << "YES";
    else cout << "NO";
}