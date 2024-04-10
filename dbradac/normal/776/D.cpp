#include <stack>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

namespace tarjan2sat {
  const int MAXN = 800100;

  vector<int> E[MAXN];

  bool ans[MAXN];
  bool stk[MAXN];
  int val[MAXN];
  int disc[MAXN];
  int n, t;
  bool consistent;

  stack<int> S;
  
  int tarjan(int x) {
    int lw = disc[x] = ++t;
    
    stk[x] = true;
    S.push(x);

    for (int y: E[x])
      if (disc[y] == 0) lw = min(lw, tarjan(y)); else
        if (stk[y]) lw = min(lw, disc[y]);
    
    if (lw == disc[x]) {
      vector<int> comp;
      bool ok = true;
      while (!S.empty()) {
        int y = S.top(); S.pop();
        comp.push_back(y);
        ok &= val[y/2] == -1;
        stk[y] = false;
        if (y == x) break;
      }

      if (ok) {
        for (int y: comp)
          val[y/2] = y&1;
        for (int y: comp)
          if (val[y/2] != (y&1)) consistent = false;
      }
    }
    return lw;
  }

  bool solve() {
    consistent = true;
    REP(i, 2*n)
      if (!disc[i]) tarjan(i);
    return consistent;
  }
  
  void add_impl(int i, bool vi, int j, bool vj) {
    E[2*i + vi].push_back(2*j + vj);
    E[2*j + !vj].push_back(2*i + !vi);
  }
  
  void init(int _n) {
    n = _n, t = 0;
    REP(i, 2*n) {
      disc[i] = 0;
      stk[i] = false;
      E[i].clear();
    }
    REP(i, n) val[i] = -1;
  }
};

const int MAX = 1<<18;

vector <int> sw[MAX];
int st[MAX];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  REP(i, n) scanf("%d", &st[i]);
  
  REP(i, m) {
    int k;
    scanf("%d", &k);
    for (; k--; ) {
      int x;
      scanf("%d", &x); x--;
      sw[x].push_back(i);
    }
  }
  
  tarjan2sat::init(m);

  REP(i, n) {
    assert((int) sw[i].size() == 2);
    tarjan2sat::add_impl(sw[i][0], 0, sw[i][1], 1 ^ st[i]);
    tarjan2sat::add_impl(sw[i][0], 1, sw[i][1], st[i]);
  }
  
  printf("%s\n", tarjan2sat::solve() ? "YES" : "NO");

  return 0;
}