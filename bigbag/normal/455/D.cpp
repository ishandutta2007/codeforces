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

const int max_n = 111111, bsz = 333, inf = 1111111111;

int n, q, a[max_n], b[bsz][2 * bsz], l[bsz], r[bsz], cnt[bsz][max_n];

int del(int poz) {
    for (int i = 0; i < bsz; ++i) {
        if (l[i] <= poz && poz <= r[i]) {
            poz -= l[i];
            int res = b[i][poz];
            --cnt[i][res];
            for (int j = poz; j < r[i] - l[i]; ++j) {
                b[i][j] = b[i][j + 1];
            }
            --r[i];
            for (int j = i + 1; j < bsz; ++j) {
                --l[j];
                --r[j];
            }
            return res;
        }
    }
}

void ins(int poz, int x) {
    for (int i = 0; i < bsz; ++i) {
        if (l[i] <= poz && poz <= r[i]) {
            poz -= l[i];
            ++cnt[i][x];
            ++r[i];
            for (int j = r[i] - l[i]; j > poz; --j) {
                b[i][j] = b[i][j - 1];
            }
            b[i][poz] = x;
            for (int j = i + 1; j < bsz; ++j) {
                ++l[j];
                ++r[j];
            }
            return;
        }
    }
}

int get_cnt(int l1, int r1, int k) {
    int numl, numr;
    for (int i = 0; i < bsz; ++i) {
        if (l[i] <= l1 && l1 <= r[i]) {
            numl = i;
        }
        if (l[i] <= r1 && r1 <= r[i]) {
            numr = i;
        }
    }
    if (numl == numr) {
        int res = 0;
        for (int i = l1 - l[numl]; i <= r1 - l[numl]; ++i) {
            if (b[numl][i] == k) {
                ++res;
            }
        }
        return res;
    }
    int res = 0;
    for (int i = numl + 1; i < numr; ++i) {
        res += cnt[i][k];
    }
    for (int i = l1 - l[numl]; i <= r[numl] - l[numl]; ++i) {
        if (b[numl][i] == k) {
            ++res;
        }
    }
    for (int i = 0; i <= r1 - l[numr]; ++i) {
        if (b[numr][i] == k) {
            ++res;
        }
    }
    return res;
}

void build() {
    for (int i = 0; i < bsz; ++i) {
        l[i] = i * bsz;
        r[i] = (i + 1) * bsz - 1;
        for (int j = l[i]; j <= r[i]; ++j) {
            b[i][j - l[i]] = a[j];
            ++cnt[i][a[j]];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    build();
    scanf("%d", &q);
    int lastans = 0;
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r;
            scanf("%d%d", &l, &r);
            l = (l + lastans - 1) % n;
            r = (r + lastans - 1) % n;
            if (l > r) {
                swap(l, r);
            }
            //printf("! %d %d\n", l, r);
            int x = del(r);
            ins(l, x);
        } else {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            l = (l + lastans - 1) % n;
            r = (r + lastans - 1) % n;
            k = (k + lastans - 1) % n + 1;
            if (l > r) {
                swap(l, r);
            }
            //printf("! %d %d  %d\n", l, r, k);
            lastans = get_cnt(l, r, k);
            //printf("%d\n", lastans);
            printf("             %d\n", lastans);
        }
        if (q % bsz == 0) {
            for (int i = 0; i < bsz; ++i) {
                for (int j = l[i]; j < n && j <= r[i]; ++j) {
                    a[j] = b[i][j - l[i]];
                    --cnt[i][a[j]];
                }
            }
            build();
        }
    }
    return 0;
}