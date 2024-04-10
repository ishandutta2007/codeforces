#include <bits/stdc++.h>

using namespace std;

const int max_n = 606, inf = 1000111222;

int n, used[max_n];
vector<int> g[max_n];

void add_edge(int v1, int v2) {
    g[v1].push_back(v2);
    g[v2].push_back(v1);
    //cout << "add " << v1 << " " << v2 << endl;
}

const bool debug = false;

int get_cnt(const vector<int> &v) {
    if (v.empty()) {
        return 0;
    }
    cout << "? " << v.size() << endl;
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    if (debug) {
        if (v.size() == 1) {
            return 0;
        }
        if (v.size() == 2) {
            return 1;
        }
        return 3;
    } else {
        int res = 0;
        cin >> res;
        return res;
    }
}

int get_cnt_from_v(int v, vector<int> &to) {
    int comp = get_cnt(to);
    to.push_back(v);
    int all = get_cnt(to);
    to.pop_back();
    return all - comp;
}

int get_edge(int v) {
    vector<int> query;
    for (int i = 1; i <= n; ++i) {
        if (i != v && used[i] == 0) {
            query.push_back(i);
        }
    }
    if (get_cnt_from_v(v, query) == 0) {
        return -1;
    }
    while (query.size() > 1) {
        vector<int> a{query.begin(), query.begin() + query.size() / 2};
        vector<int> b{query.begin() + query.size() / 2, query.end()};
        if (get_cnt_from_v(v, a)) {
            query = a;
        } else {
            query = b;
        }
    }
    return query[0];
}

bool dfs(int v, int col) {
    used[v] = col;
    int ncol = 3 - col;
    //cout << "col " << v << " " << col << endl;
    while (true) {
        int to = get_edge(v);
        if (to == -1) {
            break;
        }
        add_edge(v, to);
        if (used[to] && used[to] != ncol) {
            return false;
        }
        if (!used[to] && !dfs(to, ncol)) {
            return false;
        }
    }
    return true;
}

vector<int> cycle;
int last;
bool need = true;

bool get_cycle(int v, int col) {
    used[v] = col;
    int ncol = 3 - col;
    for (int to : g[v]) {
        if (used[to] && used[to] != ncol) {
            last = to;
            cycle.push_back(v);
            return true;
        }
        if (!used[to] && get_cycle(to, ncol)) {
            if (need) {
                cycle.push_back(v);
            }
            if (v == last) {
                need = false;
            }
            return true;
        }
    }
    return false;
}

void wa() {
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && get_cycle(i, 1)) {
            break;
        }
    }
    cout << "N " << cycle.size() << endl;
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << endl;
    exit(0);
}

void wa2(vector<int> all) {
    memset(used, 0, sizeof(used));
    for (int v : all) {
        used[v] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        used[i] = 1 - used[i];
    }
    for (int v : all) {
        int to = get_edge(v);
        if (to != -1) {
            add_edge(v, to);
            wa();
        }
    }
}

void ok() {
    vector<int> first, second;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 1) {
            first.push_back(i);
        } else {
            second.push_back(i);
        }
    }
    if (get_cnt(first)) {
        wa2(first);
    } else if (get_cnt(second)) {
        wa2(second);
    } else {
        cout << "Y " << first.size() << endl;
        for (int v : first) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && !dfs(i, 1)) {
            wa();
        }
    }
    ok();
    return 0;
}