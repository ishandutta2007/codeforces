#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 2222;
const long long inf = 1011011011022022022LL;

int n, a, b, x, y, z, ans;

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            if (x < a) {
                ++x;
            } else if (y + z < b) {
                ++y;
            } else if (y) {
                --y;
                ++z;
            } else {
                ++ans;
            }
        } else {
            if (y + z < b) {
                ++z;
            } else {
                ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}