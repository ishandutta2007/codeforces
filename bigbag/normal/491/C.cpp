// a b c d e f g h i j k l m n o p q r s t u v w x y z
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 1 2 3 4 5 6 7 8 9 0
// ! @ # $ % ^ & * ( ) - _ = + ; : ' " \ / ? , . < > { } [ ] |
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333, inf = 1111111111;

int n, k, q[333][333], f[333], m;
char ans[333];
string a, b;
vector<pair<int, pair<int, int> > > v;

struct edge {
    int x, y, f, c, u, id;
    edge(int x, int y, int u, int c, int id) : x(x), y(y), u(u), c(c), id(id), f(0) {
    }
};

vector<edge> g[max_n];

void add_edge(int x, int y, int u, int c) {
    edge e1(x, y, u, c, g[y].size()), e2(y, x, 0, -c, g[x].size());
    g[x].push_back(e1);
    g[y].push_back(e2);
}

int update(int s, int t) {
    int d[max_n], used[max_n], p[max_n], id[max_n];
    deque<int> q;
    for (int i = 0; i <= t; ++i) {
        used[i] = 0;
        d[i] = inf;
    }
    d[s] = 0;
    used[s] = 1;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        used[v] = 2;
        q.pop_front();
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i].u - g[v][i].f > 0 && d[v] + g[v][i].c < d[g[v][i].y]) {
                d[g[v][i].y] = d[v] + g[v][i].c;
                if (used[g[v][i].y] == 0) {
                    q.push_back(g[v][i].y);
                    used[g[v][i].y] = 1;
                } else if (used[g[v][i].y] == 2) {
                    q.push_front(g[v][i].y);
                    used[g[v][i].y] = 1;
                }
                p[g[v][i].y] = v;
                id[g[v][i].y] = i;
            }
        }
    }
    if (d[t] == inf) {
        return inf;
    }
    int total = inf;
    int v = t;
    while (v != s) {
        total = min(total, g[p[v]][id[v]].u - g[p[v]][id[v]].f);
        v = p[v];
    }
    v = t;
    int res = 0;
    while (v != s) {
        g[p[v]][id[v]].f += total;
        int x = g[p[v]][id[v]].y;
        int ind = g[p[v]][id[v]].id;
        g[x][ind].f -= total;
        res += total * g[p[v]][id[v]].c;
        v = p[v];
    }
    return res;
}

void min_cost_flow() {
    int s = n + m, t = n + m + 1;
    for (int i = 'A'; i <= 'z'; ++i) {
        add_edge(s, i - 'A', 1, 0);
    }
    for (int i = 'A'; i <= 'z'; ++i) {
        add_edge(n + i - 'A', t, 1, 0);
    }
    for (int i = 'A'; i <= 'z'; ++i) {
        for (int j = 'A'; j <= 'z'; ++j) {
            if (q[i][j]) add_edge(i - 'A', n + j - 'A', 1, -q[i][j]);
        }
    }
    int res = 0;
    while (true) {
        int x = update(s, t);
        if (x == inf) {
            break;
        }
        res += x;
    }
    cout << -res << endl;
    //return;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j].f > 0) {
                ans[i + 'A'] = g[i][j].y - n + 'A';
            }
        }
    }
    set<char> q;
    for (int i = 0; i < k; ++i) {
        int num = i + 'a';
        if (i >= 26) {
            num = i - 26 + 'A';
        }
        q.insert(num);
    }
    for (int i = 0; i < k; ++i) {
        int num = i + 'a';
        if (i >= 26) {
            num = i - 26 + 'A';
        }
        if (ans[num]) {
            q.erase(ans[num]);
        }
    }
    for (int i = 0; i < k; ++i) {
        int num = i + 'a';
        if (i >= 26) {
            num = i - 26 + 'A';
        }
        if (ans[num]) {
            cout << ans[num];
        } else {
            cout << (*q.begin());
            q.erase(q.begin());
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> a >> b;
    for (int i = 0; i < n; ++i) {
        ++q[a[i]][b[i]];
        //s.insert(a[i]);
    }
    //if (s.size() != k) while(1);
    n = 'z' - 'A' + 1;
    m = 2 * n;
    min_cost_flow();
    return 0;
}