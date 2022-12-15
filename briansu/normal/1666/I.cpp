#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int f(int x, int y) {
    cout << "SCAN " << x << " " << y << endl;
    int val;
    cin >> val;
    return val;
}

int q(int x, int y) {
    cout << "DIG " << x << " " << y << endl;
    int val;
    cin >> val;
    return val;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int x = f(1, 1);
        int y = f(n, 1);
        int z = 2 * (n + m - 2) - y;
        int ysum = (x + y) / 2 - n + 1 + 2;
        int xsum = (x + z) / 2 - m + 1 + 2;
        int xdiff = f(xsum / 2, 1) - ysum + 2;
        int ydiff = f(1, ysum / 2) - xsum + 2;
        int x1 = (xsum + xdiff) / 2;
        int x2 = xsum - x1;
        int y1 = (ysum + ydiff) / 2;
        int y2 = ysum - y1;
        if (q(x1, y1))
            q(x2, y2);
        else
            q(x1, y2), q(x2, y1);
    }
}