#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000006;
int n;
long long a[maxn];
long long s[maxn];

long long cost(long long mod) {
    long long ret = 0;
    for (int i = 1; i <= n; ++i)
        ret += min(s[i] % mod, mod - s[i] % mod);
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    if (s[n] == 1) {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 1e18;
    long long tmp = s[n], p = 2;
    while (p * p <= tmp) {
        if (tmp % p == 0) {
            ans = min(ans, cost(p));
            while (tmp % p == 0)
                tmp /= p;
        }
        ++p;
    }
    if (tmp > 1)
        ans = min(ans, cost(tmp));
    cout << ans << endl;
    return 0;
}