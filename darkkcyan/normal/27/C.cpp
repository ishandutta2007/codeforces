#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

int n;
ve<long> a, b;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    a.resize(n); for (int i = 0; i < n; ++i) cin >> a[i];
    b = a;
    b.resize(unique(b.bb, b.ee) - b.bb);
    if (sz(b) <= 2) return cout << 0, 0;
    for (int i = 1; i < sz(b) - 1; ++i) {
        if ((b[i - 1] - b[i]) * (b[i + 1] - b[i]) > 0) {
            cout << 3 << endl;
            int t = -1;
            for (int f = -1; f <= 1; ++f)
                t = find(a.bb + t + 1, a.ee, b[i + f]) - a.bb,
                cout << t + 1 << ' ';
            exit(0);
        }
    }

    cout << 0;


    return 0;
}