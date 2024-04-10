#include <set>
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

const int MAX = 2005;
const int INF = 0x3f3f3f3f;

ll dist[MAX][2];
ll rje[MAX];
int e[MAX][MAX];

struct strs {
  ll val;
  P st;
};

bool operator < (const strs &a, const strs &b) {
  if (a.val != b.val) return a.val < b.val;
  return a.st < b.st;
}

set <strs> S;
int n;
P ind = P(-1, -1);

void dijkstra(int poc) {
  REP(i, MAX) REP(j, 2)
    dist[i][j] = (ll) INF * INF;

  S.clear();
  S.insert({0, P(poc, 0)});
  dist[poc][0] = 0;

  for (; !S.empty();) {
    auto tmp = *S.begin(); S.erase(S.begin());
    //    TRACE(poc _ tmp.val _ tmp.st.X _ tmp.st.Y);

    if (tmp.st.Y == 0) {
      rje[tmp.st.X] = min(rje[tmp.st.X], tmp.val);
      REP(i, n) {
	if (i == tmp.st.X) continue;
	if (tmp.st.X == poc && i == (ind.X ^ ind.Y ^ poc)) continue;

	ll nd = tmp.val + e[tmp.st.X][i];
	//	if (!e[tmp.st.X][i]) TRACE(tmp.st.X _ i _ tmp.st.Y);

	if (dist[i][0] > nd) {
	  S.erase({dist[i][0], P(i, 0)});
	  dist[i][0] = nd;
	  S.insert({dist[i][0], P(i, 0)});
	}

	nd = tmp.val;
	if (dist[i][1] > nd) {
	  S.erase({dist[i][1], P(i, 1)});
	  dist[i][1] = nd;
	  S.insert({dist[i][1], P(i, 1)});
	}
      }
    }
    else {
      REP(i, n) {
	if (i == tmp.st.X) continue;
	if (tmp.st.X == poc && i == (ind.X ^ ind.Y ^ poc)) continue;

	ll nd = tmp.val + 2ll * e[i][tmp.st.X];
	if (dist[i][0] > nd) {
	  S.erase({dist[i][0], P(i, 0)});
	  dist[i][0] = nd;
	  S.insert({dist[i][0], P(i, 0)});	  
	}
      }      
    }    
  }
}

int main()
{
  int mn = INF;
  
  scanf("%d", &n);

  REP(i, n) {
    FOR(j, i+1, n) {
      scanf("%d", &e[i][j]);
      e[j][i] = e[i][j];
      if (e[i][j] < mn) {
	mn = e[i][j];
	ind = P(i, j);
      }
    }
  }

  assert(ind.X != -1);

  REP(i, n) {
    REP(j, n) {
      if (i != j) e[i][j] -= mn;
    }
  }

  REP(i, n) rje[i] = (ll) INF * INF;

  dijkstra(ind.X);
  dijkstra(ind.Y);

  REP(i, n) {
    rje[i] += (ll) mn * (n-1);
    printf("%lld\n", rje[i]);    
  }
  
  return 0;
}