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

long long c, h1, h2, w1, w2, ans, st = 1, f = 0;

long long fun(long long x) {
    long long y = (c - x * w1) / w2;
    return x * h1 + y * h2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> c >> h1 >> h2 >> w1 >> w2;
    if (c / w1 > 10000000) {
        st = 100;
    }
    ans = 0;
    for (int t = 0; t < 2; ++t) {
        for (long long x = 0; x * w1 <= c && x <= 50000; ++x) {
            ans = max(ans, fun(x));
        }
        swap(h1, h2);
        swap(w1, w2);
    }
    cout << ans << endl;
    return 0;
}