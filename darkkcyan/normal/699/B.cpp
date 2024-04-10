#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, m;
ve<string> a;
vi b, c;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    b.resize(n); c.resize(m);
    for (int i = 0; i < n; ++i)
    for (int f = 0; f < m; ++f)
        b[i] += a[i][f] == '*',
        c[f] += a[i][f] == '*';

    long sum = accumulate(b.begin(), b.end(), (long)0);

    ii ans(-1, -1);
    for (int i = 0; i < n and ans.xx == -1; ++i)
    for (int f = 0; f < m; ++f) {
        long t = b[i] + c[f] - (a[i][f] == '*');
        if (t == sum) {
            ans = ii(i, f);
            break;
        }
    }

    if (ans.xx == -1) cout << "NO";
    else {
        cout << "YES" << endl << ans.xx + 1 << ' ' << ans.yy + 1 << endl;
    }

    return 0;
}