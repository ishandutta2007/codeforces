#include <cstdio>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
using namespace std;

// two loops kill each other.
struct edge {
  int a, b, d;
};

int n, m;
set<int> g[100020];
int deg[100020];
int loop[100020];
vector<edge> ed;

int get_to(int v, int e) {
  if (ed[e].a == ed[e].b || ed[e].d) {
    return -1;
  }
  if (ed[e].a == v) {
    return ed[e].b;
  } else {
    return ed[e].a;
  }
}

void euler() {
  // int n;
  // vector < vector<int> > g (n, vector<int> (n));
  // ...      ...

  int first = 1;

  bool bad = false;

  stack<int> st;
  st.push (first);
  vector<int> res;
  while (!st.empty())
  {
    int v = st.top();
    int i = -1;
    int e;
    while (g[v].size()) {
      auto it = g[v].begin();
      e = *it;
      i = get_to(v, *it);
      if (i == -1) {
        g[v].erase(it);
      } else {
        break;
      }
    }
    if (i == -1)
    {
      res.push_back (v);
      st.pop();
    }
    else
    {
      // set direction - later?
      ed[e].d = 1;
      st.push (i);
    }
  }

  printf("%d\n", (int) ed.size());
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < (int) loop[i]; ++j) {
      printf("%d %d\n", i, i);
    }
  }
  int j = 0;
  for (size_t i = 0; i + 1<res.size(); ++i) {
    if (loop[res[i]] & 1) {
      ++j;
      loop[res[i]]--;
    }
    if ((i + j) & 1) {
      printf("%d %d\n", res[i], res[i + 1]);
    } else {
      printf("%d %d\n", res[i + 1], res[i]);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  ed.resize(m);
  memset(loop, 0, sizeof(loop));
  memset(deg, 0, sizeof(deg));

  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &ed[i].a, &ed[i].b);
    ed[i].d = 0;

    g[ed[i].a].insert(i);
    if (ed[i].b != ed[i].a) {
      g[ed[i].b].insert(i);
    }

    if (ed[i].a == ed[i].b) {
      ++ loop[ ed[i].a ];
    } else {
      ++ deg[ ed[i].a ];
      ++ deg[ ed[i].b ];
    }
  }

  int la = -1;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] & 1) {
      if (la == -1) {
        la = i;
      } else {
        g[la].insert(ed.size());
        g[i].insert(ed.size());
        ed.push_back( {la, i, 0} );
        la = -1;
      }
    }
  }

  // degrees fixed. +1?
  if (((int) ed.size()) % 2 == 1) {
    ++loop[1];
    g[1].insert(ed.size());
    ed.push_back({1, 1, 0});
  }

  // do euler.
  euler();
  return 0;
}