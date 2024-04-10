#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace sol {
// actual solution start here

#define maxn 201010
int n;
int a[maxn];
int b[maxn];
int qmem[maxn], *h = qmem, *t = qmem - 1;

int main() {
    cin >> n;
    memset(b, -1, sizeof(b));
    rep(i, n) {
        cin >> a[i];
        if (a[i] == 0) {
            *(++t) = i;
            b[i] = 0;
        }
    }
    while (h <= t) {
        int u = *(h++);
        clog << u << endl;
        if (u > 0 and b[u - 1] == -1) {
            b[u - 1] = b[u] + 1;
            *(++t) = u - 1;
        }
        if (u < n - 1 and b[u + 1] == -1) {
            b[u + 1] = b[u] + 1;
            *(++t) = u + 1;
        }
    }

    rep(i, n) cout << b[i] << ' ';

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return sol::main();
}