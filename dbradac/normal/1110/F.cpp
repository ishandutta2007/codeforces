#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20, LG = 20, TOUR = 1<<20;
const ll INF = 1e18;

int vr=1;
int disc[MAX], fin[MAX];
int lca[LG][MAX], par[MAX];
ll lca_lev[LG][MAX], lca_des[LG][MAX];
ll dubina[MAX];
vector <P> V[MAX];

ll t[2*TOUR];

void stavi(int pos, ll val) {
  pos += TOUR;
  t[pos] = min(t[pos], val);
  
  for (pos/=2; pos; pos /= 2)
    t[pos] = min(t[pos], val);
}

ll vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return INF;
  if (lo >= begin && hi <= end) return t[pos];
  return min(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

void dfs(int node, int pr, ll d) {
  sort(V[node].begin(), V[node].end());
  disc[node] = vr++;
  assert(disc[node] == node);
  dubina[node] = d;
  
  if ((int) V[node].size() == 1)
    stavi(disc[node], dubina[node]);
  
  par[node] = pr;
  lca[0][node] = pr;
  FOR(i, 1, LG)
    lca[i][node] = lca[i-1][lca[i-1][node]];
  
  for (auto it : V[node])
    if (it.X != pr)
      dfs(it.X, node, d + it.Y);

  fin[node] = vr;
}

void gen_skok(int node) {
  if (node) {    
    lca_lev[0][node] = -2ll * dubina[par[node]] + vrati(1, 0, TOUR, disc[par[node]], disc[node]);
    lca_des[0][node] = -2ll * dubina[par[node]] + vrati(1, 0, TOUR, fin[node], fin[par[node]]);

    //    if (node == 9)
      //      TRACE(dubina[par[node]] _ vrati(1, 0, TOUR, disc[par[node]], disc[node]));
    
    FOR(i, 1, LG) {
      lca_lev[i][node] = min(lca_lev[i-1][node], lca_lev[i-1][lca[i-1][node]]);
      lca_des[i][node] = min(lca_des[i-1][node], lca_des[i-1][lca[i-1][node]]);
    }
  }

  for (auto it : V[node])
    if (it.X != par[node])
      gen_skok(it.X);
}

ll get_left(int begin, int node) {
  int granica = disc[node];
  ll ret = INF;
  
  for (int i=LG-1; i>=0; i--) {
    int tmp = lca[i][node];
    //    TRACE(node _ tmp _ disc[tmp]);
    if (disc[tmp] >= begin) {
      ret = min(ret, lca_lev[i][node]);
      //      TRACE(tmp _ ret);
      node = tmp;
    }
  }

  //  TRACE(ret _ node _ -2 * dubina[node] + vrati(1, 0, TOUR, begin, granica));
  //  if (node == 1) return ret;
  node = par[node];
  ret = min(ret, -2 * dubina[node] + vrati(1, 0, TOUR, max(disc[node], begin), min(fin[node], granica)));
  return ret;
}

ll get_right(int end, int node) {
  int granica = fin[node];
  ll ret = INF;

  for (int i=LG-1; i>=0; i--) {
    int tmp = lca[i][node];
    //    TRACE(node _ i _ tmp _ fin[tmp] _ end _ ret);
    if (fin[tmp] <= end) {
      //      TRACE(node _ tmp _ lca_des[i][node]);
      ret = min(ret, lca_des[i][node]);
      node = tmp;
    }
  }

  node = par[node];
  ret = min(ret, -2 * dubina[node] + vrati(1, 0, TOUR, max(disc[node], granica), min(fin[node], end)));
  return ret;
}

int main()
{
  REP(i, 2*TOUR) t[i] = INF;
  REP(i, LG) REP(j, MAX)
    lca_lev[i][j] = lca_des[i][j] = INF;

  int n, qq;
  scanf("%d%d", &n, &qq);

  FOR(i, 2, n+1) {
    int a, b, c;
    scanf("%d%d", &a, &c);
    b = i;
    V[a].push_back(P(b, c));
    V[b].push_back(P(a, c));
  }

  dfs(1, 1, 0);
  gen_skok(1);

  while(qq--) {
    int x, l, r;
    scanf("%d%d%d", &x, &l, &r); r++;

    int poc = x;    
    for (int i=LG-1; i>=0; i--) {
      int tmp = lca[i][x];
      if (disc[tmp] >= r || fin[tmp] <= l)
	x = tmp;
    }

    if (disc[x] >= r || fin[x] <= l) x = par[x];    
    
    ll ret = min(vrati(1, 0, TOUR, max(l, disc[x]), min(r, fin[x])) - dubina[x],
		 min(get_left(l, x) + dubina[x], get_right(r, x) + dubina[x]));

    // ll a = vrati(1, 0, TOUR, max(l, disc[x]), min(r, fin[x])) - dubina[x];
    // ll b = get_left(l, x) + dubina[x];
    // ll c = get_right(r, x) + dubina[x];
    //    TRACE(a _ b _ c);

    //    TRACE(ret _ poc _ x _ dubina[poc] - dubina[x]);
    ret += dubina[poc] - dubina[x];
    
    printf("%lld\n", ret);
  }

  //  TRACE(lca_lev[0][9]);

  return 0;
}