#include <bits/stdc++.h>

using namespace std;

const int max_n = 505555, inf = 1000111222;
const int max_x = (1 << 20) + 5;

int n, x[max_n], y[max_n], a[max_n], b[max_n];
bool used[max_x];
vector<int> g[max_x];
vector<pair<int, int>> g2[max_x];

void clr() {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < max_x; ++i) {
        g[i].clear();
        g2[i].clear();
    }
}

int get_a(int i) {
    if (i < 0) {
        return b[-1 - i];
    }
    return a[i];
}

int get_b(int i) {
    if (i < 0) {
        return a[-1 - i];
    }
    return b[i];
}

int get_id(int i) {
    if (i < 0) {
        return -1 - i;
    }
    return i;
}

struct Cycle;

vector<Cycle> cycles;

struct Cycle {
    int shift;
    vector<int> ids;
    vector<pair<int, int>> add;

    Cycle() {
    }

    Cycle(int shift, const vector<int> &ids): shift(shift), ids(ids) {
    }

    void write() {
        rotate(ids.begin(), ids.begin() + shift, ids.end());
        for (pair<int, int> &p : add) {
            p.first -= shift;
            if (p.first < 0) {
                p.first += ids.size();
            }
        }
        sort(add.begin(), add.end());
        int cur = 0;
        for (int i = 0; i < ids.size(); ++i) {
            int id = ids[i], f = 0;
            if (id < 0) {
                id = -id - 1;
                f = 1;
            }
            printf("%d %d ", 2 * id + f + 1, 2 * id + 1 - f + 1);
            while (cur < add.size() && add[cur].first == i) {
                cycles[add[cur].second].write();
                ++cur;
            }
        }
    }
};

void dfs(int cid) {
    used[cid] = 1;
    //cout << cid << endl;
    for (int i = 0; i < cycles[cid].ids.size(); ++i) {
        const int B = get_b(cycles[cid].ids[i]);
        while (!g2[B].empty()) {
            const int id_c = g2[B].back().first;
            const int shift = g2[B].back().second;
            g2[B].pop_back();
            if (used[id_c]) {
                continue;
            }
            //cout << "#" << B << " " << shift << endl;
            cycles[id_c].shift = shift;
            cycles[cid].add.push_back({i, id_c});
            dfs(id_c);
        }
    }
}

bool check() {
    clr();
    cycles.clear();
    for (int i = 0; i < n; ++i) {
        g[a[i]].push_back(i);
        g[b[i]].push_back(-1 - i);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int pos = i;
            vector<int> cycle;
            cycle.push_back(i);
            used[i] = 1;
            while (a[i] != get_b(cycle.back())) {
                const int B = get_b(cycle.back());
                while (!g[B].empty() && used[get_id(g[B].back())]) {
                    g[B].pop_back();
                }
                if (g[B].empty()) {
                    return false;
                }
                cycle.push_back(g[B].back());
                used[get_id(g[B].back())] = 1;
                g[B].pop_back();
            }
            cycles.push_back(Cycle(0, cycle));
        }
    }
    if (0) {
        for (auto &cycle : cycles) {
            for (int id : cycle.ids) {
                cout << id << " ";
            }
            cout << endl;
        }
    }
    clr();
    for (int i = 0; i < cycles.size(); ++i) {
        for (int j = 0; j < cycles[i].ids.size(); ++j) {
            g2[get_a(cycles[i].ids[j])].push_back({i, j});
        }
    }
    dfs(0);
    for (int i = 0; i < cycles.size(); ++i) {
        if (!used[i]) {
            return false;
        }
    }
    return true;
}

bool check(int mid) {
    const int mask = (1 << mid) - 1;
    for (int j = 0; j < n; ++j) {
        a[j] = x[j] & mask;
        b[j] = y[j] & mask;
    }
    return check();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    int l = 0, r = 21;
    //cout << check(20) << endl;
    //cycles[0].write();
    //return 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    check(l);
    printf("%d\n", l);
    cycles[0].write();
    puts("");
    if (0) {
        for (int i = 0; i < n; ++i) {
            x[i] &= (1 << l) - 1;
            y[i] &= (1 << l) - 1;
            cout << x[i] << " " << y[i] << endl;
        }
    }
    return 0;
}