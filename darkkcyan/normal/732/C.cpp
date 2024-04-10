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

ve<long> a(3);

long subpro(ve<long> a) {
    long m = *max_element(a.bb, a.ee);
    long ans = 0;
    for (int i = 0; i < sz(a); ++i) ans += m - a[i];
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> a[0] >> a[1] >> a[2];
    long ans = numeric_limits<long>::max();

    for (int f = 0; f <= 3; ++f) {
        for (int l = 0; l <= 3; ++l) {
            ve<long> b = a;
            for (int i = 2; i >= f; --i) b[i] --;
            for (int i = 0; i < l; ++i) b[i] --;
            ans = min(ans, subpro(b));
        }
    }

    cout << ans;


    return 0;
}