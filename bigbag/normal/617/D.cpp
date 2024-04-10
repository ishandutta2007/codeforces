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

const int max_n = 3, inf = 1111111111;

int x[3], y[3], a[3], b[3], p[3], ans = inf;

void rec(int poz, int cnt, int last) {
    if (poz == 2) {
        ans = min(ans, cnt);
        return;
    }
    if (x[poz] == x[poz + 1]) {
        int f;
        if (y[poz + 1] > y[poz]) {
            f = 1;
        } else {
            f = 3;
        }
        rec(poz + 1, cnt + 1 - (f == last), f);
        return;
    }
    if (y[poz] == y[poz + 1]) {
        int f;
        if (x[poz + 1] > x[poz]) {
            f = 2;
        } else {
            f = 0;
        }
        rec(poz + 1, cnt + 1 - (f == last), f);
        return;
    }
    int f, f2;
    if (y[poz + 1] > y[poz]) {
        f = 1;
    } else {
        f = 3;
    }
    if (x[poz + 1] > x[poz]) {
        f2 = 2;
    } else {
        f2 = 0;
    }
    rec(poz + 1, cnt + 2 - (f == last), f2);

    if (x[poz + 1] > x[poz]) {
        f = 2;
    } else {
        f = 0;
    }
    if (y[poz + 1] > y[poz]) {
        f2 = 1;
    } else {
        f2 = 3;
    }
    rec(poz + 1, cnt + 2 - (f == last), f2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i] >> b[i];
        p[i] = i;
    }
    do {
        for (int i = 0; i < 3; ++i) {
            x[i] = a[p[i]];
            y[i] = b[p[i]];
        }
        rec(0, 0, -1);
    } while (next_permutation(p, p + 3));
    cout << ans << endl;
    return 0;
}