#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                ll n;
                cin >> n;
                for (ll i = 4; i - 1 <= n; i *= 2) {
                        if (n % (i - 1) == 0) {
                                cout << n / (i - 1) << "\n";
                                break;
                        }
                }

        }

}