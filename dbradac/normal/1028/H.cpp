#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MAXN = 2e5, MAXQ = 1<<21, MAXM = 5100000;

int sito[MAXM];

void eratosten() {
  FOR(i, 2, MAXM)
    if (!sito[i])
      for (int j=i; j<MAXM; j+=i)
        sito[j] = i;
}

vector <int> Prosti(int x) {
  vector <int> R;

  for (; x>1; ) {
    int pr = sito[x], pot = 0;
    for (; sito[x] == pr; x /= sito[x], pot++);
    if (pot % 2) R.push_back(pr);
  }

  return R;
}

struct event {
  int r, val;
};

vector <event> Ev[MAXN]; //push on l
int gdje[MAXM][8]; //set to MAX-1
int p[MAXN];

void add_num(int pos) {
  vector <int> R = Prosti(p[pos]);
  int sz = (int) R.size();

  REP(msk, 1<<sz) {
    int umn = 1;
    REP(j, sz) if (msk>>j & 1) umn *= R[j];
    gdje[umn][sz - __builtin_popcount(msk)] = pos;
  }
}

int n, brq;
void gen_events() {
  REP(i, MAXM) REP(j, 8) gdje[i][j] = MAXN-1;
  int mn[20];

  for (int i=n-1; i>=0; i--) {
    REP(j, 20) mn[j] = MAXN-1;

    vector <int> R = Prosti(p[i]);
    int sz = (int) R.size();

    REP(msk, 1<<sz) {
      int umn = 1;
      REP(j, sz) if (msk>>j & 1) umn *= R[j];
      REP(ost, 8) {
        int pos = gdje[umn][ost];
        int val = ost + sz - __builtin_popcount(msk);
        mn[val] = min(mn[val], pos);
      }
    }

    REP(j, 20) Ev[i].push_back({mn[j], j});

    add_num(i);
  }
}

int fen[MAXN];
vector <P> Q[MAXN];
int sol[MAXQ];

void upd(int pos, int val) {
  pos++;
  for (; pos < MAXN; pos += pos & -pos)
    fen[pos] = min(fen[pos], val);
}

int get(int pos) {
  pos++;
  int ret = MAXN;
  for (; pos; pos -= pos & -pos)
    ret = min(ret, fen[pos]);
  return ret;
}

void solve() {
  REP(i, MAXN) fen[i] = MAXN;

  for (int i=n-1; i>=0; i--) {
    for (auto it : Ev[i])
      upd(it.r, it.val);
    
    for (auto q : Q[i])
      sol[q.Y] = get(q.X);
  }
}

int main()
{
  eratosten();

  scanf("%d%d", &n, &brq);

  REP(i, n) scanf("%d", &p[i]);

  REP(i, brq) {
    int l, r;
    scanf("%d%d", &l, &r); l--; r--;
    Q[l].push_back(P(r, i));
  }

  gen_events();
  solve();

  REP(i, brq) printf("%d\n", sol[i]);

  return 0;
}