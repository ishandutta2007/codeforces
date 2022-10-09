#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace sol {
// actual solution start here

#define maxn 1010101
int k;
vi a;
string s;

int qmem[2 * maxn], *h, *t;
int dp[maxn];
int findmin(const vi& a, int ml) {
    h = t = qmem; --t;
    int sum = 0;
    int l = 0;
    rep(r, sz(a)) {
        if (a[r] > ml) return inf(int);
        sum += a[r];
        while (sum > ml) sum -= a[l++];
        while (h > t or *t < r - 1) {
            if (h <= t) {
                int nx = *t + 1;
                while (h <= t and dp[*t] >= dp[nx]) --t;
                *(++t) = nx;
            }
            else *(++t) = r - 1;
        }
        while (h <= t and *h < l - 1) ++h;
        if (h > t) dp[r] = 1;
        else dp[r] = dp[*h] + 1;
    }
    return dp[sz(a) - 1];
}

bool ok(int len) {
    int x = findmin(a, len);
    if (x == inf(int)) return false;
    return x <= k;
}

int main() {
    cin >> k >> ws;
    a.push_back(0);
    getline(cin, s);
    for (auto c: s) {
        a.back()++;
        if (c == ' ' or c == '-') a.push_back(0);
    }
    while (a.size() and a.back() == 0) a.pop_back();
    int l = 0, r = maxn;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return sol::main();
}