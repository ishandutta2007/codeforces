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

int a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    int ans = 0, p = 0;
    while (a != 0) {
        ans += a;
        p += a % b;
        a = a / b;
        if (p >= b) {
            a += p / b;
            p = p % b;
        }
    }
    cout << ans << endl;
    return 0;
}