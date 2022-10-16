#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    
    for (int x1 = 1; x1 * x1 < a * a; ++ x1) for (int y1 = 1; y1 * y1 + x1 * x1 <= a * a; ++y1) {
        if (x1 * x1 + y1 * y1 == a * a) { 
            for (int x2 = 1; x2 * x2 < b * b; ++ x2) for (int y2 = 1; y2 * y2 + x2 * x2 <= b * b; ++y2) {
                if (x2 * x2 + y2 * y2 == b * b) {
//                    cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
                    if (-x1 * x2 + y1 * y2 == 0 && y1 != y2) {
                        cout << "YES" << endl;
                        cout << 0 << ' ' << 0 << endl;
                        cout << x1 << ' ' << y1 << endl;
                        cout << -x2 << ' ' << y2 << endl;
                        return;
                    }
                }
            }
        }
    }
    
    cout << "NO" << endl;
}

int main() {
    int tests = 1;
    while (tests --> 0)
        solve();
    return 0;
}