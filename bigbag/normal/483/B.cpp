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

const long long inf = 11111111111111111LL;

long long cnt1, cnt2, x, y;

bool check(long long a) {
    return a - a / x >= cnt1 && a - a / y >= cnt2 && a - a / (x * y) >= cnt1 + cnt2;;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> cnt1 >> cnt2 >> x >> y;
    long long l = 1, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}