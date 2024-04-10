#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

int n, k;
ve<bool> a;

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k; a.resize(n);
    bool k0 = k == 0;
    for (int i = 0, t; i < n; ++i) cin >> t, a[i] = t;

    int l = 0, r = 0;
    int tl = 0, tr = 0;
    bool has1 = false;
    for (; r < n; ++r) {
        k -= a[r] == 0;
        has1 |= a[r] == 1;
        for (; l < r and k < 0; ++l) k += a[l] == 0;
        if (r - l > tr - tl) tr = r, tl = l;
    }

    if (k0 and !has1) cout << 0 << endl;
    else cout << tr - tl + 1 << endl;
    for (int i = 0; i < n; ++i) {
        if (!k0 and i <= tr and i >= tl) cout << 1;
        else cout << a[i];
        cout << ' ';
    }

    return 0;
}