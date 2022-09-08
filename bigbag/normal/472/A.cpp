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

const int max_n = 1111111, inf = 1111111111;

int n, f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            f[j] = 1;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (f[i] && f[n - i]) {
            cout << i << " " << n - i << endl;
            return 0;
        }
    }
    return 0;
}