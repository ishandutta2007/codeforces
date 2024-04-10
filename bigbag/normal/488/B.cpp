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

const int inf = 1111111111;

int n, a[9], k[9], x[9];

int get_last1() {
    x[2] = a[1];
    x[3] = a[2];
    x[4] = a[3];
    x[1] = x[2] + x[3] - x[4];
    int y = inf, z = inf;
    if ((3 * x[4] - x[2] - x[3]) % 5 == 0) y = (3 * x[4] - x[2] - x[3]) / 5;
    if ((4 * x[4] - 2 * x[2] - 2 * x[3]) % 4 == 0) z = (4 * x[4] - 2 * x[2] - 2 * x[3]) / 4;
    if (1 <= x[1] && x[1] <= x[2] && x[1] == y && y == z) return x[1];
    return 0;
}

int get_last2() {
    x[1] = a[1];
    x[3] = a[2];
    x[4] = a[3];
    x[2] = x[1] + x[4] - x[3];
    int y = inf, z = inf;
    if ((3 * x[4] - 5 * x[1] - x[3]) % 1 == 0) y = (3 * x[4] - 5 * x[1] - x[3]) / 1;
    if ((4 * x[4] - 4 * x[1] - 2 * x[3]) % 2 == 0) z = (4 * x[4] - 4 * x[1] - 2 * x[3]) / 2;
    if (x[1] <= x[2] && x[2] <= x[3] && x[2] == y && y == z) return x[2];
    return 0;
}

int get_last3() {
    x[1] = a[1];
    x[2] = a[2];
    x[4] = a[3];
    x[3] = x[1] + x[4] - x[2];
    int y = inf, z = inf;
    if ((3 * x[4] - 5 * x[1] - x[2]) % 1 == 0) y = (3 * x[4] - 5 * x[1] - x[2]) / 1;
    if ((4 * x[4] - 4 * x[1] - 2 * x[2]) % 2 == 0) z = (4 * x[4] - 4 * x[1] - 2 * x[2]) / 2;
    if (x[2] <= x[3] && x[3] <= x[4] && x[3] == y && y == z) return x[3];
    return 0;
}

int get_last4() {
    x[1] = a[1];
    x[2] = a[2];
    x[3] = a[3];
    x[4] = x[2] + x[3] - x[1];
    int y = inf, z = inf;
    if ((5 * x[1] + x[2] + x[3]) % 3 == 0) y = (5 * x[1] + x[2] + x[3]) / 3;
    if ((2 * x[2] + 2 * x[3] + 4 * x[1]) % 4 == 0) z = (2 * x[2] + 2 * x[3] + 4 * x[1]) / 4;
    if (x[3] <= x[4] && x[4] <= 1000000 && x[4] == y && y == z) return x[4];
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if (n == 0) {
        cout << "YES\n1\n1\n3\n3\n";
        return 0;
    }
    if (n == 1) {
        cout << "YES\n" << a[1] << "\n" << 3 * a[1] << "\n" << 3 * a[1] << endl;
        return 0;
    }
    if (n == 2) {
        k[1] = a[1];
        k[2] = a[2];
        for (int i = 1; i <= 1000000; ++i) {
            a[1] = k[1];
            a[2] = k[2];
            a[3] = i;
            sort(a + 1, a + 4);
            //cout << a[1] << " "<< a[2] << " " << a[3] << "##\n";
            int x;
            x = get_last1();
            if (x) {
                cout << "YES\n" << x << "\n" << i << endl;
                return 0;
            }
            x = get_last2();
            if (x) {
                cout << "YES\n" << x << "\n" << i << endl;
                return 0;
            }
            x = get_last3();
            if (x) {
                cout << "YES\n" << x << "\n" << i << endl;
                return 0;
            }
            x = get_last4();
            if (x) {
                cout << "YES\n" << x << "\n" << i << endl;
                return 0;
            }
        }
        cout << "NO\n";
        return 0;
    }
    if (n == 3) {
        int x;
        x = get_last1();
        if (x) {
            cout << "YES\n" << x << endl;
            return 0;
        }
        x = get_last2();
        if (x) {
            cout << "YES\n" << x << endl;
            return 0;
        }
        x = get_last3();
        if (x) {
            cout << "YES\n" << x << endl;
            return 0;
        }
        x = get_last4();
        if (x) {
            cout << "YES\n" << x << endl;
            return 0;
        }
        cout << "NO\n";
        return 0;
    }
    if (n == 4) {
        if (a[1] + a[2] + a[3] + a[4] == 2 * a[2] + 2 * a[3] && a[1] + a[2] + a[3] + a[4] == 4 * a[4] - 4 * a[1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}