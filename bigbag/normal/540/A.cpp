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

int n, ans;
string a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int res = 1111;
        if (x < y) {
            res = min(res, y - x);
            res = min(res, x + 10 - y);
        } else {
            res = min(res, x - y);
            res = min(res, 10 - x + y);
        }
        ans += res;
    }
    cout << ans << endl;
    return 0;
}