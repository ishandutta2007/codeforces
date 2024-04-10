#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int a, b;

int main() {
    cin >> a >> b;
    if (a == b) {
        cout << "infinity" << endl;
        return 0;
    }
    if (a < b) {
        cout << 0 << endl;
        return 0;
    }
    int x = a - b, ans = 0;
    for (int k = 1; k * k <= x; ++k) {
        if (x % k == 0) {
            int y = x / k;
            if (a % y == b) {
                //cout << "!" << y << endl;
                ++ans;
            }
            if (k < y) {
                y = k;
                if (a % y == b) {
                    //cout << y << endl;
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}