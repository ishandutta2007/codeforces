#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);
    if ((c - a) % x != 0 || (d - b) % y != 0) {
        cout << "NO" << endl;
        return 0;
    }
    a = (c - a) / x;
    b = (d - b) / y;
    if (abs(a - b) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}