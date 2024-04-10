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

int n, m, k;

bool game(int n, int m) {
    if (n % 2 == 0) {
        return true;
    }
    for (int i = 1; i * i <= m; ++i) {
        int x = i;
        if (m / x != 1 && m % x == 0 && x >= k) {
            if (game(m / x, x)) {
                return false;
            }
        }
        x = m / i;
        if (m / x != 1 && m % x == 0 && x >= k) {
            if (game(m / x, x)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    if (!game(n, m)) {
        cout << "Timur" << endl;
    } else {
        cout << "Marsel" << endl;
    }
    return 0;
}