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

const int max_n = 111, inf = 1111111111;

struct matrix {
    int n, m, a[max_n][max_n];
    void fun() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[n + i][j] = a[n - i - 1][j];
            }
        }
        n *= 2;
    }
};

int n, m, a[max_n][max_n];

bool good(matrix q) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (q.a[i][j] != a[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 64; i >= 1; i /= 2) {
        if (n % i == 0) {
            int cnt = n / i;
            matrix q;
            q.n = cnt;
            q.m = m;
            for (int i = 0; i < cnt; ++i) {
                for (int j = 0; j < m; ++j) {
                    q.a[i][j] = a[i][j];
                }
            }
            while (q.n != n) {
                q.fun();
            }
            if (good(q)) {
                cout << cnt << endl;
                return 0;
            }
        }
    }
    return 0;
}