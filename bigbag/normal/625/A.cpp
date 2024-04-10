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

const int max_n = 1, inf = 1111111111;

long long n, a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b >> c;
    long long x = b - c;
    if (a <= x) {
        cout << n / a << endl;
        return 0;
    }
    long long l = 0, r = n / x + 2;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        long long q = n - mid * x;
        if (q >= b) {
            l = mid;
        } else {
            r = mid;
        }
    }
    long long q = n - l * x;
    if (q >= b) {
        ++l;
        q -= x;
    }
    l += q / a;
    cout << l << endl;
    return 0;
}