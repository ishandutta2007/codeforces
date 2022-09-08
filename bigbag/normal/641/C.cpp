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

const int max_n = 1111111, inf = 1111111111;

int n, q, a[2][max_n], poz[2];
vector<int> ans[2];

void write(int q) {
    for (int i = poz[q]; i < n / 2; ++i) {
        ans[q].push_back(a[q][i]);
    }
    for (int i = 0; i < poz[q]; ++i) {
        ans[q].push_back(a[q][i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            a[i][j] = i + 1 + 2 * j;
        }
    }
    int q1 = 0, q2 = 1;
    while (q--) {
        int tp, x;
        scanf("%d", &tp);
        if (tp == 2) {
            swap(q1, q2);
        } else {
            scanf("%d", &x);
            if (x < 0) {
                x = (n + x) % n;
            }
            if (x % 2 == 0) {
                poz[q1] -= x / 2;
                if (poz[q1] < 0) {
                    poz[q1] += n / 2;
                }
                poz[q2] -= x / 2;
                if (poz[q2] < 0) {
                    poz[q2] += n / 2;
                }
            } else {
                swap(q1, q2);
                --x;
                poz[q1] -= (x / 2 + 1);
                if (poz[q1] < 0) {
                    poz[q1] += n / 2;
                }
                poz[q2] -= x / 2;
                if (poz[q2] < 0) {
                    poz[q2] += n / 2;
                }
            }
        }
    }
    write(q1);
    write(q2);
    for (int i = 0; i < n / 2; ++i) {
        printf("%d %d ", ans[q1][i], ans[q2][i]);
    }
    printf("\n");
    return 0;
}