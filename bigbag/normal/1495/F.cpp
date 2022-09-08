/**
 *  created: 31/03/2021, 23:09:03
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_lev = 18;

int n, q, p[max_n], a[max_n], nxt[max_n];
int fin[max_lev][max_n];
long long cost[max_lev][max_n], b[max_n];

void calc_nxt() {
    p[n] = inf;
    nxt[n] = n;
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = i + 1;
        while (p[i] > p[nxt[i]]) {
            nxt[i] = nxt[nxt[i]];
        }
    }
}

void calc_fin() {
    for (int i = 0; i < max_lev; ++i) {
        fin[i][n] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = i + 1;
        while (p[i] > p[nxt[i]]) {
            nxt[i] = nxt[nxt[i]];
        }
        long long tot = a[i];
        int pos = i + 1;
        for (int lev = max_lev - 1; lev >= 0; --lev) {
            if (fin[lev][pos] <= nxt[i]) {
                tot += cost[lev][pos];
                pos = fin[lev][pos];
            }
        }
        b[i] = min(b[i], tot);
        fin[0][i] = nxt[i];
        cost[0][i] = b[i];
        for (int lev = 1; lev < max_lev; ++lev) {
            fin[lev][i] = fin[lev - 1][fin[lev - 1][i]];
            cost[lev][i] = cost[lev - 1][i] + cost[lev - 1][fin[lev - 1][i]];
        }
    }
}

const int magic = 111;

int light_fin[max_lev][max_n], mn[max_lev][max_n];
long long light_cost[max_lev][max_n];

void calc_light_nxt() {
    for (int lev = 0; lev < max_lev; ++lev) {
        light_fin[lev][n] = n;
        mn[lev][n] = inf;
    }
    for (int i = n - 1; i >= 0; --i) {
        mn[0][i] = inf;
        int light_nxt = nxt[i];
        long long light_a = b[i];
        if (nxt[i] - i > magic) {
            light_nxt = i + 1;
            light_a = a[i];
            mn[0][i] = nxt[i];
        }

        light_fin[0][i] = light_nxt;
        light_cost[0][i] = light_a;
        for (int lev = 1; lev < max_lev; ++lev) {
            light_fin[lev][i] = light_fin[lev - 1][light_fin[lev - 1][i]];
            light_cost[lev][i] = light_cost[lev - 1][i] + light_cost[lev - 1][light_fin[lev - 1][i]];
            mn[lev][i] = min(mn[lev - 1][i], mn[lev - 1][light_fin[lev - 1][i]]);
        }
    }
}

map<pair<int, int>, long long> rem;

long long get_cost(int from, int to) {
    if (rem.count({from, to})) {
        return rem[{from, to}];
    }
    long long res = 0;
    //cout << from << " -> " << to << endl;
    while (to - from > magic) {
        //cout << from << ": " << light_fin[0][from] << " " << light_cost[0][from] << " " << mn[0][from] << endl;
        for (int lev = max_lev - 1; lev >= 0; --lev) {
            if (light_fin[lev][from] > to) {
                continue;
            }
            if (mn[lev][from] > to) {
                //cout << "#" << lev << " " << light_fin[lev][from] << endl;
                res += light_cost[lev][from];
                from = light_fin[lev][from];
            }
        }
        if (nxt[from] <= to) {
            res += b[from];
            from = nxt[from];
        }
    }
    while (from < to) {
        if (nxt[from] <= to) {
            res += b[from];
            from = nxt[from];
        } else {
            res += a[from];
            ++from;
        }
    }
    return rem[{from, to}] = res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &b[i]);
    }
    calc_nxt();
    calc_fin();
    calc_light_nxt();
    set<int> all{0, n};
    long long ans = get_cost(0, n);
    while (q--) {
        int x;
        scanf("%d", &x);
        --x;
        if (x) {
            auto p = all.insert(x);
            auto it = p.first;
            if (!p.second) {
                int pr = *prev(it);
                int nxt = *next(it);
                ans -= get_cost(pr, x);
                ans -= get_cost(x, nxt);
                ans += get_cost(pr, nxt);
                all.erase(it);
            } else {
                int pr = *prev(it);
                int nxt = *next(it);
                ans += get_cost(pr, x);
                ans += get_cost(x, nxt);
                ans -= get_cost(pr, nxt);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}