#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

long long r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> r;
    --r;
    if (r == 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (long long x = 1; x * x <= r; ++x) {
        if (r % x == 0) {
            long long y = r / x;
            y -= x + 1;
            if (y > 0 && y % 2 == 0) {
                cout << x << " " << y / 2 << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}