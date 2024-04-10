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

const int max_n = 111111, inf = 1111111111;

long long n, k, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    ans = n;
    ans *= n - 1;
    ans /= 2;
    if (k * 2 + 1 >= n) {
    } else {
        n -= 2 * k;
        long long x;
        x = n;
        x *= n - 1;
        x /= 2;
        ans -= x;
    }
    cout << ans << endl;
    return 0;
}