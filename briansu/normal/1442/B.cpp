#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MOD = 998244353;
const int MAXn = 2e5 + 5;
int a[MAXn], b[MAXn], p[MAXn], d[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i], d[i] = 0;
        for (int i = 1; i <= k; i++)
            cin >> b[i];
        for (int i = 1; i <= n; i++)
            p[a[i]] = i;
        for (int i = 1; i <= k; i++)
            d[p[b[i]]] = i;
        ll ans = 1;
        d[0] = d[n + 1] = n + 1;
        for (int i = 1; i <= n; i++)
            if (d[i] != 0)
                ans = ans * ((d[i - 1] < d[i]) + (d[i + 1] < d[i])) % MOD;
        cout << ans << "\n";
    }
}