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

const int MAXn = 1e3 + 5;
ll x[MAXn], y[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        sort(x + 1, x + 1 + n);
        sort(y + 1, y + 1 + n);
        if (n&1) cout << 1 << endl;
        else cout << (ll)(x[n / 2 + 1] - x[n / 2] + 1) * (ll)(y[n / 2 + 1] - y[n / 2] + 1) << endl;
    }
}