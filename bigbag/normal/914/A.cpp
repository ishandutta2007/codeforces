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

const int max_n = 1, inf = 1011111111;

int n, x;

int f(int x) {
    int l = 0, r = 1111;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (mid * mid <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = -inf;
    while (n--) {
        cin >> x;
        int sq = f(x);
        if (sq * sq != x) {
            ans = max(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}