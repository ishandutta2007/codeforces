#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 300300;

ll dp[N][2];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ll x = 0, y = 0;
    for (int i=1; i<=n; ++i) {
        int a;
        cin >> a;
        if (i%2) {
            x += a/2;
            y += a-a/2;
        } else {
            x += a-a/2;
            y += a/2;
        }
    }
    cerr << ":: " << x << " " << y << endl;
    cout << min(x, y) << endl;
    return 0;
}