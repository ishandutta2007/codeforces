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

long long l, r, k, x, num[5], ans[5];

void rec(int poz, long long nx) {
    if (poz == num[0] + 1) {
        if (nx < x) {
            x = nx;
            for (int i = 0; i < poz; ++i) {
                ans[i] = num[i];
            }
        }
        return;
    }
    long long st = l;
    if (poz > 1) {
        st = num[poz - 1] + 1;
    }
    for (long long i = st; i <= r; ++i) {
        num[poz] = i;
        rec(poz + 1, nx ^ i);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> l >> r >> k;
    if (r - l + 1 <= 4) {
        x = 1e15;
        for (int i = 1; i <= k; ++i) {
            num[0] = i;
            rec(1, 0);
        }
        cout << x << endl << ans[0] << endl;
        for (int i = 1; i <= ans[0]; ++i) {
            cout << ans[i] << " ";
        }
        return 0;
    }
    if (k == 1) {
        cout << l << endl << 1 << endl << l << endl;
        return 0;
    }
    if (k == 2) {
        if (l % 2 == 1) {
            ++l;
        }
        cout << 1 << endl << 2 << endl << l << " " << l + 1 << endl;
        return 0;
    }
    if (k >= 4) {
        if (l % 2 == 1) {
            ++l;
        }
        cout << 0 << endl << 4 << endl << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
        return 0;
    }
    for (int len = 0; len < 60; ++len) {
        long long x, y, z;
        x = (3LL << len);
        z = (1LL << (len + 1)) - 1;
        y = x ^ z;
        if (z >= l && x <= r) {
            cout << 0 << endl << 3 << endl << z << " " << y << " " << x << endl;
            return 0;
        }
    }
    if (l % 2 == 1) {
        ++l;
    }
    cout << 1 << endl << 2 << endl << l << " " << l + 1 << endl;
    return 0;
}