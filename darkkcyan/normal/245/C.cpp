#include <bits/stdc++.h>

using namespace std;

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
typedef ve<int> vi;
typedef pair<int, int> ii;

int n;
vi a;
void read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

long process() {
    if (n < 3 or n % 2 == 0) return -1;
    long ans = 0;
    for (int i = n; i > 1; i -= 2) {
        ans += max(a[i], a[i ^ 1]);
        a[i / 2] -= max(a[i], a[i ^ 1]);
        if (a[i / 2] < 0) a[i / 2] = 0;
    }
    ans += a[1];
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define fn "file"
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #undef fn
    #endif // ONLINE_JUDGE

    read();
    cout << process();

    return 0;
}