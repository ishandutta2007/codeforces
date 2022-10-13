#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; long long k; cin >> n >> k;
    string a, b; cin >> a >> b;

    long long ans = 0;
    int at = 0;
    while (at < n && a[at] == b[at]) {
        ++at;
        ans += 1;
    }

    a = a.substr(at);
    b = b.substr(at);
    n = a.size();
    
    //cerr << a << endl << b << endl;

    if (n == 0) {
        cout << ans << endl;
        return 0;
    }

    if (k <= b[0] - a[0] + 1) {
        ans += k * n;
        cout << ans << endl;
        return 0;
    }

    long long have = b[0] - a[0] + 1;
    ans += have;

    assert(have >= 2);
    int dep = 0;

    for (int dep = 1; dep < n; ++dep) {
        long long new_have = 0;
        new_have += ('b' - a[dep] + 1);
        new_have += (b[dep] - 'a' + 1);
        new_have += (have - 2) * ('b' - 'a' + 1);
        if (new_have >= k) {
//            cerr << dep << " " << new_have << endl;
            ans += k * (n - dep);
            cout << ans << endl;
            return 0;
        }
        ans += new_have;
        have = new_have;
    }

    cout << ans << endl;
    return 0;
}