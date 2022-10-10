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

int n, b, d, t;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    cin >> n >> b >> d;
    int ans = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t > b) continue;
        s += t;
        if (s > d) ++ans, s = 0;
    }
    cout << ans;
    return 0;
}