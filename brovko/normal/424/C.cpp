#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, p[1000005], px[1000005];

int f(int n, int i)
{
    int q = n / i, r = n % i;

    if(q % 2 == 0)
        return px[r];

    return (px[i - 1] ^ px[r]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i < 1000005; i++)
        px[i] = (px[i - 1] ^ i);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> p[i];

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans ^= p[i];

    for(int i = 1; i <= n; i++)
        ans ^= f(n, i);

    cout << ans;
}