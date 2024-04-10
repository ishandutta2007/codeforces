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

long long a, b, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int len = 1; len <= 62; ++len) {
        long long x = (1LL << len) - 1;
        for (int poz = 0; poz + 1 < len; ++poz) {
            long long y = x;
            y -= (1LL << poz);
            if (a <= y && y <= b) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}