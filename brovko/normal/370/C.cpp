#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[5005], k[105], b[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for(int i = 0; i < n; i++)
        k[a[i]]++;

    int Max = 0;

    for(int i = 0; i <= m; i++)
        if(k[i] > k[Max])
            Max = i;

    for(int i = 0; i < n; i++)
        b[(i + k[Max]) % n] = a[i];

    int ans = 0;

    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            ans++;

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ' << b[i] << "\n";
}