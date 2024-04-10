#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct Edge {
	int to, cap, rev;
	Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};

struct Netflow {
	vector<Edge> egs[505];
    int n;
    void inline init(int N) { n = N; loop(i, n + 2) egs[i].clear(); }
	void inline addedge(int u, int v, int cap) {
		egs[u].emb(v, cap, SZ(egs[v]));
		egs[v].emb(u, 0, SZ(egs[u]) - 1);
	}
	int dist[505];
	bool bfs(int s, int t) {
		queue<int> q; q.push(s);
		memset(dist, -1, sizeof(int) * (n + 2));
        dist[s] = 0;
		while (SZ(q)) {
			int now = q.front(); q.pop();
            parse(e, egs[now]) {
                if (e.cap && !~dist[e.to]) {
                    dist[e.to] = dist[now] + 1;
                    q.push(e.to);
                }
            }
		}
        return ~dist[t];
	}
    int iter[5005];
    int dfs(int now, int to, int cap = INT_MAX) {
        if (now == to) return cap;
        for (int &i = iter[now]; i < SZ(egs[now]); ++i) {
            Edge &e = egs[now][i];
            if (e.cap && dist[e.to] > dist[now]) {
                int f = dfs(e.to, to, min(cap, e.cap));
                if (f) {
                    e.cap -= f;
                    egs[e.to][e.rev].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }
    ll get(int s, int t) {
        ll res = 0;
        while (bfs(s, t)) {
            memset(iter, 0, sizeof(iter));
            int tmp;
            while ((tmp = dfs(s, t))) res += tmp;
        }
        return res;
    }
} nf;

int n, m, k;
int u[2555], v[2555];
vector<int> nei[55];
int tb[105], bd[105];
bool ban[105];
ll dp[55][105];
int lst[55][105];
int x[55], y[55];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    nf.init(n << 1 | 1);
    cont(i, m) {
        int u, v; scanf("%d%d", &u, &v);
        nei[u].pub(v); nei[v].pub(u);
        ::u[i] = u; ::v[i] = v;
        nf.addedge(u, v + n, 1);
    }
    cont(i, k) scanf("%d%d", x + i, y + i);
    cont(j, n) nf.addedge(0, j, 1), nf.addedge(j + n, n << 1 | 1, 1);
    memset(tb, -1, sizeof(tb));
    int need = n - nf.get(0, n << 1 | 1), sneed = need;
    tb[need] = 0;
    int ts = 0;
    while (need <= k) {
        int mneed = 0, toban = -1;
        cont(i, n << 1) if (!ban[i]) {
            nf.init(n << 1);
            ban[i] = 1;
            cont(j, m) {
                if (!ban[u[j]] && !ban[v[j] + n]) nf.addedge(u[j], v[j] + n, 1);
            }
            cont(j, n) nf.addedge(0, j, 1), nf.addedge(j + n, n << 1 | 1, 1);
            int nb = n - nf.get(0, n << 1 | 1);
            if (nb > mneed) {
                mneed = nb;
                toban = i;
            }
            ban[i] = 0;
        }
        need = mneed;
        tb[need] = ++ts;
        bd[need] = (toban > n ? -(toban - n) : toban);
        ban[toban] = 1;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][sneed] = 0;
    cont(i, k) loop(j, need + 1) if (~dp[i - 1][j]) {
        circ(k, max(i + 1, j), need) if (~tb[k]) {
            ll ndp = dp[i - 1][j] + max(0ll, x[i] - 1ll * y[i] * (tb[k] - tb[j]));
            if (ndp > dp[i][k]) {
                dp[i][k] = ndp;
                lst[i][k] = j;
            }
        }
    }
    vector<int> ans;
    int ni = k, nj = need;
    if (~dp[ni][nj]) {
        while (ni) {
            ans.pub(0);
            int mj = lst[ni][nj];
            while (nj != mj) {
                if (~tb[nj]) ans.pub(bd[nj]);
                --nj;
            }
            --ni;
        }
    }
    else {
        loop(i, k) ans.pub(0);
    }
    reverse(all(ans));
    printf("%d\n", SZ(ans));
    parse(it, ans) printf("%d ", it);
    return 0;
}