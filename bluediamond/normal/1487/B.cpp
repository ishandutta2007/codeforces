#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int n, k, b;

int rep(int x) {
        x %= n;
        if (x < 0)
                x += n;
        return x;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                cin >> n >> k;
                b = 0;
                k--;
                int num = n / 2;
                num += (2 * num == n) * (int) 1e9;
                cout << rep(b + k + k / num) + 1 << "\n";
        }
}