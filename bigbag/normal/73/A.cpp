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

long long a, b, c, x, y, z, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> y >> z >> k;
    long long ans = 1;
    //cout << x * y * z << endl;
    for (int i = 1; i <= min(x, k + 1); ++i) {
        a = i - 1;
        long long o = k - a;
        b = o / 2;
        c = o - b;
        ++a;
        ++b;
        ++c;
        if (b > y) {
            c += b - y;
            b = y;
        }
        //cout << a << ' ' << b << ' ' << c << endl;
        c = min(z, c);
        ans = max(ans, a * b * c);
        c = o / 2;
        b = o - c;
        ++b;
        ++c;
        if (c > z) {
            b += c - z;
            c = z;
        }
        //cout << a << ' ' << b << ' ' << c << endl;
        b = min(b, y);
        ans = max(ans, a * b * c);
    }
    cout << ans << endl;
    return 0;
}