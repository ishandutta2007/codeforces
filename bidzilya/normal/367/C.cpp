#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_m = 1e5 + 100;

int n, m;
int w[max_m];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> w[i] >> w[i];
    }
    sort(w, w + m);
    if (n == 1) {
        cout << w[m - 1] << endl;
    } else if (m == 1) {
        cout << w[0] << endl;
    } else if (m == 2) {
        cout << w[0] + w[1] << endl;
    } else {
        ll ans = w[m - 1] + w[m - 2];
        for (int cm = 3; cm <= m; ++cm) {
            ll cnt;
            if (cm & 1) {
                cnt = 1LL * cm * (cm - 1) / 2 + 1;
            } else {
                cnt = 1LL * (cm - 1) * cm / 2 + 1;
                cnt += (cm - 2) / 2;
            }
            if (cnt <= n) {
                ans += w[m - cm];
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}