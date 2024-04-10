#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 301010
#define maxbit 20
int first_get[maxn][maxbit];
int cur[maxbit];
int n, q;
int a[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    rep(i, n) cin >> a[i];
    rep(i, maxbit) first_get[n][i] = n;
    rep(i, maxbit) cur[i] = n;

    for (int i = n; i--; ) {
        rep(f, maxbit) first_get[i][f] = n;

        rep(f, maxbit) if ((a[i] >> f) & 1) {
            first_get[i][f] = i;
            rep(g, maxbit) 
                first_get[i][g] = min(first_get[i][g], first_get[cur[f]][g]);
            cur[f] = i;
        }
    }

    while (q--) {
        int x, y; cin >> x >> y;
        --x, --y;
        bool ok = false;
        rep(f, maxbit) if ((a[y] >> f) & 1) {
            if (first_get[x][f] <= y) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "Shi" : "Fou") << '\n';
    }

    return 0;
}