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

#define NN 101010
int cnt[NN] = {0};
int n;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        cnt[t]++;
    }

    int ans = 1;
    for (int i = 2; i < NN; ++i) {
        int c = 0;
        for (int f = i; f < NN; f += i) c += cnt[f];
        ans = max(ans, c);
    }

    cout << ans;

    return 0;
}