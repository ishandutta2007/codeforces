/**
 *  created: 29/08/2021, 19:13:16
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int copy_dsu[max_n];

struct dsu {
    int p_or_sz[max_n];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p_or_sz[i] = -1;
        }
    }

    void init_from_copy(int n) {
        for (int i = 0; i < n; ++i) {
            p_or_sz[i] = copy_dsu[i];
        }
    }

    int find_set(int v) {
        if (p_or_sz[v] < 0) {
            return v;
        }
        return p_or_sz[v] = find_set(p_or_sz[v]);
    }

    bool union_set(int v1, int v2) {
        v1 = find_set(v1);
        v2 = find_set(v2);
        if (v1 == v2) {
            return false;
        }
        if (-p_or_sz[v1] > -p_or_sz[v2]) {
            swap(v1, v2);
        }
        p_or_sz[v2] += p_or_sz[v1];
        p_or_sz[v1] = v2;
        return true;
    }
};

int n, k, max_deg[max_n], D[max_n][max_n];
int deg[max_n];
dsu d;

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}






struct GroundSetElement {
    int u, v;
    int cost;
    bool taken;

    GroundSetElement() {
    }

    GroundSetElement(int u, int v, int cost): u(u), v(v), cost(cost), taken(false) {
    }

    bool operator < (const GroundSetElement &g) const {
        return cost < g.cost;
    }
};

const int max_e = max_n * max_n / 2;

vector<GroundSetElement> elems;
int cur_deg[max_n];

int parent[max_e], weight[max_e];
pair<int, int> dist[max_e];
vector<pair<int, int>> edges;
bool is_s[max_e], is_t[max_e];

void prepare() {
    d.init_from_copy(n);
    copy(deg, deg + n, cur_deg);
    for (int i = 0; i < elems.size(); ++i) {
        if (elems[i].taken) {
            d.union_set(elems[i].u, elems[i].v);
            --cur_deg[elems[i].u];
            --cur_deg[elems[i].v];
        }
    }
}

bool is_ok1(const GroundSetElement &a) {
    return d.find_set(a.u) != d.find_set(a.v);
}

bool is_ok2(const GroundSetElement &a) {
    return cur_deg[a.u] > 0 && cur_deg[a.v] > 0;
}

bool augment() {
    edges.clear();
    prepare();
    for (int i = 0; i < elems.size(); ++i) {
        if (!elems[i].taken) {
            is_s[i] = is_ok1(elems[i]);
            is_t[i] = is_ok2(elems[i]);
            weight[i] = -elems[i].cost;
        } else {
            is_s[i] = is_t[i] = false;
            weight[i] = elems[i].cost;
        }
        weight[i] *= -1;
    }
    for (int i = 0; i < elems.size(); ++i) {
        if (elems[i].taken) {
            elems[i].taken = false;
            prepare();
            elems[i].taken = true;
            for (int j = 0; j < elems.size(); ++j) {
                if (!elems[j].taken) {
                    if (is_ok1(elems[j])) {
                        edges.push_back({i, j});
                    }
                    if (is_ok2(elems[j])) {
                        edges.push_back({j, i});
                    }
                }
            }
        }
    }

    for (int i = 0; i < elems.size(); ++i) {
        dist[i] = {inf, inf};
        parent[i] = -1;
        if (is_s[i]) {
            dist[i] = {weight[i], 0};
        }
    }
    for (bool change = true; change; ) {
        change = false;
        for (const auto &edge : edges) {
            pair<int, int> ndist = dist[edge.first];
            if (ndist.first == inf) {
                continue;
            }
            ndist.first += weight[edge.second];
            ++ndist.second;
            if (dist[edge.second] > ndist) {
                dist[edge.second] = ndist;
                parent[edge.second] = edge.first;
                change = true;
            }
        }
    }
    int t = -1;
    for (int i = 0; i < elems.size(); ++i) {
        if (is_t[i] && (t == -1 || dist[t] > dist[i])) {
            t = i;
        }
    }
    if (t == -1 || dist[t].first == inf) {
        return false;
    }
    while (t != -1) {
        elems[t].taken ^= 1;
        t = parent[t];
    }
    return true;
}

int ans = inf;

int solve(int need_e, int cost) {
    for (int i = 0; i < n; ++i) {
        copy_dsu[i] = d.p_or_sz[i];
    }
    for (int i = 0; i < elems.size(); ++i) {
        elems[i].taken = false;
    }
    int it = 0;
    while (augment()) {
        ++it;
        int res = cost;
        for (int i = 0; i < elems.size(); ++i) {
            if (elems[i].taken) {
                res += elems[i].cost;
            }
        }
        int cnt = need_e - it;
        for (int i = 0; i < elems.size() && cnt; ++i) {
            if (!elems[i].taken) {
                res += elems[i].cost;
                --cnt;
            }
        }
        /*prepare();
        for (int i = 0; i < elems.size(); ++i) {
            if (!elems[i].taken && d.union_set(elems[i].u, elems[i].v)) {
                res += elems[i].cost;
            }
        }*/
        if (res >= ans) {
            return -1;
        }
    }
    if (it != need_e) {
        return -1;
    }
    int res = cost;
    for (int i = 0; i < elems.size(); ++i) {
        if (elems[i].taken) {
            //cout << "#" << elems[i].u << " " << elems[i].v << " " << elems[i].cost << endl;
            res += elems[i].cost;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        n = 50;
        k = 5;
        for (int i = 0; i < k; ++i) {
            max_deg[i] = inf;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                D[i][j] = rand() % 100 + 1;
            }
        }
    } else {
        cin >> n >> k;
        for (int i = 0; i < k; ++i) {
            cin >> max_deg[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cin >> D[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i < k && j < k) {
                continue;
            }
            elems.push_back({i, j, D[i][j]});
        }
    }
    sort(elems.begin(), elems.end());
    int small_e = (k * (k - 1)) / 2;
    int TOT = 0;
    vector<int> all_masks;
    for (int mask = 0; mask < (1 << small_e); ++mask) {
        all_masks.push_back(mask);
    }
    const int seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    shuffle(all_masks.begin(), all_masks.end(), generator);
    for (int mask : all_masks) {
        d.init(n);
        copy(max_deg, max_deg + k, deg);
        fill(deg + k, deg + n, inf);
        int num = 0, cost = 0;
        bool ok = 1;
        int need_e = n - 1;
        for (int i = 0; i < k && ok; ++i) {
            for (int j = i + 1; j < k && ok; ++j) {
                if (get_bit(mask, num)) {
                    if (!d.union_set(i, j) || !deg[i] || !deg[j]) {
                        ok = 0;
                        break;
                    }
                    --deg[i];
                    --deg[j];
                    cost += D[i][j];
                    --need_e;
                    //cout << i << " " << j << endl;
                }
                ++num;
            }
        }
        if (!ok) {
            continue;
        }
        ++TOT;
        int res = solve(need_e, cost);
        if (res == -1) {
            continue;
        }
        //cout << res << " " << cost << "   " << res + cost << ", mask = " << mask << endl;
        ans = min(ans, res);
    }
    cout << ans << "\n";
    return 0;
}