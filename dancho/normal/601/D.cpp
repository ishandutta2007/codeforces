#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int ne[26];
};

int ln;
node tr[1 << 20];

int n;
int c[1 << 20];
char l[1 << 20];
bool us[1 << 20];
int fin[1 << 20];

int par[1 << 20];
vector<int> g[1 << 20];

long long mxsol, cnt;

void dfs(int v, int tv) {
    if (us[v]) {
        return;
    }
    us[v] = 1;
    fin[v] = tv;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (!us[u]) {
            par[u] = v;
            if (tr[tv].ne[l[u] - 'a'] == -1) {
                tr[tv].ne[l[u] - 'a'] = ln++;
            }
            dfs(u, tr[tv].ne[l[u] - 'a']);
        }
    }
}

void solve(int v, set<int> &m) {
    m.clear();
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (par[u] == v) {
            set<int> o;
            solve(u, o);
            if (m.size() < o.size()) {
                swap(m, o);
            }
            for (set<int>::iterator it = o.begin(); it != o.end(); ++it) {
                m.insert(*it);
            }
        }
    }
    m.insert(fin[v]);
    long long co = (long long) c[v] + m.size();
    if (co > mxsol) {
        mxsol = co;
        cnt = 1;
    } else if (co == mxsol) {
        ++cnt;
    }
}

int main() {
    memset(tr, -1, sizeof(tr));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    scanf("%s", l);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(us, 0, sizeof(us));
    ln = 1;
    par[0] = -1;
    dfs(0, 0);

    mxsol = -1;
    cnt = 0;
    set<int> m;
    solve(0, m);
    printf("%lld\n%lld\n", mxsol, cnt);

    return 0;
}