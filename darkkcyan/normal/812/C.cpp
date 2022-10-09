#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n;)
#define rep1(i,n) for (int i = 0; ++i <= n;) 

#define maxn 101010
int n;
llong s;
llong a[maxn], b[maxn];

llong cal(int k) {
    rep1(i, n) b[i] = a[i] + (llong)i * k;
    sort(b + 1, b + n + 1);
    llong ans = 0;
    rep1(i, k) ans += b[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    rep1(i, n) cin >> a[i];
    llong l = 0, r = n;
    while (l < r) {
        llong mid = l + (r - l + 1) / 2;
        llong cost = cal(mid);
        if (cost <= s) l = mid;
        else r = mid - 1;
    }
    cout << l << ' ' << cal(l);
    return 0;
}