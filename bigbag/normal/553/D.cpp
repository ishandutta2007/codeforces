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

const int max_n = 111111, inf = 1111111111;

int n, m, k, bad[max_n], res[max_n], cnt[max_n];
set<pair<double, int> > s;
vector<int> g[max_n], V;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        bad[x] = 1;
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        if (bad[u] == 0 && bad[v] == 0) {
            ++cnt[u];
            ++cnt[v];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (bad[i] == 0) {
            if (g[i].size() == 0) {
                printf("1\n%d\n", i);
                return 0;
            }
            res[i] = 1;
            s.insert(make_pair(1.0 * cnt[i] / g[i].size(), i));
        }
    }
    pair<double, int> p2 = *s.begin();
    double Ans = p2.first;
    while (s.size() > 1) {
        pair<double, int> p = *s.begin();
        s.erase(p);
        int v = p.second;
        //cout << v << endl;
        for (int i = 0; i < g[v].size(); ++i) {
            if (res[g[v][i]] == 1) {
                s.erase(make_pair(1.0 * cnt[g[v][i]] / g[g[v][i]].size(), g[v][i]));
                --cnt[g[v][i]];
                s.insert(make_pair(1.0 * cnt[g[v][i]] / g[g[v][i]].size(), g[v][i]));
            }
        }
        pair<double, int> p2 = *s.begin();
        res[v] = 0;
        V.push_back(v);
        if (Ans < p2.first) {
            Ans = p2.first;
            V.clear();
        }
    }
    p2 = *s.begin();
    if (p2.first > Ans) {
        cout << 1 << endl << p2.second << endl;
        return 0;
    }
    //cout << Ans << endl;
    for (int i = 0; i < V.size(); ++i) {
        res[V[i]] = 1;
        //cout << "!" << V[i] << endl;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (res[i] == 1) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
        if (res[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}