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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    if (n >= 50)
        return cout << 0 << endl, 0;
    if (n == 1)
        return cout << (r - l + 1) << endl, 0;
    if (n == 2)
        return cout << (ll)(r - l + 1) * (r - l) << endl, 0;
    vector<int> pw(1);
    for (int x = 1; ; x++) {
        int res = 1;
        for (int i = 1; i < n && res <= r; i++, res *= x);
        if (res > r)
            break;
        pw.pb(res);
    }
    ll ans = 0;
    for (int a = 1; a < SZ(pw); a++) {
        for (int b = a + 1; b < SZ(pw); b++) {
            if (gcd(a, b) == 1)
                ans += max(0, r / pw[b] - (l - 1) / pw[a]);            
        }
    }
    cout << ans * 2 << endl;
}