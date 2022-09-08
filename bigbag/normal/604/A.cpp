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

int t[6], x[6], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 5; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i <= 5; ++i) {
        cin >> x[i];
        int c = i * 500;
        ans += max((c * 3) / 10, c - (c / 250) * t[i] - 50 * x[i]);
    }
    cin >> x[0] >> x[1];
    cout << ans + x[0] * 100 - x[1] * 50 << endl;
    return 0;
}