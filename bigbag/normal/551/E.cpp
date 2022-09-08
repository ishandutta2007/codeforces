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

const int max_n = 555555, sz = 717, inf = 1011111111;

int n, q, a[max_n], num[max_n], l[sz], r[sz], f[sz];
multiset<int> s[sz];

void update(int L, int R, int x) {
    int n1 = num[L], n2 = num[R];
    for (int i = n1 + 1; i < n2; ++i) {
        f[i] += x;
        if (f[i] > inf) {
            f[i] = inf;
        }
    }
    if (n1 == n2) {
        for (int i = L; i <= R; ++i) {
            s[n1].erase(s[n1].find(a[i]));
            a[i] += x;
            if (a[i] > inf) {
                a[i] = inf;
            }
            s[n1].insert(a[i]);
        }
        return;
    }
    for (int i = L; i <= r[n1]; ++i) {
        s[n1].erase(s[n1].find(a[i]));
        a[i] += x;
        if (a[i] > inf) {
            a[i] = inf;
        }
        s[n1].insert(a[i]);
    }
    for (int i = R; i >= l[n2]; --i) {
        s[n2].erase(s[n2].find(a[i]));
        a[i] += x;
        if (a[i] > inf) {
            a[i] = inf;
        }
        s[n2].insert(a[i]);
    }
}

int get_ans(int x) {
    int mn = -1, mx = -1;
    for (int i = 0; i < sz; ++i) {
        int y = x - f[i];
        if (y >= 0 && s[i].count(y)) {
            for (int j = l[i]; j <= r[i]; ++j) {
                if (a[j] == y) {
                    mn = j;
                    break;
                }
            }
            break;
        }
    }
    if (mn == -1) {
        return -1;
    }
    for (int i = sz - 1; i >= 0; --i) {
        int y = x - f[i];
        if (y >= 0 && s[i].count(y)) {
            for (int j = r[i]; j >= l[i]; --j) {
                if (a[j] == y) {
                    mx = j;
                    break;
                }
            }
            break;
        }
    }
    return mx - mn;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < sz; ++i) {
        l[i] = 0;
        if (i) {
            l[i] = r[i - 1] + 1;
        }
        r[i] = min(n - 1, l[i] + sz - 1);
        for (int j = l[i]; j <= r[i]; ++j) {
            num[j] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        s[num[i]].insert(a[i]);
    }
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l;
            --r;
            update(l, r, x);
        } else {
            int y;
            scanf("%d", &y);
            printf("%d\n", get_ans(y));
        }
    }
    return 0;
}