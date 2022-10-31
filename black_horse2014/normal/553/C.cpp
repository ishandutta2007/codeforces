#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define MOD 1000000007
#define X first
#define Y second
#define MX 100005

struct Edge {
    int st, en;
    Edge(int st = 0, int en = 0) : st(st), en(en) {}
};

int bit[MX];
vector<Edge> edge[2];
vi con[MX];

int n, m, root[MX], chk[MX], color[MX];

int find_root(int x) {
    return root[x] == -1 ? x : root[x] = find_root(root[x]);
}

vi v, _v;
bool flag;

void DFS(int id, int par) {
    int i;
    chk[id] = 1;
    _v.pb(id);
    for (i = 0; i < con[id].size(); i++) {
        int j = con[id][i];
        if (j == par) continue;
        if (!chk[j]) {
            color[j] = 1 ^ color[id];
            DFS(j, id);
        } else {
            if (color[j] == color[id]) flag = true;
        }
    }
}

int main() {

    int i;

    for (bit[0] = i = 1; i < MX; i++) bit[i] = bit[i - 1] * 2 % MOD;

    memset(root, -1, sizeof root);
    memset(color, -1, sizeof color);

    scanf("%d%d", &n, &m);

    int a, b, c;

    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        if (c == 1) edge[0].pb(Edge(a, b));
        else edge[1].pb(Edge(a, b));
    }

    for (i = 0; i < edge[0].size(); i++) {
        a = edge[0][i].st, b = edge[0][i].en;
        int _a = find_root(a), _b = find_root(b);
        if (_a != _b) root[_b] = _a;
    }

    for (i = 0; i < edge[1].size(); i++) {
        a = edge[1][i].st, b = edge[1][i].en;
        int _a = find_root(a), _b = find_root(b);
        if (_a == _b) {
            puts("0"); return 0;
        }
        con[_a].pb(_b), con[_b].pb(_a);
    }

    for (i = 1; i <= n; i++) {
        int id = find_root(i);
        if (id == i) v.pb(id);
    }

    b = c = 0;

    for (i = 0; i < v.size(); i++) if (!chk[v[i]]){
        _v.clear();
        color[v[i]] = 0;
        flag = 0;
        DFS(v[i], -1);
        if (flag) {
            puts("0"); return 0;
        }
        if (_v.size() == 1) c++;
        else b ++;
    }

    if (c > 0) {
        int res = 1LL * bit[c - 1] * bit[b] % MOD;
        cout << res << endl;
    }
    else {
        cout << bit[b - 1] << endl;
    }
    return 0;
}