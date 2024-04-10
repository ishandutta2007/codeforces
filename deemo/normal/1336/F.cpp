#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1.5e5 + 100;
const int LOG = 19;

int n, m, k;
vector<int> adj[MAXN];
int uu[MAXN], vv[MAXN], lc[MAXN], leg1[MAXN], leg2[MAXN];
int child_id[MAXN];
int par[LOG][MAXN], depth[MAXN];
#define tm ihatethis
int st[MAXN], ft[MAXN], tm;
int degen = -1;

void dfs(int v, int p = -1, int de = 0) {
    par[0][v] = p;
    depth[v] = de;
    st[v] = tm++;
    if (~p)
        adj[v].erase(find(adj[v].begin(), adj[v].end(), p));
    for (int i = 0; i < adj[v].size(); i++)
        child_id[adj[v][i]] = i;
    for (int u: adj[v])
        dfs(u, v, de + 1);
    ft[v] = tm;
}

void lca_prep() {
    for (int w = 1; w < LOG; w++)
        for (int v = 0; v < n; v++)
            if (par[w-1][v] == -1)
                par[w][v] = -1;
            else
                par[w][v] = par[w-1][par[w-1][v]];
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    for (int w = LOG-1; ~w; w--)
        if (depth[u] - (1<<w) >= depth[v])
            u = par[w][u];
    if (u == v) return u;

    for (int w = LOG-1; ~w; w--)
        if (par[w][u] ^ par[w][v])
            u = par[w][u], v = par[w][v];
    return par[0][u];
}

int get_par_at_depth(int v, int d) {
    assert(depth[v] >= d);
    for (int w = LOG-1; ~w; w--)
        if (depth[v] - (1<<w) >= d)
            v = par[w][v];
    return v;
}

int sec[MAXN];
pair<pii, pii> sort_id[MAXN];
ll ans;
int fen[MAXN];

void add_fen(int v, int val) {
    for (; v<MAXN; v+=v&-v)
        fen[v] += val;
}

int get_fen(int v) {
    int res = 0;
    for (; v; v-=v&-v)
        res += fen[v];
    return res;
}

void count_single_path(int p, int v) {
    if (depth[v] - depth[p] < k) return;
    p = get_par_at_depth(v, depth[p] + k);
    ans += get_fen(ft[p]) - get_fen(st[p]);
}

using namespace __gnu_pbds;

typedef tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int dpar[MAXN];
int dsub[MAXN];
ordered_set dsets[MAXN];
vector<int> dadj[MAXN];
int get_par(int v) {return dpar[v]==v? v: get_par(dpar[v]);}
void ddfs(int path, int other_set, int req, int root) {
    if (depth[root] + req <= depth[vv[path]]) {
        int p = get_par_at_depth(vv[path], depth[root] + req);
        ans += dsets[other_set].order_of_key({ft[p], -1});
        ans -= dsets[other_set].order_of_key({st[p], -1});
    }
    for (int u: dadj[path])
        ddfs(u, other_set, req, root);
}

void ddfs_add(int path, int other_set) {
    dsets[other_set].insert({st[vv[path]], path});
    for (int u: dadj[path])
        ddfs_add(u, other_set);
}

void count_double(int l, int r) {
    if (r - l == 1) return;

    int root = sort_id[sec[l]].F.S;
    vector<int> vec(sec + l, sec + r);
    sort(vec.begin(), vec.end(), [](int p1, int p2) {
            return st[uu[p1]] < st[uu[p2]];
        });

    vector<pii> edges;
    for (int i = 0; i + 1 < vec.size(); i++) {
        int p1 = vec[i], p2 = vec[i+1];
        int anc = lca(uu[p1], uu[p2]);
        int common = depth[anc] - depth[root];
        edges.push_back({common, i});
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for (auto [common, i]: edges) {
        int p1 = vec[i], p2 = vec[i+1];
        p1 = get_par(p1), p2 = get_par(p2);
        assert(p1 != p2);
        if (dsub[p1] < dsub[p2])
            swap(p1, p2);

        if (common >= k-1)
            ans += 1ll*dsub[p1]*dsub[p2];
        else
            ddfs(p2, p1, k-common, root);

        dpar[p2] = p1;
        dadj[p1].push_back(p2);
        dsub[p1] += dsub[p2];
        ddfs_add(p2, p1);
    }

    for (int p: vec) {
        dpar[p] = p;
        dsub[p] = 1;
        dadj[p].clear();
        dsets[p].clear();
        dsets[p].insert({st[vv[p]], p});
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0); // super descriptive name
    lca_prep();
    for (int i = 0; i < m; i++) {
        cin >> uu[i] >> vv[i], uu[i]--, vv[i]--;
        if (st[uu[i]] > st[vv[i]])
            swap(uu[i], vv[i]);
        lc[i] = lca(uu[i], vv[i]);
        if (uu[i] == lc[i])
            leg1[i] = --degen;
        else
            leg1[i] = child_id[get_par_at_depth(uu[i], depth[lc[i]] + 1)];
        leg2[i] = child_id[get_par_at_depth(vv[i], depth[lc[i]] + 1)];
        sort_id[i] = {{depth[lc[i]], lc[i]}, {leg1[i], leg2[i]}};
    }
    iota(dpar, dpar+m, 0);
    fill(dsub, dsub+m, 1);
    for (int i = 0; i < m; i++)
        dsets[i].insert({st[vv[i]], i});
    iota(sec, sec + m, 0);
    sort(sec, sec + m, [](int p1, int p2) {
            return sort_id[p1] < sort_id[p2];
        });

    for (int l = 0; l < m;) {
        int r = l;
        while (r < m && sort_id[sec[l]] == sort_id[sec[r]]) {
            int p = sec[r++];
            if (leg1[p] != -1)
                count_single_path(lc[p], uu[p]);
            count_single_path(lc[p], vv[p]);
        }

        count_double(l, r);

        for (; l < r; l++) {
            int p = sec[l];
            if (leg1[p] != -1)
                add_fen(st[uu[p]]+1, 1);
            add_fen(st[vv[p]]+1, 1);
        }
    }

    cout << ans << "\n";
	return 0;
}