#include <bits/stdc++.h>

using namespace std;

const int inf = 1000111222;

int n, a[2][3];

int solve_max(int a[3], int b[3]) {
    return min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
}

int solve_min(int a[3], int b[3]) {
    int x = min(a[0], b[2]);
    a[0] -= x;
    b[2] -= x;

    x = min(a[0], b[0]);
    a[0] -= x;
    b[0] -= x;

    x = min(a[1], b[0]);
    a[1] -= x;
    b[0] -= x;

    x = min(a[1], b[1]);
    a[1] -= x;
    b[1] -= x;

    x = min(a[2], b[1]);
    a[2] -= x;
    b[1] -= x;

    x = min(a[2], b[2]);
    a[2] -= x;
    b[2] -= x;
    return a[0] + a[1] + a[2];
}

int solve(int a[3], int b[3]) {
    int A[3], B[3];
    int res = inf;
    for (int i = 0; i < 3; ++i) {
        copy(a, a + 3, A);
        copy(b, b + 3, B);
        rotate(A, A + i, A + 3);
        rotate(B, B + i, B + 3);
        res = min(res, solve_min(A, B));
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    int mx = solve_max(a[0], a[1]);
    cout << solve(a[0], a[1]) << " " << mx << endl;
    return 0;
}