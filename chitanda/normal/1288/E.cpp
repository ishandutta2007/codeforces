#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define y1     y114514
#define pb     push_back
#define mkp    make_pair
#define fi     first
#define se     second
#define all(a) a.begin(), a.end()

typedef pair<int, int>     pii;
typedef unsigned long long ull;
typedef long long          ll;

const int M = 1000000007;

const int maxn = 600005;
int       n, m;

int a[maxn];
int ans1[maxn], ans2[maxn];

int rt[maxn];
int ocur[maxn];

int cnt[maxn * 30];
int ls[maxn * 30], rs[maxn * 30];
int tot;

int r[maxn];

#define mid ((l + r) >> 1)

int add(int &rt, int l, int r, int v) {
    int t = ++tot;
    ls[t] = ls[rt], rs[t] = rs[rt];
    cnt[t] = cnt[rt];

    ++cnt[t];
    if (l == r) return t;
    if (v <= mid)
        ls[t] = add(ls[rt], l, mid, v);
    else
        rs[t] = add(rs[rt], mid + 1, r, v);
    return t;
}

int ask(int t, int l, int r, int x) {
    if (r <= x || !t) return cnt[t];
    return ask(ls[t], l, mid, x) + (x > mid ? ask(rs[t], mid + 1, r, x) : 0);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        ans1[i] = i;
        ans2[i] = i;
        ocur[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        ocur[n - i + 1] = i;
        r[i]            = add(r[i - 1], 0, n + m, 0);
    }

    int sum0 = 0;
    for (int i = n + 1; i <= n + m; ++i) {
        scanf("%d", a + i);
        int &p = ocur[a[i]];
        r[i]   = add(r[i - 1], 0, n + m, p);
        if (!p) ++sum0;

        //printf("%d: %d\n", a[i], p);

        //printf("%d %d\n", ask(r[i], 0, n + m, p), ask(r[p], 0, n + m, p));
        //printf("%d\n", cnt[r[i]]);

        ans1[a[i]] = 1;
        ans2[a[i]] = max(ans2[a[i]],
                         ask(r[i], 0, n + m, p) - ask(r[p], 0, n + m, p));

        p = i;
    }

    for (int i = 1; i <= n; ++i) {
        int &p  = ocur[i];
        ans2[i] = max(ans2[i], ask(r[n + m], 0, n + m, p) - ask(r[p], 0, n + m, p) + 1);
        printf("%d %d\n", ans1[i], ans2[i]);
    }
    return 0;
}