#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int Solve(int c, int m, int x) {
    int ans = min(c, min(m, x));
    c -= ans; m -= ans; x -= ans;

    if (c == 0 || m == 0) 
        return ans;
    
    assert(x == 0);
    
    if (c < m) swap(c, m);
    int d = c - m;
    int now = min(m, min(2 * c, d));
    ans += now;
    c -= 2 * now;
    m -= now;
    if (c == 0 || m == 0) 
        return ans;
    assert(c == m);

    now = min(c / 3, m / 3);
    ans += 2 * now;
    
    c -= 3 * now;
    m -= 3 * now;
    
    assert(c == m);
    assert(c < 3 && m < 3);

    if (c == 2) 
        return ans + 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    /*    
    for (int c = 0; c <= 100; ++c) {
        for (int m = 0; m <= 100; ++m) {
            for (int x = 0; x <= 100; ++x) {
                Solve(c, m, x);
            }
        }
    }
    cerr << "OK" << endl;
    */
    int q; cin >> q;
    while (q--) {
        int c, m, x; cin >> c >> m >> x;
        cout << Solve(c, m, x) << '\n';
    }
    return 0;
}