#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

#define pb push_back

const int MXL = 0x3f3f3f3f;
const int mxn = 500006;
using ai = int[mxn];
using avi = vi[mxn];

ai dfn, low, scc; int cnt, scnt;
stack<int,vi> sta; bool ins[mxn];
int tarjan(int x, vi *e) {
        dfn[x] = low[x] = ++cnt;
        sta.push(x); ins[x] = true;
        for (auto i : e[x]) low[x] = min(low[x],
                dfn[i] ? dfn[ins[i] ? i : x] : tarjan(i, e));
        if (low[x] == dfn[x]) {
                ++scnt; int t;
                do { t = sta.top(); sta.pop(); ins[t] = false;
                        scc[t] = scnt; } while (t != x);
        }
        return low[x];
}

int n, m;
avi e;
int sz[mxn];

int s;

bool v[mxn];
vi ring;
bool dfs(int x) { // sdfs
        if (v[x] && x == s) return true;
        if (v[x]) return false;
        v[x] = true;
        ring.pb(x);
        for (auto i : e[x])
                if (dfs(i))
                        return true;
        ring.pop_back();
        return false;
}

int rid[mxn];

avi e2;

struct MM { // minmax
        int mn, mx;
        MM() : mn(MXL), mx(-MXL) {}
        MM(int x) : mn(x), mx(x) {}
        MM(int mn, int mx) : mn(mn), mx(mx) {}
        void add(MM b) {
                mn = min(mn, b.mn);
                mx = max(mx, b.mx);
        }
};

// forward / back
avi ef, eb;
MM ff[mxn], fb[mxn];
bool vf[mxn], vb[mxn];

int c[mxn];

// !!
//  !!
void dp(vi *e, MM *f, bool *v) {
        function<void(int)> cal = [&](int x) {
                if (v[x]) return;
                v[x] = true;
                for (auto i : e[x]) {
                        if (!rid[i]) {
                                cal(i);
                                f[x].add(f[i]);
                        } else {
                                f[x].add(rid[i]);
                        }
                }
        };
        for (int i = 1; i <= n; ++i) if (!v[i])
                cal(i);
}

int main() {
        #define NIE ({puts("-1"); return 0;})
        #define ZERO ({puts("-1"); puts(""); return 0;})
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
                int x, y;
                scanf("%d%d", &x, &y);
                e[x].pb(y);
        }

        for (int i = 1; i <= n; ++i) if (!dfn[i])
                tarjan(i, e);

        for (int i = 1; i <= n; ++i)
                ++sz[scc[i]];

        for (int i = 1; i <= n; ++i) if (sz[scc[i]] > 1)
                s = i;

        // 

        if (!s) NIE;

        // 

        dfs(s);

        int rn = ring.size();

        for (int i = 0; i < rn; ++i)
                rid[ring[i]] = i + 1;

        // 

        fill(dfn, dfn + n + 1, 0);
        cnt = scnt = 0;
        for (int i = 1; i <= n; ++i)
                for (auto j : e[i])
                        if (!rid[i] && !rid[j])
                                e2[i].pb(j);

        fill(sz, sz + n + 1, 0);

        for (int i = 1; i <= n; ++i) if (!dfn[i])
                tarjan(i, e2);

        for (int i = 1; i <= n; ++i)
                ++sz[scc[i]];

        for (int i = 1; i <= n; ++i) if (sz[scc[i]] > 1)
                ZERO;

        // DP

        for (int i = 1; i <= n; ++i)
                for (auto j : e[i])
                        /*if (!rid[i] || !rid[j] || (rid[i] - 1 + 1) % rn != rid[j] - 1) */{ // ? 
                                ef[i].pb(j);
                                eb[j].pb(i);
                        }

        dp(ef, ff, vf);
        dp(eb, fb, vb);

        auto rem = [](int l, int r) {
                if (l <= r) {
                        ++c[l];
                        --c[r + 1];
                }
        };

        for (int i = 1; i <= rn; ++i) {
                int x = ring[i - 1];
                // 
                if (ff[x].mx >= i) rem(i + 1, ff[x].mx - 1); // ix!!!!!
                if (ff[x].mn <= i) rem(i + 1, rn);
                if (fb[x].mx >= i) rem(1, i - 1);
        }

        partial_sum(c, c + rn + 1, c);

        vi sol;
        for (int i = 1; i <= rn; ++i) if (!c[i])
                sol.pb(ring[i - 1]);

        sort(sol.begin(), sol.end());
	if (sol.size()==0){ puts("-1"); return 0; }
        cout << sol[0] << endl;


        return 0;
}