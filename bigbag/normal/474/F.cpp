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

const int max_n = 111111, max_lev = 20;

struct tree {
    pair<int, int> mins[4 * max_n];
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            mins[v] = make_pair(value, 1);
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        if (mins[2 * v].first == mins[2 * v + 1].first) {
            mins[v] = make_pair(mins[2 * v].first, mins[2 * v].second + mins[2 * v + 1].second);
        } else {
            mins[v] = min(mins[2 * v], mins[2 * v + 1]);
        }
    }
    pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mins[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        pair<int, int> p1 = get_min(2 * v, tl, mid, l, mid), p2 = get_min(2 * v + 1, mid + 1, tr, mid + 1, r);
        if (p1.first == p2.first) {
            return make_pair(p1.first, p1.second + p2.second);
        }
        return min(p1, p2);
    }
};

int n, m, a[max_n], num[max_n];
int gcd[max_lev][max_n];
tree t;

void get_all_gcd() {
    for (int i = 0; i < n; ++i) {
        gcd[0][i] = a[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            gcd[i][j] = __gcd(gcd[i - 1][j], gcd[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_gcd(int l, int r) {
    int lev = num[r - l + 1];
    return __gcd(gcd[lev][l], gcd[lev][r - (1 << lev) + 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        t.update(1, 0, n - 1, i, a[i]);
    }
    get_all_gcd();
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        int g = get_gcd(l, r);
        pair<int, int> p = t.get_min(1, 0, n - 1, l, r);
        //cout << "gcd = " << g << ", min = " << p.first << ", cnt_min = " << p.second << endl;
        if (g < p.first) {
            printf("%d\n", r - l + 1);
        } else {
            printf("%d\n", r - l + 1 - p.second);
        }
    }
    return 0;
}