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

const int max_n = 101111, inf = 1011111111;
const int max_x = 55;

int n, A[max_x], B[max_x], q[max_x];
long long pw[max_x];

bool check(int cnt) {
    int mn = cnt;
    for (int i = 0; i < max_x; ++i) {
        mn = min(mn, A[i]);
        q[i] = mn;
    }
    int f = 0;
    for (int i = max_x - 1; i >= 0; --i) {
        int can = q[i] - f;
        if (can < B[i]) {
            return false;
        }
        f += B[i];
        can = q[i] - f;
        if (q[i] + can < A[i]) {
            return false;
        }
        f += A[i] - q[i];
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    pw[0] = 1;
    for (int i = 1; i < max_x; ++i) {
        pw[i] = pw[i - 1] * 2;
    }
    for (int i = 0; i < n; ++i) {
        long long x;
        scanf("%I64d", &x);
        int f = 0;
        for (int j = 0; j < max_x; ++j) {
            if (pw[j] == x) {
                f = 1;
                ++A[j];
                break;
            }
        }
        if (f == 0) {
            for (int j = 0; j + 1 < max_x; ++j) {
                if (pw[j] < x && x < pw[j + 1]) {
                    ++B[j];
                    break;
                }
            }
        }
    }
    int f = 0;
    for (int i = 1; i <= A[0]; ++i) {
        if (check(i)) {
            printf("%d ", i);
            f = 1;
        }
    }
    if (f == 0) {
        printf("-1\n");
    }
    return 0;
}