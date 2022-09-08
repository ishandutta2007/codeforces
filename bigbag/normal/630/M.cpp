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

long long n, ans = 1111, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    n %= 360;
    if (n < 0) {
        n += 360;
    }
    int q = 0;
    for (int i = 0; i < 4; ++i) {
        long long res = q - n;
        if (res < 0) {
            res *= -1;
        }
        res = min(res, 360 - res);
        if (res < ans) {
            ans = res;
            x = i;
        }
        q += 90;
    }
    cout << x << endl;
    return 0;
}