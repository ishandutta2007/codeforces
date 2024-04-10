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

long long r, a, b, c, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> r >> a >> b >> c >> d;
    r *= 2;
    long long q = (a - c) * (a - c) + (b - d) * (b - d);
    double dist = sqrt(q);
    for (int k = -100; k <= 100; ++k) {
        long long f = dist + k;
        if (f >= 0 && f * f == q) {
            if (f % r == 0) {
                cout << f / r << endl;
            } else {
                cout << f / r + 1 << endl;
            }
            return 0;
        }
    }
    q = dist / r + 1;
    cout << q << endl;
    return 0;
}