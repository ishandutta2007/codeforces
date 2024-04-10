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
#define rep(i,n) for (int i = - 1; ++i < (n);)
#define rep1(i,n) for (int i = 0; ++i <= (n); )

namespace sol {

#define maxn 1010
int n;
int a[maxn], b[maxn];

int main() {
    cin >> n;
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) {
        if (a[i] != b[i]) {
            cout << "rated";
            return 0;
        }
    }
    bool issorted = true;
    rep(i, n - 1) {
        if (a[i] < a[i + 1]) {
            issorted = false;
            break;
        }
    }
    if (!issorted) cout << "unrated";
    else cout << "maybe";
    return 0;
} }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t;
    //while (t--)
    sol::main();
    return 0;
}