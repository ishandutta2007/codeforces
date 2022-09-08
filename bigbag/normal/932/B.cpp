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

const int max_n = 1000111, inf = 1000111222;

int q, l, r, k, a[max_n], sum[10][max_n];

int f(int n) {
    int res = 1;
    while (n) {
        if (n % 10) {
            res *= n % 10;
        }
        n /= 10;
    }
    return res;
}

int g(int n) {
    if (a[n]) {
        return a[n];
    }
    if (n < 10) {
        return n;
    }
    return a[n] = g(f(n));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1; i < max_n; ++i) {
        sum[g(i)][i] = 1;
        for (int j = 0; j < 10; ++j) {
            sum[j][i] += sum[j][i - 1];
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", sum[k][r] - sum[k][l - 1]);
    }
    return 0;
}