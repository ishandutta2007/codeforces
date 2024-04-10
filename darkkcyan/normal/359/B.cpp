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

long n, k;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long t = (n - k);
    int i;
    for (i = 1; i <= t; ++i) {
        cout << (i * 2 - 1) << ' ' << (i * 2) << ' ';
    }

    for (; i <= n; ++i) {
        cout << (i * 2) << ' ' << (i * 2 - 1) << ' ';
    }

    return 0;
}