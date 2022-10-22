#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            b[i] = a[n / 2 + i / 2];
        else b[i] = a[i / 2];
    }

    int ans = 0;

    for(int i = 1; i < n - 1; i++)
        if(b[i] < b[i - 1] && b[i] < b[i + 1])
            ans++;

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
        cout << b[i] << ' ';
}