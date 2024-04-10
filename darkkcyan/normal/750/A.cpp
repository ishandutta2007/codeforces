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

    cin >> n >> k;
    long time = (24 - 20) * 60 - k;
    long ans = 0;
    for (long i = 5, cur = 0; cur + i <= time; cur += i, i += 5) {
        ++ans;
        if (ans == n) break;
    }
    cout << ans;
    return 0;
}