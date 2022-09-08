#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_k = 5;
const int max_perm = 122;

int n, k;

struct perm {
    int p[max_k];

    perm get_nxt(const perm &a) const {
        perm res;
        for (int i = 0; i < k; ++i) {
            res.p[i] = p[a.p[i]];
        }
        return res;
    }

    bool operator < (const perm &a) const {
        for (int i = 0; i < k; ++i) {
            if (p[i] != a.p[i]) {
                return p[i] < a.p[i];
            }
        }
        return false;
    }
};

int id[max_n], nxt[max_perm][max_perm], mn[max_perm], last[max_perm];
vector<int> all;

void prec() {
    vector<perm> all_perm;
    map<perm, int> ids;
    perm p;
    for (int i = 0; i < k; ++i) {
        p.p[i] = i;
    }
    do {
        ids[p] = all_perm.size();
        all_perm.push_back(p);
    } while (next_permutation(p.p, p.p + k));
    for (int i = 0; i < all_perm.size(); ++i) {
        for (int j = 0; j < all_perm.size(); ++j) {
            nxt[i][j] = ids[all_perm[i].get_nxt(all_perm[j])];
        }
    }
    for (int i = 0; i < n; ++i) {
        perm p;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &p.p[j]);
            --p.p[j];
        }
        id[i] = ids[p];
    }
}

int ans;
long long sum;

void dfs(int h) {
    int st = last[h];
    if (st == 0) {
        ++ans;
    }
    last[h] = all.size();
    while (st < all.size()) {
        dfs(nxt[h][all[st]]);
        ++st;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    prec();
    int tot = 1;
    for (int i = 1; i <= k; ++i) {
        tot *= i;
    }
    for (int i = 0; i < tot; ++i) {
        mn[i] = inf;
    }
    for (int i = n - 1; i >= 0; --i) {
        mn[id[i]] = i;
        vector<int> poss;
        for (int id = 0; id < tot; ++id) {
            last[id] = 0;
        }
        for (int id = 1; id < tot; ++id) {
            if (mn[id] != inf) {
                poss.push_back(mn[id]);
            }
        }
        sort(poss.begin(), poss.end());
        poss.erase(unique(poss.begin(), poss.end()), poss.end());
        int last_pos = i;
        ans = 1;
        all.clear();
        for (int pos : poss) {
            if (last[id[pos]]) {
                continue;
            }
            all.push_back(id[pos]);
            sum += 1LL * ans * (pos - last_pos);
            if (ans == 1) {
                ans = 0;
            }
            for (int id = 0; id < tot; ++id) {
                if (id == 0 || last[id]) {
                    dfs(id);
                }
            }
            last_pos = pos;
            if (ans == tot) {
                break;
            }
        }
        sum += 1LL * ans * (n - last_pos);
    }
    printf("%I64d\n", sum);
    return 0;
}