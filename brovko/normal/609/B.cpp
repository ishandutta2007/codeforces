#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a[200005], b[15];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[a[i]]++;

    int ans = 0;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j < i; j++)
            ans += b[i] * b[j];

    cout << ans;
}