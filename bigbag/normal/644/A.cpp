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

int n, a, b, num[3], ans[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &a, &b);
    num[1] = 1;
    num[2] = 2;
    for (int i = 0; i < a; ++i) {
        int q = 1, w = 2;
        if (i % 2) {
            swap(q, w);
        }
        for (int j = 0; j < b; ++j) {
            if (num[q] <= n) {
                ans[i][j] = num[q];
                num[q] += 2;
            }
            swap(q, w);
        }
    }
    if (num[1] <= n || num[2] <= n) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}