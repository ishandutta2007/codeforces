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

long long ans, n, mx, cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    mx = 9;
    cnt = 9;
    for (int i = 1; i < 12; ++i) {
        if (mx <= n) {
            ans += i * cnt;
        } else {
            ans += i * (n - (mx + 1) / 10 + 1);
            break;
        }
        mx = mx * 10 + 9;
        cnt *= 10;
    }
    cout << ans << endl;
    return 0;
}