#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        long x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        if (a > b) swap(a, b);
        if (x < a) {
            cout << 0 << endl;
            continue;
        }
        if (a == b) {
            cout << (x / a) << endl;
            continue;
        }
        if (x == y) {
            long both = x / (a + b);
            x -= both * (a + b);
            y -= both * (a + b);
            long one = a <= x && b <= y;
            cout << (2 * both + one) << endl;
            continue;
        }
        // take many to balance
        long fit_x = x / a;
        long fit_y = y / b;
        long fit_d = (y - x) / (b - a);
        long fit = min(min(fit_x, fit_y), fit_d);
        x -= fit * a;
        y -= fit * b;
        assert(x <= y);
        long both = x / (a + b);
        x -= both * (a + b);
        y -= both * (a + b);
        long one = a <= x && b <= y;
        cout << (fit + 2 * both + one) << endl;
    }
    return 0;
}