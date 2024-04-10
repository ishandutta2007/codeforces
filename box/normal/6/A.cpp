#include <iostream>
#include <algorithm>
using namespace std;

int TriangleType(int a, int b, int c) {
    int mx = max(a, max(b, c));
    if(a == mx) {
        a = b; b = c; c = mx;
    } else if(b == mx) {
        b = c; c = mx;
    }
    if(a+b > c) return 2;
    if(a+b == c) return 1;
    return 0;
}

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int tot = 0;
    tot = max(tot, TriangleType(a, b, c));
    tot = max(tot, TriangleType(a, b, d));
    tot = max(tot, TriangleType(a, c, d));
    tot = max(tot, TriangleType(b, c, d));
    if(tot == 2) cout << "TRIANGLE" << endl;
    else if(tot == 1) cout << "SEGMENT" << endl;
    else cout << "IMPOSSIBLE" << endl;
}