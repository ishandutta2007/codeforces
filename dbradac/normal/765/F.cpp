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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17,TOUR = 1<<17, MAXQ = 300100, INF = 0x3f3f3f3f;

int n, brq;
int p[MAX];
P q[MAXQ];
vector <int> Rq[MAX];

int pozicije[MAX];
vector <int> Sor;
int rje[MAXQ];

int t_broj[2*TOUR], t_rje[2*TOUR];
int query(int t[2*TOUR], int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin) return -INF;
  if (lo >= begin && hi <= end) return t[pos];
  return max(query(t, 2*pos+0, lo, (lo+hi)/2, begin, end),
	     query(t, 2*pos+1, (lo+hi)/2, hi, begin, end));
}

void insert(int t[2*TOUR], int pos, int val)
{
  pos += TOUR;
  for (; pos; pos /= 2)
    t[pos] = max(t[pos], val);
}

void load()
{
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &p[i]);
    Sor.push_back(p[i]);
  }
  sort(Sor.begin(), Sor.end());
  Sor.resize(unique(Sor.begin(), Sor.end()) - Sor.begin());

  REP(i, n) pozicije[i] = lower_bound(Sor.begin(), Sor.end(), p[i]) - Sor.begin();

  scanf("%d", &brq);
  REP(i, brq) {
    scanf("%d%d", &q[i].X, &q[i].Y);
    q[i].X--; q[i].Y--;
  }
}

int main()
{
  load();
  memset(rje, INF, sizeof rje);
  
  REP(i, brq) Rq[q[i].Y].push_back(i);
  
  REP(i, 2*TOUR) t_broj[i] = t_rje[i] = -INF;

  REP(i, n) {
    int begin = 0, end = pozicije[i];
    REP(j, 32) {
      int poz = query(t_broj, 1, 0, TOUR, begin, end+1);
      if (poz < 0) break;
      assert(p[i] - p[poz] >= 0);
      insert(t_rje, poz, -(p[i] - p[poz]));
      begin = upper_bound(Sor.begin(), Sor.end(), (p[i] + p[poz]) / 2) - Sor.begin();
      for (; begin < (int) Sor.size() && Sor[begin] * 2 <= p[i] + p[poz]; begin++);
    }

    begin = pozicije[i], end = TOUR;
    REP(j, 32) {
      int poz = query(t_broj, 1, 0, TOUR, begin, end+1);
      if (poz < 0) break;
      assert(p[poz] - p[i] >= 0);
      insert(t_rje, poz, -(p[poz] - p[i]));
      end = lower_bound(Sor.begin(), Sor.end(), (p[i] + p[poz]) / 2) - Sor.begin();
      for (; end>=0 && (end == (int) Sor.size() || Sor[end] * 2 >= p[i] + p[poz]); end--);
    }

    insert(t_broj, pozicije[i], i);

    for (auto itq : Rq[i])
      rje[itq] = -query(t_rje, 1, 0, TOUR, q[itq].X, q[itq].Y + 1);
  }

  REP(i, brq) printf("%d\n", rje[i]);
  
  return 0;
}