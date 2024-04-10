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

const int max_n = 11, inf = 1111111111;

int m, n, ans, poz;

void update(int x) {
    if (x == m) {
        return;
    }
    if (1 <= x && x <= n) {
        if (m < x) {
            int f = n - (m + x) / 2;
            //cout << x << " " << f << endl;
            if (ans < f || (ans == f && x < poz)) {
                ans = f;
                poz = x;
            }
        } else {
            int f = (m + x + 1) / 2 - 1;
            //cout << x << " " << f << endl;
            if (ans < f || (ans == f && x < poz)) {
                ans = f;
                poz = x;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    ans = 0;
    poz = m;
    update(m + 1);
    update(m + 2);
    update(m + 3);
    update(m + 4);
    update(m + 5);
    update(m - 1);
    update(m - 2);
    update(m - 3);
    update(m - 4);
    update(m - 5);
    cout << poz << endl;
    return 0;
}