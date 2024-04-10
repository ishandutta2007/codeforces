#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    long n, m, a; cin >> n >> m >> a;
    --a;
    bool s = a & 1; a >>= 1;
    cout << a / m + 1 << ' ' << a - m * (a / m) + 1 << ' ' << ("LR")[s];

    return 0;
}