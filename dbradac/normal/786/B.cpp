#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
// #define TRACE(x) cerr << #x << " = " << x << endl
// #define _ << " " <<
#define X first
#define Y second

const int MAX = 1<<17, TOUR = 1<<17;
const ll INF = 1e18;

P t_dol[2*TOUR];
ll propdol[2*TOUR];
vector <P> t_gor[2*TOUR];
ll mn[2*TOUR];
P mn_gor[2*TOUR];
int n, m, poc;

vector <pair<P, ll> > V_dol[2*MAX];
vector <pair<P, ll> > V_gor[2*MAX];

//s kraja t_gor

ll dist[MAX];
int bio[MAX];

void init_dol()
{
  FOR(i, TOUR, TOUR+n) t_dol[i] = {INF, i-TOUR};
  FOR(i, TOUR+n, 2*TOUR) t_dol[i] = {INF, INF};
  for (int i=TOUR-1; i; i--) t_dol[i] = min(t_dol[2*i], t_dol[2*i+1]);
}

void propagiraj(int pos)
{
  if (pos >= TOUR) return;
  FOR(i, 2*pos, 2*pos+2) {
    if (t_dol[i].Y < INF/2)
      t_dol[i] = min(t_dol[i], {propdol[pos], t_dol[i].Y});
    propdol[i] = min(propdol[i], propdol[pos]);
  }
}

void ubaci_dol(int pos, int lo, int hi, int begin, int end, ll val)
{
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    //    TRACE(pos _ val _ t_dol[pos].Y);
    if (t_dol[pos].Y < INF/2) {
      t_dol[pos] = min(t_dol[pos], {val, t_dol[pos].Y});
      propdol[pos] = min(propdol[pos], val);
    }
    return;
  }

  propagiraj(pos);
  ubaci_dol(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  ubaci_dol(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  t_dol[pos] = min(t_dol[2*pos], t_dol[2*pos+1]);
}

void ubij_dol(int pos, int lo, int hi, int begin)
{
  if (lo >= begin + 1 || hi <= begin) return;
  if (lo >= begin && hi <= begin + 1) {
    //    TRACE(pos _ t_dol[pos].X _ t_dol[pos].Y);
      propagiraj(pos);
    t_dol[pos] = {INF, INF};
    return;
  }

  propagiraj(pos);
  ubij_dol(2*pos+0, lo, (lo+hi)/2, begin);
  ubij_dol(2*pos+1, (lo+hi)/2, hi, begin);
  t_dol[pos] = min(t_dol[2*pos], t_dol[2*pos+1]);
  //  TRACE(pos _ t_dol[pos].X _ t_dol[pos].Y);
}

//s kraja t_gor

void merge(int pos)
{
  if (pos < TOUR) {
    mn[pos] = min(mn[2*pos], mn[2*pos+1]);
    mn_gor[pos] = min(mn_gor[2*pos], mn_gor[2*pos+1]);
  }
  else
    mn_gor[pos] = {INF, INF};

  //TRACE(pos);
  //  TRACE(pos _ mn_gor[pos].X _ mn_gor[pos].Y);
  for (; !t_gor[pos].empty(); ) {
    P tmp = t_gor[pos].back();
    if (bio[tmp.Y])
      t_gor[pos].pop_back();
    else {
      //      if (tmp.Y == 3) TRACE(pos _ mn[pos] _ tmp.X _ tmp.Y);
      mn_gor[pos] = min(mn_gor[pos], {mn[pos] + tmp.X, tmp.Y});
      break;
    }
  }
}

void ubaci_gor(int pos, int lo, int hi, int begin, int end, P val)
{
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    //    if (val.Y == 3) TRACE(lo _ hi _ val.X);
    t_gor[pos].push_back(val);
    return;
  }

  ubaci_gor(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  ubaci_gor(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  merge(pos);
}

void ubij_gor(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    merge(pos);
    return;
  }
  ubij_gor(2*pos+0, lo, (lo+hi)/2, begin, end);
  ubij_gor(2*pos+1, (lo+hi)/2, hi, begin, end);
  merge(pos);
}

void init_gor()
{
  REP(i, 2*TOUR) mn_gor[i] = {INF, INF};
  
  REP(i, n) {
    for (auto it : V_gor[i])
      ubaci_gor(1, 0, TOUR, (int) it.X.X, (int) it.X.Y, P(it.Y, (ll) i));
  }

  REP(i, 2*TOUR) sort(t_gor[i].begin(), t_gor[i].end(), greater<P>());
}

void ubaci_gor_val(int pos, int lo, int hi, int begin, ll val)
{
  if (lo >= begin + 1 || hi <= begin) return;
  if (lo >= begin && hi <= begin + 1) {
    //    TRACE(pos _ lo _ hi _ val);
    mn[pos] = min(mn[pos], val);
    merge(pos);
    return;
  }

  ubaci_gor_val(2*pos+0, lo, (lo+hi)/2, begin, val);
  ubaci_gor_val(2*pos+1, (lo+hi)/2, hi, begin, val);
  merge(pos);
}

//s kraja t_gor

P daj_min()
{
  //  TRACE(t_dol[1].X _ t_dol[1].Y);
  //  TRACE(mn_gor[1].X _ mn_gor[1].Y);
  P ret = min(t_dol[1], mn_gor[1]);
  return ret;
}

void go()
{
  REP(i, MAX) dist[i] = INF;
  ubaci_dol(1, 0, TOUR, poc, poc+1, 0ll);

  for (;;) {
    P tmp = daj_min();
    //    TRACE(tmp.X _ tmp.Y);
    if (tmp.X > INF/2) break;
    assert(!bio[tmp.Y]);
    bio[tmp.Y] = 1;
    dist[tmp.Y] = tmp.X;

    for (auto it : V_dol[tmp.Y])
      ubaci_dol(1, 0, TOUR, (int) it.X.X, (int) it.X.Y, tmp.X + it.Y);    
    //    TRACE("ubij" _ tmp.Y);
    ubij_dol(1, 0, TOUR, (int) tmp.Y);
    for (auto it : V_gor[tmp.Y]) {
      ubij_gor(1, 0, TOUR, (int) it.X.X, (int) it.X.Y);
      //TRACE(it.X.X _ it.X.Y);
    }
    
    ubaci_gor_val(1, 0, TOUR, (int) tmp.Y, tmp.X);
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &poc); poc--;

  REP(i, m) {
    int st;
    scanf("%d", &st);

    if (st == 1) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c); a--; b--;
      V_dol[a].push_back({{b, b+1}, c});
    }
    else {
      int v, l, r, c;
      scanf("%d%d%d%d", &v, &l, &r, &c); v--; l--;
      //      TRACE(v);
      if (st == 2) V_dol[v].push_back({{l, r}, c});
      else V_gor[v].push_back({{l, r}, c});
    }    
  }

  REP(i, 2*TOUR) propdol[i] = INF;
  REP(i, 2*TOUR) mn[i] = INF;
  
  init_dol();
  init_gor();
  go();

  REP(i, n) printf("%lld ", dist[i] < INF ? dist[i] : -1);
  printf("\n");
 
  return 0;
}