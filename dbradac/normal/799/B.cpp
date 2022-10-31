#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define _ << " _ " <<

#define TRACE(x) cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

// #define TRACE(x)
// #define debug(...)

using namespace std;

typedef long long llint;

const int MAX = 1<<20;
const int INF = 1e9 + 5;

int n;
vector <int> V[10];
int p[MAX], a[MAX], b[MAX];

int main(void) {
  scanf("%d", &n);

  REP(i, n) scanf("%d", &p[i]);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n) scanf("%d", &b[i]);

  REP(i, n) {
    a[i]--; b[i]--;
    V[(1<<a[i]) | (1<<b[i])].push_back(p[i]);
  }

  REP(i, 10) sort(V[i].begin(), V[i].end(), greater<int>());

  int m;
  scanf("%d", &m);

  REP(i, m) {
    int mn = INF, ind = -1;
    int c;
    scanf("%d", &c); c--;

    REP(j, 10) {
      if ((j & (1<<c)) && !V[j].empty()) {
	if (V[j].back() < mn) {
	  mn = V[j].back();
	  ind = j;
	}
      }
    }

    if (ind == -1) printf("-1 ");
    else {
      printf("%d ", mn);
      V[ind].pop_back();
    }    
  }
  printf("\n");
  
  return 0;
}