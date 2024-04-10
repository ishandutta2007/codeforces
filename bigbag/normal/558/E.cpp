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

const int max_n = 111111, sz = 1111, inf = 1111111111;

int n, k, cnt[sz][26], f[sz], l[sz], r[sz], a[max_n], num[max_n], c[26];
char s[max_n];

void build() {
    for (int i = 0; i < sz; ++i) {
        l[i] = i * sz;
        r[i] = (i + 1) * sz - 1;
        f[i] = -1;
        for (int j = l[i]; j <= r[i] && j < max_n; ++j) {
            num[j] = i;
            if (j < n) {
                ++cnt[i][a[j]];
            }
        }
    }
}

void push(int q) {
    if (f[q] != -1) {
        for (int i = 0; i < 26; ++i) {
            cnt[q][i] = 0;
        }
        for (int i = l[q]; i <= r[q]; ++i) {
            a[i] = f[q];
            ++cnt[q][f[q]];
        }
        f[q] = -1;
    }
}

void update(int L, int R, int x) {
    int n1 = num[L];
    int n2 = num[R];
    if (n1 == n2) {
        push(n1);
        for (int i = L; i <= R; ++i) {
            --cnt[n1][a[i]];
            a[i] = x;
            ++cnt[n1][a[i]];
        }
        return;
    }
    for (int i = n1 + 1; i < n2; ++i) {
        f[i] = x;
    }
    push(n1);
    push(n2);
    for (int i = L; i <= r[n1]; ++i) {
        --cnt[n1][a[i]];
        a[i] = x;
        ++cnt[n1][a[i]];
    }
    for (int i = l[n2]; i <= R; ++i) {
        --cnt[n2][a[i]];
        a[i] = x;
        ++cnt[n2][a[i]];
    }
}

void get_c(int L, int R) {
    for (int i = 0; i < 26; ++i) {
        c[i] = 0;
    }
    int n1 = num[L];
    int n2 = num[R];
    if (n1 == n2) {
        push(n1);
        for (int i = L; i <= R; ++i) {
            ++c[a[i]];
        }
        return;
    }
    for (int i = n1 + 1; i < n2; ++i) {
        if (f[i] != -1) {
            c[f[i]] += r[i] - l[i] + 1;
        } else {
            for (int j = 0; j < 26; ++j) {
                c[j] += cnt[i][j];
            }
        }
    }
    if (f[n1] != -1) {
        c[f[n1]] += r[n1] - L + 1;
    } else {
        for (int i = L; i <= r[n1]; ++i) {
            ++c[a[i]];
        }
    }
    if (f[n2] != -1) {
        c[f[n2]] += R - l[n2] + 1;
    } else {
        for (int i = l[n2]; i <= R; ++i) {
            ++c[a[i]];
        }
    }
}

void write() {
    for (int i = 0; i < sz; ++i) {
        push(i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%c", a[i] + 'a');
    }
    printf("\n");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &k, s);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'a';
    }
    build();
    while (k--) {
        int l, r, t;
        scanf("%d%d%d", &l, &r, &t);
        --l;
        --r;
        get_c(l, r);
        if (t == 1) {
            for (int i = 0; i < 26; ++i) {
                if (c[i]) {
                    update(l, l + c[i] - 1, i);
                    l += c[i];
                }
            }
        } else {
            for (int i = 26; i >= 0; --i) {
                if (c[i]) {
                    update(l, l + c[i] - 1, i);
                    l += c[i];
                }
            }
        }
        //write();
    }
    write();
    return 0;
}