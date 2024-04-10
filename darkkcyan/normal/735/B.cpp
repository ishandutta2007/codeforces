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
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, n1, n2;
vi a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &n1, &n2);
    a.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    long s1 = 0, s2 = 0;
    double ans;
    int i;
    if (n1 > n2) swap(n1, n2);
    for (int i = 0; i < n1 and a.size(); ++i, a.pop_back()) s1 += a.back();
    for (int i = 0; i < n2 and a.size(); ++i, a.pop_back()) s2 += a.back();
    ans = (double)s1 / n1 + (double)s2 / n2;
    cout << fixed << setprecision(10) << ans;

    return 0;
}