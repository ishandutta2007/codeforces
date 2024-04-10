#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, d;
        cin >> a >> b >> d;
        int c = a | b;
        int k = (d - c % d) % d;
        int p = (1 << 30) % d;
        // Now solve the equation p*x = k (mod d).
        // i.e. solve p*x - d*y = k.
        int x, y, g;
        bool exists = find_any_solution(p, -d, k, x, y, g);
        if(!exists) {
            cout << -1 << '\n';
        } else {
            x = (x % d + d) % d;
            cout << c + (1<<30)*x << '\n';
        }
    }
    
    return 0;
}