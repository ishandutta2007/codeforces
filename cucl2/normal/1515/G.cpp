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

ll inline gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int n, m;
vector<pair<int, int> > nei[200005];
int dfn[200005], low[200005], tmc;
vector<int> stk;
bool lgl[200005];
ll hg[200005], de[200005];
int bel[200005], cs;
ll gs[200005];

void tarjan(int now, ll dep) {
    stk.pub(now); lgl[now] = 1;
    dfn[now] = low[now] = ++tmc;
    de[now] = dep;
    parse(it, nei[now]) {
        int to = it.first;
        if (!dfn[to]) {
            tarjan(to, dep + it.second);
            low[now] = min(low[now], low[to]);
        } else if (lgl[to]) {
            hg[now] = gcd(hg[now], de[now] - de[to] + it.second);
            low[now] = min(low[now], dfn[to]);
        }
    }
    if (dfn[now] == low[now]) {
        bel[now] = ++cs;
        lgl[now] = 0;
        while (stk.back() != now) {
            int to = stk.back();
            bel[to] = cs;
            lgl[to] = 0;
            stk.pob();
        }
        stk.pob();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    cont(i, m) {
        int a, b, l; scanf("%d%d%d", &a, &b, &l);
        nei[a].emb(b, l);
    }
    cont(i, n) if (!dfn[i]) tarjan(i, 0);
    cont(i, n) gs[bel[i]] = gcd(gs[bel[i]], hg[i]);
    int q; scanf("%d", &q);
    while (q--) {
        int v, s, t; scanf("%d%d%d", &v, &s, &t);
        int rem = (t - s) % t;
        ll gg = gcd(gs[bel[v]], t);
        if (!rem || (gg && rem % gg == 0)) puts("YES");
        else puts("NO");
    }
    return 0;
}