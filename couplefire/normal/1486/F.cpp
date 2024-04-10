#include <stdio.h>
#include <memory.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N = 300005, M = 20;

int you[N] = { 0 }, d[N] = { 0 }, up[N][M] = { 0 }, sh[N] = { 0 }, ct[N] = { 0 };// gg[N] = { 0 };
vector<int> my[N];
map<pair<int,int>, int> our[N];
map<pair<int,int>, int>::iterator it;
long long ans = 0;

void dfs(int x) {
    int i = 0, y = 0, k = 0;
    for (i = 0; i < my[x].size(); i ++) {
        y = my[x][i];
        if (d[y]) continue;
        d[y] = d[x] + 1;
        up[y][0] = x;
        for (k = 1; ; k ++) {
            up[y][k] = up[up[y][k-1]][k-1];
            if (!up[y][k]) break;
        }
        dfs(y);
    }
}
int get(int x, int dd) {
    if (dd < 0) return 0;
    int k = 0;
    for (k = 0; dd; k ++) {
        if (dd & (1<<k)) {
            x = up[x][k];
            dd ^= (1<<k);
        }
    }
    return x;
}

int lca(int p, int q) {
    if (d[p] > d[q]) swap(p, q);
    q = get(q, d[q] - d[p]);
    if (p == q) return p;
    int k = 0;
    for (k = M - 1; k >= 0; k --) {
        if (up[p][k] != up[q][k]) {
            p = up[p][k];
            q = up[q][k];
        }
    }
    return up[p][0];
}

int tt(int x) {
    int i = 0, y = 0, ss = 0, sss = you[x];
    long long now = ct[x] * 1LL * (ct[x] - 1) / 2, now2 = 0, now3 = 0;
    for (i = 0; i < my[x].size(); i ++) {
        y = my[x][i];
        if (d[y] < d[x]) continue;
        ss = tt(y);
        sss += ss - sh[y];
        now -= sh[y] * 1LL * (sh[y] - 1) / 2;
        now2 += (ss - sh[y]) * 1LL * (ct[x] - sh[y]);
        //printf("## %d %d %d %d %d\n", x, y, ss, sh[y], ct[x]);
    }
    for (it = our[x].begin(); it != our[x].end(); it ++) {
        now += it->second * 1LL * (it->second - 1) / 2;
    }
    ans += now;
    ans += now2;
    now3 = you[x] * 1LL * ct[x];
    ans += now3;
    //printf("%d %lld %lld %lld\n", x, now, now2, now3);
    return sss;
}


void solve() {
    int n = 0, i = 0, m = 0, p = 0, q = 0, pp = 0, qq = 0, ca = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i ++) {
        my[i].clear();
        our[i].clear();
    }
    memset(d, 0, sizeof(d));
    memset(up, 0, sizeof(up));
    memset(sh, 0, sizeof(sh));
    //memset(gg, 0, sizeof(gg));
    memset(ct, 0, sizeof(ct));
    memset(you, 0, sizeof(you));
    for (i = 1; i < n; i ++) {
        scanf("%d%d", &p, &q);
        my[p].push_back(q);
        my[q].push_back(p);
    }
    d[1] = 1;
    up[1][0] = 0;
    dfs(1);
    scanf("%d", &m);
    while (m --) {
        scanf("%d%d", &p, &q);
        ca = lca(p, q);
        ct[ca] ++;
        if (p == q) continue;
        //gg[p] ++;
        //gg[q] ++;
        if (p != ca) {
            you[p] ++;
        }
        if (q != ca) {
            you[q] ++;
        }
        pp = get(p, d[p] - d[ca] - 1);
        qq = get(q, d[q] - d[ca] - 1);
        if (pp) sh[pp] ++;
        if (qq) sh[qq] ++;
        if (pp && qq) {
            if (pp > qq) {
                swap(pp, qq);
            }
            our[ca][make_pair(pp, qq)] ++;
        }
    }
    tt(1);
    printf("%lld\n", ans);
}

int main() {
    int o = 1;
    //scanf("%d", &o);
    while (o --) {
        solve();
        //fflush(stdout);
    }
    return 0;
}