#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 200010;
const int mod = 998244353;

int n, ans, d[N];

int main()
{
    int i, u, v;

    scanf("%d", &n);
    ans = n;

    for (i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        ans = (ll) ans * (++d[u]) % mod * (++d[v]) % mod;
    }

    cout << ans;

    return 0;
}