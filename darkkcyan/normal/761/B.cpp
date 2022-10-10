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

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, l; cin >> n >> l;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int t = 0; t < n; ++t) {
        b.push_back(b[0]);
        b.erase(b.begin());
        bool found = true;
        for (int i = 1; i < n; ++i) {
            if ((a[i] - b[i] + l * l) % l != (a[0] - b[0] + l * l) % l) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";

    return 0;
}