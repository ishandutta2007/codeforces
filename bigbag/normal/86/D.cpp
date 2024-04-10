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

const int max_n = 222222, max_x = 1111111, inf = 1111111111;

int sq;

struct querry {
    int l, r, num;
    querry() {
    }
    void read() {
        scanf("%d%d", &l, &r);
        --l;
        --r;
    }
    bool operator < (const querry &q) const {
        int l1 = l / sq, l2 = q.l / sq;
        return l1 < l2 || l1 == l2 && r < q.r;
    }
};

int n, t, a[max_n];
long long ans, cnt[max_x], anss[max_n];
querry p[max_n];

void add(int x) {
    ans += (2 * cnt[x] + 1) * x;
    //cout << x << "  " << ans << endl;
    ++cnt[x];
}

void del(int x) {
    ans = ans - 2 * cnt[x] * x + x;
    --cnt[x];
}

long long get_ans(int l, int r) {
    for (int i = l; i <= r; ++i) {
        add(a[i]);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < t; ++i) {
        p[i].read();
        p[i].num = i;
    }
    sq = sqrt(n) + 5;
    sort(p, p + t);
    int l = p[0].l, r = p[0].r;
    //cout << l << " " << r << endl;
    ans = get_ans(l, r);
    anss[p[0].num] = ans;
    for (int i = 1; i < t; ++i) {
        if (p[i].l > p[i - 1].r) {
            for (int j = p[i - 1].l; j <= p[i - 1].r; ++j) {
                del(a[j]);
            }
            for (int j = p[i].l; j <= p[i].r; ++j) {
                add(a[j]);
            }
        } else if (p[i].l >= p[i - 1].l && p[i].r >= p[i - 1].r) {
            for (int j = p[i - 1].l; j < p[i].l; ++j) {
                //cout << "del " << a[j] << endl;
                del(a[j]);
            }
            for (int j = p[i - 1].r + 1; j <= p[i].r; ++j) {
                add(a[j]);
            }
        } else if (p[i].l >= p[i - 1].l && p[i].r < p[i - 1].r) {
            for (int j = p[i - 1].l; j < p[i].l; ++j) {
                del(a[j]);
            }
            for (int j = p[i].r + 1; j <= p[i - 1].r; ++j) {
                del(a[j]);
            }
        } else if (p[i].r <= p[i - 1].r) {
            for (int j = p[i].r + 1; j <= p[i - 1].r; ++j) {
                del(a[j]);
            }
            for (int j = p[i].l; j < p[i - 1].l; ++j) {
                add(a[j]);
            }
        } else {
            for (int j = p[i - 1].r + 1; j <= p[i].r; ++j) {
                add(a[j]);
            }
            for (int j = p[i].l; j < p[i - 1].l; ++j) {
                add(a[j]);
            }
        }
        anss[p[i].num] = ans;
    }
    for (int i = 0; i < t; ++i) {
        //printf("%lld\n", anss[i]);
        cout << anss[i] << endl;
    }
    return 0;
}