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

const int max_n = 111111, inf = 1011111111;

struct tree {
    long long t[max_n];
    tree() {
        memset(t, 0, sizeof(t));
    }
    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] += x;
        }
    }
    long long get(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }
};

int n, a[max_n];
tree t1, t2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    long long q = 0, w = 1LL * n * (n + 1);
    for (int len = 1; len <= n; ++len) {
        q += 1LL * (n - len + 1) * (1LL * len * (len - 1)) / 2;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    long long cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        cnt += t1.get(a[i]);
        t1.update(a[i], 1);
        q -= 2LL * (i + 1) * t2.get(a[i]);
        t2.update(a[i], n - i);
    }
    printf("%.10f\n", (double) (cnt + ((long double) q) / w));
    return 0;
}