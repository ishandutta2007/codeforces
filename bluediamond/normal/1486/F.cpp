#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T {
        int x;
        int y;
};

ll func(ll x) {
        return x * (x - 1) / 2;
}

const int N = (int) 3e5 + 7;
const int K = 20;
int n;
int p[N];
int dep[N];
int euler_tour[2 * N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
int both[N];
int at_least_one[N];
int anc[K][N];
vector<int> meet[N];
vector<int> g[N];
pair<int, int> tab_lca[2 * N][K];

void dfs_lca(int a, int pr = 0)
{
    p[a] = pr;
    euler_tour[++tour_sz] = a;
    first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
    for (auto &b : g[a])
    {
        if (b == pr)
            continue;
        dep[b] = 1 + dep[a];
        dfs_lca(b, a);
        euler_tour[++tour_sz] = a;
        last_time_on_tour[a] = tour_sz;
    }
}

void lcaTM()
{
    dfs_lca(1);
    for (int i = 2; i <= tour_sz; i++)
    {
        lg2[i] = 1 + lg2[i / 2];
    }
    for (int i = 1; i <= tour_sz; i++)
    {
        tab_lca[i][0] = {dep[euler_tour[i]], euler_tour[i]};
    }
    for (int k = 1; (1 << k) <= tour_sz; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= tour_sz; i++)
        {
            tab_lca[i][k] = min(tab_lca[i][k - 1], tab_lca[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int lca(int a, int b)
{
    if (first_time_on_tour[a] > last_time_on_tour[b])
    {
        swap(a, b);
    }
    a = first_time_on_tour[a];
    b = last_time_on_tour[b];
    int k = lg2[b - a + 1];
    return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}

int m;
int cnt[N];
T v[N];
ll ret;

void gather(int a) {
        for (auto &b : g[a]) {
                if (b == p[a])
                        continue;
                gather(b);
                at_least_one[a] += at_least_one[b];
                both[a] += both[b];
                cnt[a] += cnt[b];
        }
}

bool is_anc(int node, int x) {
        if (dep[node] > dep[x])
                return 0;
        int dif = dep[x] - dep[node];
        for (int j = 0; (1 << j) <= dif; j++)
                if (dif & (1 << j))
                        x = anc[j][x];
        return (node == x);
}

int k_th_anc(int node, int k) {
        for (int j = 0; (1 << j) <= k; j++)
                if (k & (1 << j))
                        node = anc[j][node];
        return node;
}

bool on_way(int node, int x, int y) {
        int z = lca(x, y);
        if (dep[node] < dep[z])
                return 0;
        return is_anc(node, x) | is_anc(node, y);
}

mt19937 rng((long long) (new char));

int rn(int l, int r) {
        return l + rng() % (r - l + 1);
}

void print() {
        freopen ("input", "w", stdout);
        int n = 1000, m = 2000;
        cout << n << "\n";
        for (int i = 2; i <= n; i++) {
                cout << i << " " << rn(1, i - 1) << "\n";
        }
        cout << m << "\n";
        for (int i = 1; i <= m; i++) {
                cout << rn(1, n) << " " << rn(1, n) << "\n";
        }
        exit(0);
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        ///print();

      ///  freopen ("input", "r", stdin);

        cin >> n;
        for (int i = 1; i < n; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        lcaTM();
        for (int i = 1; i <= n; i++)
                anc[0][i] = p[i];
        for (int k = 1; (1 << k) <= n; k++)
                for (int i = 1; i <= n; i++)
                        anc[k][i] = anc[k - 1][anc[k - 1][i]];
        /**for (int i = 1; i <= n; i++) {
                assert(lca(i, i) == i);
                for (int j = i + 1; j <= n; j++)
                        cout << i << " " << j << " : " << lca(i, j) << "\n";
        }**/

        cin >> m;
        for (int i = 1; i <= m; i++) {
                cin >> v[i].x >> v[i].y;
                int z = lca(v[i].x, v[i].y);
                at_least_one[v[i].x]++;
                at_least_one[v[i].y]++;
                at_least_one[z]--;
                both[z]++;
                meet[z].push_back(i);
                if (z == v[i].x || z == v[i].y) {
                        cnt[p[z]]--;
                        cnt[v[i].x + v[i].y - z]++;
                        continue;
                }
                cnt[v[i].x]++;
                cnt[v[i].y]++;
                cnt[z]--;
                cnt[p[z]]--;
        }
        gather(1);
        for (int i = 1; i <= n; i++)
                ret += func(cnt[i]);
        for (int i = 2; i <= n; i++) {
                for (int k = 0; k < (int) g[i].size(); k++)
                        if (g[i][k] == p[i]) {
                                swap(g[i][k], g[i][0]);
                        }
        }
        for (int i = 2; i <= n; i++) {
                assert(g[i][0] == p[i]);
        }
        for (int i = 1; i <= n; i++) {
                /// minus the ones which are bad only in one position
                /// plus the ones which are bad in two positions
                /// minus
                for (auto &j : g[i]) {
                        if (j != p[i])
                                ret -= func(at_least_one[j] - both[j]);
                        else
                                ret -= func(at_least_one[i] - both[i]);
                }
                /// plus
                map<pair<int, int>, int> fr;
                for (auto &j : meet[i]) {
                        if (v[j].x == i || v[j].y == i)
                                continue;
                        int x = v[j].x;
                        int y = v[j].y;
                        int dif_x = dep[x] - dep[i] - 1;
                        int dif_y = dep[y] - dep[i] - 1;
                        int val_x = k_th_anc(x, dif_x);
                        int val_y = k_th_anc(y, dif_y);
                        if (val_x > val_y)
                                swap(val_x, val_y);
                        ret += fr[{val_x, val_y}]++;
                }
                map<int, int> cn;
                for (auto &k : meet[i]) {
                        if (!on_way(i, v[k].x, v[k].y))
                                continue;
                        int x = v[k].x;
                        int y = v[k].y;
                        int dif_x = dep[x] - dep[i] - 1;
                        int dif_y = dep[y] - dep[i] - 1;
                        int val_x = k_th_anc(x, dif_x);
                        int val_y = k_th_anc(y, dif_y);
                        cn[val_x]++;
                        cn[val_y]++;
                        if (val_x == val_y)
                                cn[val_x]--;
                }
                for (auto &j1 : g[i]) {
                        int j2 = p[i];
                        if (j1 == j2)
                                continue;
                        ret += func(at_least_one[j1] - both[j1] - cn[j1]);

                }
        }
        cout << ret << "\n";
}