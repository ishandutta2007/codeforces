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

int n, poz1 = -1, poz2 = -1;
long long l, x, y, a[max_n];
map<long long, int> f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        f[a[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (f.count(a[i] + x)) {
            poz1 = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f.count(a[i] + y)) {
            poz2 = i;
            break;
        }
    }
    if (poz1 != -1 && poz2 != -1) {
        cout << 0 << endl;
        return 0;
    }
    if (poz1 != -1 && poz2 == -1) {
        cout << "1\n" << y << endl;
        return 0;
    }
    if (poz1 == -1 && poz2 != -1) {
        cout << "1\n" << x << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        long long q = a[i] + x + y;
        if (f.count(q)) {
            cout << "1\n" << a[i] + x << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        long long q = a[i] + y - x;
        if (f.count(q)) {
            if (a[i] + y <= l) {
                cout << "1\n" << a[i] + y << endl;
                return 0;
            }
            if (a[i] - x > 0) {
                cout << "1\n" << a[i] - x << endl;
                return 0;
            }
        }
    }
    cout << "2\n" << x << " " << y << endl;
    return 0;
}