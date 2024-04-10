#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000;
ll n,m,k;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
int main() {
    cin >> n >> m >> k;
    if (k <= n-1) {
        cout << k + 1 << " " << 1 <<endl;
        return 0;
    }
    ll myans = (k - n) / (m - 1);
    if (((k - n) / (m - 1)) % 2 == 1) {
        ll ans2 = m -  ((k - n) % (m - 1));
        cout << n - myans << " " << ans2 << endl;
        return 0;
    } else {
        cout << n - myans << " " << 2 + ((k - n) % (m - 1)) << endl;
    }
    return 0;
}