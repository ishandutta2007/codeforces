/**
 *  created: 28/02/2021, 17:47:54
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_f = 27;

int n, f[max_f], num[max_n], sz[max_n], used[max_n], par[max_n];
vector<int> g[max_n];

void calc_sz(int v, int p) {
    sz[v] = 1;
    par[v] = p;
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        calc_sz(to, v);
        sz[v] += sz[to];
    }
}

vector<int> all[2];
int id1, id2;

void get_all(int v, int p) {
    if (sz[v] == f[id1]) {
        all[0].push_back(v);
    }
    if (sz[v] == f[id2]) {
        all[1].push_back(v);
    }
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        get_all(to, v);
    }
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd(int x) {
    return generator() % x;
}

bool check_cand(vector<pair<int, int>> &v);

bool check_cands(vector<vector<pair<int, int>>> &v) {
    if (v.size() == 2 && rnd(2)) {
        swap(v[0], v[1]);
    }
    for (auto &cand : v) {
        if (check_cand(cand)) {
            return true;
        }
        break;
    }
    return false;
}

bool check(int v) {
    //cout << "#" << v << endl;
    calc_sz(v, -1);
    if (sz[v] <= 3) {
        return true;
    }
    if (!num[sz[v]]) {
        return false;
    }
    //cout << "#" << v << endl;
    all[0].clear();
    all[1].clear();
    id1 = num[sz[v]] - 1;
    id2 = num[sz[v]] - 2;
    //cout << "%" << id1 << " " << id2 << endl;
    get_all(v, -1);
    assert(all[0].size() <= 1);
    assert(all[1].size() <= 2);
    //cout << "#" << v << ": " << all[0].size() << " " << all[1].size() << endl;
    if (all[0].size() + all[1].size() == 0) {
        return false;
    }
    if (all[0].size() + all[1].size() == 1) {
        int root = -1;
        if (all[0].size() == 1) {
            root = all[0][0];
        } else {
            root = all[1][0];
        }
        assert(par[root] != -1);
        vector<pair<int, int>> cand;
        cand.push_back({par[root], root});
        cand.push_back({root, v});
        return check_cand(cand);
    }
    if (all[0].size() + all[1].size() == 2) {
        vector<vector<pair<int, int>>> cands;
        for (int i = 0; i < 2; ++i) {
            for (int root : all[i]) {
                vector<pair<int, int>> cand;
                cand.push_back({par[root], root});
                cand.push_back({root, v});
                cands.push_back(cand);
            }
        }
        return check_cands(cands);
    } else {
        vector<vector<pair<int, int>>> cands;
        for (int i = 1; i < 2; ++i) {
            for (int root : all[i]) {
                vector<pair<int, int>> cand;
                cand.push_back({par[root], root});
                cand.push_back({root, v});
                cands.push_back(cand);
            }
        }
        return check_cands(cands);
    }
}

bool check_cand(vector<pair<int, int>> &v) {
    if (rnd(2)) {
        swap(v[0], v[1]);
    }
    for (const auto &p : v) {
        used[p.first] = 1;
        bool res = check(p.second);
        used[p.first] = 0;
        if (!res) {
            return false;
        }
    }
    return true;
}

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    f[0] = f[1] = 1;
    for (int i = 2; i < max_f; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        num[f[i]] = i;
        //cout << i << ": " << f[i] << endl;
    }
    if (0) {
        n = f[max_f - 1];
        for (int i = 1; i < n; ++i) {
            add_edge(i - 1, i);
        }
    } else {
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            add_edge(u, v);
        }
    }
    if (check(0)) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}