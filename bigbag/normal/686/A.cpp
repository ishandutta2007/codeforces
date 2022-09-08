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

const int max_n = 1, inf = 1111111111;

int n, ans, all;
long long x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x;
    while (n--) {
        char c;
        int cnt;
        cin >> c >> cnt;
        if (c == '+') {
            x += cnt;
        } else {
            if (x >= cnt) {
                x -= cnt;
                ++ans;
            }
            ++all;
        }
    }
    cout << x << " " << all - ans << endl;
    return 0;
}