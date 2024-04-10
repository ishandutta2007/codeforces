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

const int max_n = 555;

long long n, ans, f[6];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    ans = 1;
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    f[4] = 4;
    f[5] = 5;
    for (int i = n - 4; i <= n; ++i) {
        ans *= i * i;
        for (int j = 1; j < 6; ++j) {
            if (ans % f[j] == 0) {
                ans /= f[j];
                f[j] = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}