#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005], b[1000005], c[100005], x, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        x += a[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
        x -= b[i];
        y += b[i];
    }

    for(int i = 0; i < n - 2; i++)
    {
        cin >> c[i];
        y -= c[i];
    }

    cout << x << "\n" << y;
}