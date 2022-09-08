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

const int max_n = 111111, inf = 1111111111;

int l, r, k;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int fun(int r, int k) {
    if (r < k || !is_prime(k)) {
        return 0;
    }
    int res = r / k;
    for (int i = 2; i < k && i <= r / k; ++i) {
        res -= fun(r / k, i);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> l >> r >> k;
    cout << fun(r, k) - fun(l - 1, k) << endl;
    return 0;
}