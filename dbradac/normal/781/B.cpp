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

const int MAXN = 2005;

vector<int> E[MAXN];

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

string s[1005][2];
char a[50], b[50];

int main()
{
  int n;
  scanf("%d", &n);
  
  init(n);
  
  REP(i, n) {
    scanf(" %s %s", a, b);
    REP(j, 3)
      s[i][0].push_back(a[j]);
    REP(j, 2)
      s[i][1].push_back(a[j]);
    s[i][1].push_back(b[0]);
  }

  REP(i, n) {
    FOR(j, i+1, n) {
      REP(sti, 2)
	REP(stj, 2)
	if (s[i][sti] == s[j][stj]) {
	  add_impl(i, sti, j, 1^stj);
	  add_impl(j, stj, i, 1^sti);
	}
      
      if (s[i][0] == s[j][0]) {
	add_impl(i, 1, j, 1);
	add_impl(j, 1, i, 1);
      }
    }
  }

  solve();
  if (!consistent)
    printf("NO\n");
  else {
    printf("YES\n");
    REP(i, n)
      printf("%s\n", s[i][val[i]].c_str());
  }
    
  return 0;
}