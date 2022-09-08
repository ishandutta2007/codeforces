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

const int inf = 111111111;

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n > m) {
        if (n == m + 1) {
            for (int i = 0; i < n + m; ++i) {
                if (i % 2 == 0) {
                    cout << 0;
                } else {
                    cout << 1;
                }
            }
            return 0;
        }
        cout <<-1 << endl;
        return 0;
    }
    int cnt = 0;
    while (m > 1 && n > 0 && n != m) {
        m -= 2;
        --n;
        ++cnt;
    }
    if (n == m) {
        for (int i = 0; i < cnt; ++i) {
            cout << "110";
        }
        for (int i = 0; i < n; ++i) {
            cout << "10";
        }
        return 0;
    }
    if (n == 0) {
        if (m <= 2) {
            for (int i = 0; i < cnt; ++i) {
                cout << "110";
            }
            for (int i = 0; i < m; ++i) {
                cout << "1";
            }
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    return 0;
}