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

int n, d;
vi a;

long c2(long n) {
    if (n <= 1) return 0;
    return n * (n - 1) / 2;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long l = 0, r = 0;
    long ans = 0;
    for (; r < n; ++r) {
        for (; l < r and a[r] - a[l] > d; ++l);
        ans += c2(r - l);
    }

    cout << ans;

    return 0;
}