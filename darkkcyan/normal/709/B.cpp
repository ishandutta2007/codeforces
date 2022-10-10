#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log clog << __LINE__ << ": "
#define _ << ' ' <<
#endif

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back

int n, s;
ve<int> a;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n >> s;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n == 1) return cout << 0, 0;

    sort(all(a));
    long ans = min(
        min(abs(a.back() - s), abs(s - a[1])) + abs(a.back() - a[1]),
        min(abs(s - a[0]), abs(s - a[n - 2])) + abs(a[n - 2] - a[0])
    );

    cout << ans;

    return 0;
}