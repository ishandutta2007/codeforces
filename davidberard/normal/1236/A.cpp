#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int a, b, c;
int t;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    for (int tt=0;tt<t;++tt) {
        cin >> a >> b >> c;
        int ans = 0;
        int m = min(c/2, b);
        b -= m;
        c -= m*2;
        ans += 3*m;

        m = min(b/2, a);
        a -= m;
        b -= m*2;
        ans += 3*m;

        cout << ans << "\n";
    }
    return 0;
}