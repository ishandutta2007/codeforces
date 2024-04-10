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

const int MAX = 1<<19, TOUR = 1<<19;
const ll INF = 1e18;

int n, q;
P e[MAX];
int w[MAX];
int disc[MAX], fin[MAX], vr=0;
ll odroota[MAX];
int tko[MAX];
vector <P> V[MAX];
int moj_ind[MAX];

struct node {
  ll mn, prop;
} t[2*TOUR];

void propagiraj(int pos) {
  ll pr = t[pos].prop;
  if (!pr) return;
  FOR(i, 2*pos, 2*pos+2) {
    t[i].mn += pr;
    t[i].prop += pr;
  }    
  t[pos].prop = 0;
}

void stavi(int pos, int lo, int hi, int begin, int end, ll val) {
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    t[pos].prop += val;
    t[pos].mn += val;
    return;
  }

  propagiraj(pos);
  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  t[pos].mn = min(t[2*pos].mn, t[2*pos+1].mn);
}

ll vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return INF;
  if (lo >= begin && hi <= end) return t[pos].mn;
  propagiraj(pos);
  return min(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

void dfs(int node, int pros, ll dosad) {
  tko[vr] = node;
  disc[node] = vr++;

  odroota[node] = dosad;
  for (auto it : V[node])
    if (it.X != pros)
      dfs(it.X, node, dosad + it.Y);

  fin[node] = vr;
}

void init() {
  REP(i, TOUR) {
    ll val = INF;
    if (i < n)
      val = odroota[tko[i]] + w[moj_ind[tko[i]]];

    t[i+TOUR].mn = val;
  }

  for (int i=TOUR-1; i; i--)
    t[i].mn = min(t[2*i].mn, t[2*i+1].mn);
}

ll do_mene(int x) {
  if (!x) return 0;
  return vrati(1, 0, TOUR, disc[x], disc[x]+1) - w[moj_ind[x]];
}

int main()
{
  scanf("%d%d", &n, &q);

  moj_ind[0] = MAX-1;
  REP(i, 2*n-2) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    e[i] = P(a, b);
    w[i] = c;

    if (i < n-1) {
      V[a].push_back({b, c});
      V[b].push_back({a, c});
    }
    else
      moj_ind[a] = i;
  }

  dfs(0, -1, 0);
  init();

  for (; q--; ) {
    int st;
    scanf("%d", &st);

    if (st == 1) {
      int ind, novw;
      scanf("%d%d", &ind, &novw); ind--;
      int prom = novw - w[ind];
      w[ind] = novw;

      if (ind < n-1) {
	int donji = e[ind].Y;
	stavi(1, 0, TOUR, disc[donji], fin[donji], (ll) prom);
      }
      else {
	int ja = e[ind].X;
	//	TRACE(ja _ ind _ n-2+ja);
	assert(moj_ind[ja] == ind);
	stavi(1, 0, TOUR, disc[ja], disc[ja]+1, (ll) prom);
      }
    }
    else {
      int a, b;
      scanf("%d%d", &a, &b); a--; b--;
      //      TRACE(a _ b);
      ll rje = INF;
      
      if (disc[b] >= disc[a] && disc[b] < fin[a]) {
	ll doa = do_mene(a), dob = do_mene(b);
	rje = dob - doa;
      }
      else {
	ll moj_put = vrati(1, 0, TOUR, disc[a], fin[a]) - do_mene(a);
	ll dob = do_mene(b);
	
	//	TRACE(moj_put _ dob);

	rje = moj_put + dob;
      }

      printf("%lld\n", rje);
    }
  }

  return 0;
}