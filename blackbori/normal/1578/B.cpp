#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t, x1, p1, x2, p2, v;
    
    for (cin >> t; t--; ) {
        cin >> x1 >> p1 >> x2 >> p2;
        v = min(p1, p2); p1 -= v; p2 -= v;
        for (; p1 && x1 <= x2; x1 *= 10, p1--);
        for (; p2 && x2 <= x1; x2 *= 10, p2--);
        if (x1 == x2) cout << "=\n";
        else if (x1 < x2) cout << "<\n";
        else cout << ">\n";
    }
    
    return 0;
}