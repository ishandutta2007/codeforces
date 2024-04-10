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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n, m, s, t, u[max_n], v[max_n], dd[max_n], dp[max_n], poz[max_n];
long long dist1[max_n], dist2[max_n];
vector<int> g[max_n], d[max_n], rg[max_n], rd[max_n], g2[max_n], rg2[max_n], qq;
set<pair<int, int> > good;

void get_dp(int v) {
    if (dp[v] != -1) {
        return;
    }
    dp[v] = -2;
    if (poz[v]) {
        dp[v] = poz[v];
    }
    sort(g2[v].begin(), g2[v].end());
    for (int i = 0; i < g2[v].size(); ++i) {
        if (poz[v] && poz[v] + 1 == poz[g2[v][i]] && (i == 0 || g2[v][i] != g2[v][i - 1])) {
            continue;
        }
        get_dp(g2[v][i]);
        dp[v] = max(dp[v], dp[g2[v][i]]);
    }
}

bool ok(int a, int b) {
    return good.count(make_pair(a, b));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &dd[i]);
        g[u[i]].push_back(v[i]);
        d[u[i]].push_back(dd[i]);
        rg[v[i]].push_back(u[i]);
        rd[v[i]].push_back(dd[i]);
    }
    for (int i = 1; i <= n; ++i) {
        dist1[i] = inf;
        dist2[i] = inf;
    }
    dist1[s] = 0;
    set<pair<long long, int> > q;
    for (int i = 1; i <= n; ++i) {
        q.insert(make_pair(dist1[i], i));
    }
    while (!q.empty()) {
        pair<long long, int> p = *q.begin();
        q.erase(p);
        int v = p.second;
        for (int i = 0; i < g[v].size(); ++i) {
            if (dist1[v] + d[v][i] < dist1[g[v][i]]) {
                q.erase(make_pair(dist1[g[v][i]], g[v][i]));
                dist1[g[v][i]] = dist1[v] + d[v][i];
                q.insert(make_pair(dist1[g[v][i]], g[v][i]));
            }
        }
    }
    dist2[t] = 0;
    for (int i = 1; i <= n; ++i) {
        q.insert(make_pair(dist2[i], i));
    }
    while (!q.empty()) {
        pair<long long, int> p = *q.begin();
        q.erase(p);
        int v = p.second;
        for (int i = 0; i < rg[v].size(); ++i) {
            if (dist2[v] + rd[v][i] < dist2[rg[v][i]]) {
                q.erase(make_pair(dist2[rg[v][i]], rg[v][i]));
                dist2[rg[v][i]] = dist2[v] + rd[v][i];
                q.insert(make_pair(dist2[rg[v][i]], rg[v][i]));
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (dist1[u[i]] + dd[i] == dist1[v[i]]) {
            g2[u[i]].push_back(v[i]);
            rg2[v[i]].push_back(u[i]);
        }
    }
    int cnt = n, vv = t;
    while (vv != s) {
        qq.push_back(vv);
        poz[vv] = cnt;
        --cnt;
        vv = rg2[vv][0];
    }
    qq.push_back(vv);
    poz[vv] = cnt;
    reverse(qq.begin(), qq.end());
    /*for (int i = 0; i < qq.size(); ++i) {
        cout << qq[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < qq.size(); ++i) {
        cout << poz[qq[i]] << " ";
    }
    cout << endl;*/
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        get_dp(i);
        //cout << i << " " << dp[i] << endl;
    }
    int mx = -1;
    for (int i = 0; i + 1 < qq.size(); ++i) {
        mx = max(mx, dp[qq[i]]);
        if (mx == poz[qq[i]]) {
            good.insert(make_pair(qq[i], qq[i + 1]));
        }
    }
    for (int i = 0; i < m; ++i) {
        if (dist1[u[i]] + dd[i] + dist2[v[i]] == dist1[t]) {
            if (ok(u[i], v[i])) {
                printf("YES\n");
            } else {
                if (dd[i] == 1) {
                    printf("NO\n");
                } else {
                    printf("CAN 1\n");
                }
            }
        } else {
            long long x = dist1[u[i]] + dd[i] + dist2[v[i]] - dist1[t] + 1;
            if (dd[i] > x) {
                printf("CAN %I64d\n", x);
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}