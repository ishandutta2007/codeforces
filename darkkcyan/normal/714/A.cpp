#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()


int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    long l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;

    if (l1 > r2 or l2 > r1) return cout << 0, 0;
    l1 = max(l1, l2);
    r1 = min(r1, r2);
    long ans = r1 - l1 + 1;
    if (l1 <= k and k <= r1) --ans;
    cout << max(ans, (long) 0);

    return 0;
}