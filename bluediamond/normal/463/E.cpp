#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(int x) {
        if (x <= 1) {
                return 0;
        } else {
                for (int i = 2; i * i <= x; i++) {
                        if (x % i == 0) {
                                return 0;
                        }
                }
                return 1;
        }
}

vector<int> primes;

vector<int> getPrimes(int x) {
        vector<int> sol;
        for (auto &d : primes) {
                if (d * d > x) {
                        break;
                }
                bool is = 0;
                while (x % d == 0) {
                        x /= d;
                        is = 1;
                }
                if (is) {
                        sol.push_back(d);
                }
        }
        if (x > 1) {
                sol.push_back(x);
        }
        return sol;
}

void print(vector<int> a) {
        cout << " : ";
        for (auto &x : a) {
                cout << x << " ";
        }
        cout << "\n";
}

const int N = (int) 1e5 + 7;
const int R = sqrt((int) 2e6) + 100;

int n;
int q;
int v[N];
vector<int> g[N];
int sz[N];
int cn[N];
int comp[N];
int level[N];
int first[N];
int par[N];
int cnt_comp;
map<int, set<int>> levels[N];
vector<int> who[N];

void dfs(int a) {
        sz[a] = 1;
        for (auto &b : g[a]) {
                if (sz[b] == 0) {
                        dfs(b);
                        if (sz[b] > sz[cn[a]]) {
                                cn[a] = b;
                        }
                }
        }
}

void dfs2(int a, int p) {
        par[a] = p;
        if (cn[p] == a) {
                comp[a] = comp[p];
        } else {
                comp[a] = ++cnt_comp;
                first[cnt_comp] = a;
        }
        who[comp[a]].push_back(a);
        level[a] = 1 + level[p];
        vector<int> pVec = getPrimes(v[a]);
        for (auto &p : pVec) {
                levels[comp[a]][p].insert(level[a]);
        }
        for (auto &b : g[a]) {
                if (b != p) {
                        dfs2(b, a);
                }
        }
}

void del(int a) {
        vector<int> pVec = getPrimes(v[a]);
        for (auto &p : pVec) {
                levels[comp[a]][p].erase(level[a]);
        }
}

void make(int a, int x) {
        v[a] = x;
        vector<int> pVec = getPrimes(v[a]);
        for (auto &p : pVec) {
                levels[comp[a]][p].insert(level[a]);
        }
}

int query(int a) {
        vector<int> pVec = getPrimes(v[a]);
        a = par[a];
        int ans = -1;
        while (a) {
                int c = comp[a];
                for (auto &p : pVec) {
                        if (levels[c].count(p) == 0) {
                                continue;
                        }
                        auto it = levels[c][p].lower_bound(level[a] + 1);
                        if (it != levels[c][p].begin()) {
                                it--;
                                ans = max(ans, *it);
                        }
                }
                if (ans != -1) {
                       int dif = ans - level[first[c]];
                       return who[c][dif];
                }
                a = first[c];
                a = par[a];
        }
        return -1;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        for (int i = 1; i <= R; i++) {
                if (isPrime(i)) {
                        primes.push_back(i);
                }
        }

        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
                cin >> v[i];
        }
        for (int i = 1; i < n; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        dfs(1);
        dfs2(1, 0);
        while (q--) {
                int t, a;
                cin >> t >> a;
                if (t == 1) {
                        cout << query(a) << "\n";
                } else {
                        int b;
                        cin >> b;
                        del(a);
                        make(a, b);
                }
        }
}