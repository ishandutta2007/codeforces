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

long long l, r, i, j, k;

bool wa(long long a, long long b, long long c) {
    return __gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) != 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> l >> r;
    for (i = l; i <= r; ++i) {
        for (j = i + 1; j <= r; ++j) {
            for (k = j + 1; k <= r; ++k) {
                if (wa(i, j, k)) {
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}