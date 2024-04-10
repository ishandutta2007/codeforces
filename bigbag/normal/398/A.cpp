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

const long long inf = 1000000000;

long long a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    if (a == 0) {
        cout << -b * b << endl;
        for (int i = 0; i < b; ++i) {
            cout << 'x';
        }
        return 0;
    }
    if (b == 0) {
        cout << a * a << endl;
        for (int i = 0; i < a; ++i) {
            cout << 'o';
        }
        return 0;
    }
    if (b == 1) {
        cout << a * a - 1 << endl;
        cout << 'x';
        for (int i = 0; i < a; ++i) {
            cout << 'o';
        }
        return 0;
    }
    long long max_ans = -inf * inf, ans_cnt;
    for (int cnt = 2; cnt <= b; ++cnt) {
        long long x = b / cnt, x1 = b % cnt, y1 = cnt - 2, y2 = a - y1;
        if (y2 > 0) {
            long long ans = y1 + y2 * y2 - x1 * (x + 1) * (x + 1) - (cnt - x1) * x * x;
            if (ans > max_ans) {
                max_ans = ans;
                ans_cnt = cnt;
            }
        }
    }
    cout << max_ans << endl;// << ans_cnt << endl;
    long long x = b / ans_cnt, x1 = b % ans_cnt, y1 = ans_cnt - 2, y2 = a - y1;
    for (int i = 0; i < ans_cnt; ++i) {
        if (i >= x1) {
            for (int j = 0; j < x; ++j) {
                cout << 'x';
            }
        } else {
            for (int j = 0; j < x + 1; ++j) {
                cout << 'x';
            }
        }
        if (i + 1 != ans_cnt) {
            if (i + 2 == ans_cnt) {
                for (int j = 0; j < y2; ++j) {
                    cout << 'o';
                }
            } else {
                cout << 'o';
            }
        }
    }
    return 0;
}