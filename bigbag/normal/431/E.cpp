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

const int max_n = 111111, inf = 1001111111;

struct fenwick {
    long long t[2 * max_n];
    fenwick() {
        memset(t, 0, sizeof(t));
    }
    void update(int poz, int x) {
        for (; poz < 2 * max_n; poz = (poz | (poz + 1))) {
            t[poz] += x;
        }
    }
    long long get(int poz) {
        long long res = 0;
        for (; poz >= 0; poz = (poz & (poz + 1)) - 1) {
            res += t[poz];
        }
        return res;
    }
};

int n, q, a[max_n], tp[max_n], poz[max_n], x[max_n];
long long v[max_n];
vector<int> b;
map<int, int> m;
fenwick f1, f2;

bool check(double x, long long v) {
    int poz = upper_bound(b.begin(), b.end(), (int) min(1.0 * inf, x)) - b.begin() - 1;
    int cnt = f2.get(poz);
    long long sum = f1.get(poz);
    return x * cnt >= v + sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b.push_back(a[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d", &tp[i]);
        if (tp[i] == 1) {
            scanf("%d%d", &poz[i], &x[i]);
            b.push_back(x[i]);
            --poz[i];
        } else {
            scanf("%I64d", &v[i]);
        }
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int cnt = 0;
    for (int i = 0; i < b.size(); ++i) {
        m[b[i]] = cnt;
        ++cnt;
    }
    for (int i = 0; i < n; ++i) {
        f1.update(m[a[i]], a[i]);
        f2.update(m[a[i]], 1);
    }
    for (int i = 0; i < q; ++i) {
        if (tp[i] == 1) {
            f1.update(m[a[poz[i]]], -a[poz[i]]);
            f2.update(m[a[poz[i]]], -1);
            a[poz[i]] = x[i];
            f1.update(m[a[poz[i]]], a[poz[i]]);
            f2.update(m[a[poz[i]]], 1);
        } else {
            double l = 0, r = 1e16;
            while (r - l > 1e-4) {
                double mid = (l + r) / 2;
                if (check(mid, v[i])) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            printf("%.10f\n", r);
        }
    }
    return 0;
}