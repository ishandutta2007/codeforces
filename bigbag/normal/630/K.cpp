#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, ans, a[111];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a[3] = 7;
    for (int mask = 0; mask < (1 << 4); ++mask) {
        long long x = 1, cnt = 0, res = 0;
        for (int j = 0; j < 4; ++j) {
            if (get_bit(mask, j)) {
                x *= a[j];
                ++cnt;
            }
        }
        res = n / x;
        if (cnt % 2 == 0) {
            ans += res;
        } else {
            ans -= res;
        }
    }
    cout << ans << endl;
    return 0;
}