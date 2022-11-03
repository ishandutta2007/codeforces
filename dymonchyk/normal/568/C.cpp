#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <string>

using namespace std;

struct SAT2_Solver {
  SAT2_Solver(int _n = 0) : n(_n) {
    init(_n);
  };
  void init(int _n) {
    n = _n;
    g.clear();
    g.resize(2 * n + 1);
  }
  void addOrClause(int x, int y, int c) {
    // cout << x << "  " << y << endl;
    if (c) {
      addEdge(-x, y);
      addEdge(-y, x);
    } else {
      addEdge(x, -x);
      addEdge(y, -y);
    }
  }
  void addAndClause(int x, int y, int c) {
    if (c) {
      addOrClause(x, x, 1);
      addOrClause(y, y, 1);
    } else {
      addOrClause(-x, -y, 1);
    }
  }
  void addXorClause(int x, int y, int c) {
    if (c) {
      addOrClause(x, y, 1);
      addOrClause(-x, -y, 1);
    } else {
      addOrClause(-x, y, 1);
      addOrClause(x, -y, 1);
    }
  }
  void addImplClause(int x, int y, int c) {
    // cout << x << "  " << y << endl;
    if (c) {
      addOrClause(-x, y, 1);
    } else {
      // TODO: test
      addOrClause(-x, y, 0);
    }
  }
  vector<int> solve() {
    vector<int> ret(n + 1, 0);
    
    used.assign(2 * n + 1, 0);
    comp.assign(2 * n + 1, -1);
    order.clear();

    for (int i = 1; i <= 2 * n; ++i) {
      if (!used[i]) {
        dfs(i);
      }
    }

    int compCnt = 0;
    for (int i = order.size() - 1; i >= 0; --i) {
      if (comp[order[i]] == -1) {
        ++compCnt;
        dfs2(order[i], compCnt);
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (comp[i] == comp[i + n]) {
        ret.clear();
        return ret;
      }
      if (comp[i] < comp[i + n])
        ret[i] = 0;
      else
        ret[i] = 1;
      // cout << ret[i] << endl;
    }

    return ret;
  }
private:
  inline void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
      int u = g[v][i];
      dfs(u);
    }
    order.push_back(v);
  }
  inline void dfs2(int v, int color) {
    if (comp[v] != -1) return;
    comp[v] = color;
    int nv = negVertex(v);
    for (int i = 0; i < g[nv].size(); ++i) {
      int u = negVertex(g[nv][i]);
      dfs2(u, color);
    }
  }
  vector<int> order, comp, used;

private:
  int negVertex(int x) {
    if (x <= n) return x + n;
    else return x - n;
  }
  void addEdge(int x, int y) {
    if (x < 0) x = n - x;
    if (y < 0) y = n - y;
    g[x].push_back(y);
    // cout << x << "  " << y << endl;
  }
  int n;
  vector<vector<int> > g;
};

const int N = 200 * 200 * 5;
int p1[N], p2[N];
char c1[N], c2[N];

int n, m;
char what[27] = {0};

bool check(const string &s, int cnt) {
  SAT2_Solver solver(n);
  for (int i = 0; i < m; ++i) {
    // if (p1[i] < cnt) {
      int t1 = c1[i] == 'V' ? 1 : -1, t2 = c2[i] == 'V' ? 1 : -1;
      solver.addImplClause((p1[i] + 1) * t1, (p2[i] + 1) * t2, 1);
    // }
  }
  for (int i = 0; i < cnt; ++i) {
    int t = what[s[i] - 'a'] == 'V' ? 1 : -1;
    solver.addOrClause((i + 1) * t, (i + 1) * t, 1);
  }
  return solver.solve().size() > 0;
}

// vector < vector<int> > g, gt;
// vector<bool> used;
// vector<int> order, comp;

// void dfs1 (int v) {
//   used[v] = true;
//   for (size_t i=0; i<g[v].size(); ++i) {
//     int to = g[v][i];
//     if (!used[to])
//       dfs1 (to);
//   }
//   order.push_back (v);
// }

// void dfs2 (int v, int cl) {
//   comp[v] = cl;
//   for (size_t i=0; i<gt[v].size(); ++i) {
//     int to = gt[v][i];
//     if (comp[to] == -1)
//       dfs2 (to, cl);
//   }
// }


// const int N = 200 * 200 * 5;
// int p1[N], p2[N];
// char c1[N], c2[N];

// int n, m;
// char what[27] = {0};

// void add(int x, int y) {
//   g[x].push_back(y);
//   gt[y].push_back(x);
//   // cout << x << "  " << y << endl;
// }

// bool check(const string &s, int cnt) {
//   g.clear(); g.resize(2 * n);
//   gt.clear(); gt.resize(2 * n);
//   // cout << s << endl;
//   for (int i = 0; i < m; ++i) {
//     if (p1[i] >= cnt) {
//       int t1 = c1[i] == 'V' ? 1 : 0, t2 = c2[i] == 'V' ? 1 : 0;
//       add(2 * (p1[i]) + t1, 2 * (p2[i]) + t2);
//       add(2 * (p2[i]) + (t2 ^ 1), 2 * (p1[i]) + (t1 ^ 1));
//     } else {
//       if (what[s[p1[i]] - 'a'] != c1[i]) continue;
//       int t1 = c1[i] == 'V' ? 1 : 0, t2 = c2[i] == 'V' ? 1 : 0;
//       add(2 * (p1[i]) + t1, 2 * (p2[i]) + t2);
//       add(2 * (p2[i]) + (t2 ^ 1), 2 * (p1[i]) + (t1 ^ 1));
//     }
//   }
//   for (int i = 0; i < cnt; ++i) {
//     int t = what[s[i] - 'a'] == 'V' ? 1 : 0;
//     // solver.addOrClause((i + 1) * t, (i + 1) * t, 1);
//     add(2 * (i) + (t ^ 1), 2 * (i) + t);
//     // add(2 * (i) + t, 2 * (i) + (t ^ 1));
//   }
//   // cout << endl;


//   order.clear();
//   used.assign (2 * n, false);
//   for (int i=0; i<2 * n; ++i)
//     if (!used[i])
//       dfs1 (i);

//   // cout << order.size() << endl;

//   comp.assign (2 * n, -1);
//   for (int i=0, j=0; i<2 * n; ++i) {
//     int v = order[2 * n-i-1];
//     if (comp[v] == -1)
//       dfs2 (v, j++);
//   }
//   // for (int i = 0; i < 2 * n; ++i)
//   //   cout << comp[i] << "  ";
//   // cout << endl;

//   for (int i=0; i<2 * n; ++i)
//     if (comp[i] == comp[i^1]) {
//       return false;
//     }
//   // cout << "true" << endl;
//   return true;
// }

int main() {
  gets(what);
  char last = 'a' + strlen(what) - 1;
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %c %d %c\n", &p1[i], &c1[i], &p2[i], &c2[i]);
    --p1[i], --p2[i];
  }
  char str[202] = {0};
  gets(str);

  bool hasV = false, hasC = false;
  for (int i = strlen(what) - 1; i >= 0; --i) {
    if (what[i] == 'V') hasV = true;
    else hasC = true;
  }

  if (!hasV || !hasC) {
    if (check(str, n))
      cout << str << endl;
    else
      cout << -1 << endl;
    return 0;
  }

  if (check(str, n)) {
    cout << str << endl;
    return 0;
  }
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    string tmp = str;
    bool was[256] = {0}, ok = false;
    while (tmp[m] < last) {
      ++tmp[m];
      if (was[what[tmp[m] - 'a']]) continue;
      was[what[tmp[m] - 'a']] = true;
      if (check(tmp, m + 1)) {
        ok = true;
        break;
      }
    }
    if (ok) l = m;
    else r = m;
  }

  for (int i = l; i >= l; --i) {
    string tmp = str;
    bool was[256] = {0};
    while (tmp[i] < last) {
      ++tmp[i];
      if (was[what[tmp[i] - 'a']]) continue;
      was[what[tmp[i] - 'a']] = true;
      if (check(tmp, i + 1)) {
        for (int j = i + 1; j < n; ++j) {
          memset(was, 0, sizeof(was));
          for (tmp[j] = 'a'; tmp[j] <= last; ++tmp[j]) {
            if (was[what[tmp[j] - 'a']]) continue;
            was[what[tmp[j] - 'a']] = true;
            // cout << tmp << "  " << last << endl;
            if (check(tmp, j + 1))
              break;
          }
        }
        cout << tmp << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}