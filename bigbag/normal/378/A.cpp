#include <set>
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

int a, b, ans[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int i = 1; i < 7; ++i) {
        int d1 = abs(i - a), d2 = abs(i - b);
        if (d1 < d2) {
            ans[0]++;
        }
        if (d1 == d2) {
            ans[1]++;
        }
        if (d1 > d2) {
            ans[2]++;
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
    return 0;
}