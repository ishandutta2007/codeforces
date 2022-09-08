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

const int max_n = 1111, inf = 111111111;

int n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == 0) {
        cout << 0 << endl;
        return 0;
    }
    sum = abs(sum);
    int ans = 0;
    while (sum >= x) {
        sum -= x;
        ++ans;
    }
    if (sum == 0) {
        cout << ans << endl;
    } else {
        cout << ans + 1 << endl;
    }
    return 0;
}