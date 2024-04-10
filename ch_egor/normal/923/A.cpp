#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui32;
const long long INFLL = 1e18;

using namespace std;

const int MAXN = 1000 * 1000;

int p[MAXN + 1];

vector<int> fact(int x) {
    vector<int> res;
    while (x > 1) {
        res.push_back(p[x]);
        while (x > 1 && x % p[x] == 0) {
            x /= p[x];
        }
    }
    return res;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int x2;
    cin >> x2;

    for (int i = 2; i <= MAXN; i++) {
        if (!p[i]) {
            p[i] = i;
            for (int j = i + i; j <= MAXN; j += i) {
                p[j] = i;
            }
        }
    }

    vector<int> pr = fact(x2);

    int ans = 1e9;

    for (auto p2 : pr) {
        for (int x1 = p2 + 1; x1 <= x2; x1++) {
            int k2 = x2 / p2;
            if ((k2 - 1) * p2 >= x1) {
                continue;
            }
            vector<int> prX1 = fact(x1);
            for (auto p1 : prX1) {
                int k1 = x1 / p1;
                if (p1 >= max(3, (k1 - 1) * p1 + 1)) {
                    continue;
                }
                ans = min(ans, max(3, (k1 - 1) * p1 + 1));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}