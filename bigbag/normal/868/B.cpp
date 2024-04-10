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

const int max_n = 5, inf = 1011111111;
const long double eps = 1e-8;

int a[max_n];
int t1, t2;
long double b[max_n];

bool check(int t1, int t2) {
    while (t1 != t2) {
        //cout << t1 << " " << t2 << endl;
        int nx = (t1 + 1);
        if (t1 != 11) {
            for (int i = 0; i < 3; ++i) {
                if (t1 - eps <= b[i] && b[i] - eps <= nx) {
                    return false;
                }
            }
        } else {
            for (int i = 0; i < 3; ++i) {
                if (t1 - eps <= b[i] && b[i] - eps <= 12) {
                    return false;
                }
                if (0 - eps <= b[i] && b[i] - eps <= 0) {
                    return false;
                }
            }
        }
        t1 = nx % 12;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a[0] >> a[1] >> a[2] >> t1 >> t2;
    a[0] %= 12;
    t1 %= 12;
    t2 %= 12;
    int cur = a[0] * 3600 + a[1] * 60 + a[2];
    b[0] = cur;
    b[1] = cur % 3600;
    b[2] = cur % 60;
    b[0] /= 3600;
    b[1] /= 300;
    b[2] /= 5;
    //cout << b[0] << " " << b[1] << " " << b[2] << endl;
    if (check(t1, t2) || check(t2, t1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}