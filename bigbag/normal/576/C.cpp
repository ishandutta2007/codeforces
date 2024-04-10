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

const int max_n = 1111111, sz = 1000, inf = 1111111111;

int n, x[max_n], y[max_n], p[max_n], nx[max_n], ny[max_n], num[max_n];

bool cmp(int a, int b) {
    if (nx[a] < nx[b]) {
        return true;
    }
    if (nx[a] > nx[b]) {
        return false;
    }
    if ((nx[a] == nx[b] && ny[a] == ny[b])) {
        if (num[nx[a]] % 2 == 0) {
            return y[a] < y[b];
        }
        return y[a] > y[b];
    }
     if (num[nx[a]] % 2 == 0) {
        return ny[a] < ny[b];
    }
    return ny[a] > ny[b];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        nx[i] = x[i] / sz;
        ny[i] = y[i] / sz;
        num[nx[i]] = 1;
        p[i] = i;
    }
    for (int i = 1; i < max_n; ++i) {
        num[i] += num[i - 1];
    }
    sort(p, p + n, cmp);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        printf("%d ", p[i] + 1);
        //res += abs(y[p[i]] - y[p[i + 1]]);
        //res += abs(x[p[i]] - x[p[i + 1]]);
    }
    //cout << res << endl;
    //cout << "2500000000" << endl;
    return 0;
}