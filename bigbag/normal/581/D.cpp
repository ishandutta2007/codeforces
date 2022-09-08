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

const int max_n = 555, inf = 1111111111;

int n, s, a[3], b[3], p[3];
char ans[max_n][max_n], c[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i] >> b[i];
        s += a[i] * b[i];
    }
    for (int i = 1; i * i <= s; ++i) {
        if (i * i == s) {
            n = i;
            break;
        }
    }
    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int q = 0; q < 2; ++q) {
        for (int w = 0; w < 2; ++w) {
            for (int e = 0; e < 2; ++e) {
                p[0] = 0;
                p[1] = 1;
                p[2] = 2;
                do {
                    c[0] = 'A' + p[0];
                    c[1] = 'A' + p[1];
                    c[2] = 'A' + p[2];
                    int a1 = a[p[0]], b1 = b[p[0]];
                    int a2 = a[p[1]], b2 = b[p[1]];
                    int a3 = a[p[2]], b3 = b[p[2]];
                    if (a1 == n) {
                        if (a2 + a3 == n && b1 + b2 == n && b1 + b3 == n) {
                            cout << n << endl;
                            for (int i = 0; i < a1; ++i) {
                                for (int j = 0; j < b1; ++j) {
                                    ans[i][j] = c[0];
                                }
                                for (int j = b1; j < n; ++j) {
                                    if (i < a2) {
                                        ans[i][j] = c[1];
                                    } else {
                                        ans[i][j] = c[2];
                                    }
                                }
                                printf("%s\n", ans[i]);
                            }
                            return 0;
                        }
                        if (a2 == n && a3 == n && b1 + b2 + b3 == n) {
                            cout << n << endl;
                            for (int i = 0; i < a1; ++i) {
                                for (int j = 0; j < n; ++j) {
                                    ans[i][j] = c[0];
                                    if (j >= b1) {
                                        ans[i][j] = c[1];
                                    }
                                    if (j >= b1 + b2) {
                                        ans[i][j] = c[2];
                                    }
                                }
                                printf("%s\n", ans[i]);
                            }
                            return 0;
                        }
                    }
                } while (next_permutation(p, p + 3));
                swap(a[2], b[2]);
            }
            swap(a[1], b[1]);
        }
        swap(a[0], b[0]);
    }
    cout << -1 << endl;
    return 0;
}