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

const int maxn = 100005;
int n, m;
vector<int> nei[maxn], egs[maxn];
int dfn[maxn], low[maxn], tmc, bls;
bool inq[maxn];
vector<int> stk;
int bel[maxn], deg[maxn];
vector<int> ctn[maxn];

void tarjan(int now) {
    dfn[now] = low[now] = ++tmc;
    stk.pub(now); inq[now] = 1;
    parse(to, nei[now]) {
        if (!dfn[to]) {
            tarjan(to);
            low[now] = min(low[now], low[to]);
        } else if (inq[to]) {
            low[now] = min(low[now], dfn[to]);
        }
    }
    if (dfn[now] == low[now]) {
        bel[now] = ++bls; inq[now] = 0;
        ctn[bls].pub(now);
        while (stk.back() != now) {
            bel[stk.back()] = bls;
            inq[stk.back()] = 0;
            ctn[bls].pub(stk.back());
            stk.pob();
        }
        stk.pob();
    }
}

bool inline query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int res; cin >> res;
    return res;
}

void inline answer(int a) {
    cout << "! " << a << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    cont(i, m) {
        int a, b; cin >> a >> b;
        nei[a].pub(b);
    }
    cont(i, n) if (!dfn[i]) tarjan(i);
    cont(i, n) parse(j, nei[i]) if (bel[i] != bel[j]) {
        egs[bel[i]].pub(bel[j]);
        ++deg[bel[j]];
    }
    vector<int> ls;
    cont(i, bls) if (!deg[i]) {
        ls.pub(ctn[i].back());
        ctn[i].pob();
    }
    while (SZ(ls) > 1) {
        int u = ls.back(); ls.pob();
        int v = ls.back(); ls.pob();
        int del, rem;
        if (query(u, v)) del = v, rem = u;
        else rem = v, del = u;
        ls.pub(rem);
        int gr = bel[del];
        if (SZ(ctn[gr])) {
            ls.pub(ctn[gr].back());
            ctn[gr].pob();
        } else {
            parse(j, egs[gr]) {
                --deg[j];
                if (!deg[j]) {
                    ls.pub(ctn[j].back());
                    ctn[j].pob();
                }
            }
        }
    }
    assert(SZ(ls));
    answer(ls[0]);
    return 0;
}