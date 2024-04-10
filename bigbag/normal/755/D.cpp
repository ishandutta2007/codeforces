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

const int max_n = 1011111, inf = 1011111111;

int n;

struct tree {
    int t[max_n];
    tree() {
        memset(t, 0, sizeof(t));
    }
    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] += x;
        }
    }
    int get(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }
    int sum(int l, int r) {
        //cout << l << " " << r << endl;
        if (l > r) {
            return sum(l, n) + sum(1, r);
        }
        return get(r) - get(l - 1);
    }
};

tree t1, t2;
int k;

int mn(int x, int k) {
    x -= k;
    if (x < 1) {
        x += n;
    }
    return x;
}

int pl(int x, int k) {
    x += k;
    if (x > n) {
        x -= n;
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    k = min(k, n - k);
    long long ans = 1;
    int l = 1;
    for (int i = 1; i <= n; ++i) {
        int r = pl(l, k);
        //cout << mn(l, k - 1) << " " << mn(r, 1) << "   " << pl(l, 1) << " " << pl(r, k - 1) << "    ans = ";
        ans += t1.sum(mn(l, k - 1), mn(r, 1));
        //ans += t2.sum(pl(l, 1), pl(r, k - 1));
        ans += 1;
        t1.update(l, 1);
        //t2.update(r, 1);
        //printf("%d\n", ans);
        printf("%I64d ", ans);
        l = r;
    }
    printf("\n");
    return 0;
}