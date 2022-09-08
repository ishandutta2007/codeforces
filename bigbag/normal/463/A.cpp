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

int n, s, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ans = -1;
    cin >> n >> s;
    s *= 100;
    while (n--) {
        cin >> x >> y;
        if (s >= x * 100 + y) {
            ans = max(ans, 0);
            if (y) ans = max(ans, 100 - y);
        }
    }
    cout << ans << endl;
    return 0;
}