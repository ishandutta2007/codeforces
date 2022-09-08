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

const int max_n = 1111111, inf = 1111111111;

int ans, a[6], b[6];

int get(int x) {
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }
    int cnt = 2 * a[0] + 1;
    int ans = 0;
    b[1] = get(a[5]);
    b[2] = get(a[1]);
    b[3] = get(a[4]);
    b[4] = get(a[2]);
    for (int i = 0; i < b[3] + b[1]; ++i) {
        ans += cnt;
        if (i + 1 < b[1]) {
            ++cnt;
        }
        if (i + 1 < b[2]) {
            ++cnt;
        }
        if (i + 1 > b[1]) {
            --cnt;
        }
        if (i + 1 > b[2]) {
            --cnt;
        }
    }
    cout << ans << endl;
    return 0;
}