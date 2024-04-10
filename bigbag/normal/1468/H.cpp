/**
 *  created: 25/12/2020, 15:35:50
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 200222, inf = 1000111222;

int t, n, k, m, f[max_n];

bool ok() {
    if ((n - m) % (k - 1)) {
        return false;
    }
    const int x = (k - 1) / 2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            if (cnt >= x && (n - m - cnt) >= x) {
                return true;
            }
        } else {
            ++cnt;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &k, &m);
        fill(f, f + n, 0);
        for (int i = 0; i < m; ++i) {
            int x;
            scanf("%d", &x);
            --x;
            f[x] = 1;
        }
        if (ok()) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}