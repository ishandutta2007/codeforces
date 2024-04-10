#include <cstdio>
#include <map>
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

const int MAX = 1<<19;

int fen[MAX];

void add(int pos, int x) {
  for (pos+=3; pos < MAX; pos += pos & -pos)
    fen[pos] += x;
}

int get(int pos) {
  int r=0;
  for (pos+=3; pos; pos -= pos & -pos)
    r += fen[pos];
  return r;
}
vector <int> Bitne_Koor;

int get_koor(int x) {
  return (int) (lower_bound(Bitne_Koor.begin(), Bitne_Koor.end(), x) - Bitne_Koor.begin());
}

struct str {
  int x, q, r, lijevo, desno;
} p[MAX];

bool operator < (const str &a, const str &b) {
  return a.r > b.r;
}

map <int, vector<int> > M;

int query(int ind) {
  return get(p[ind].desno) - get(p[ind].lijevo-1);
}

void stavi(int ind, int val) {
  add(p[ind].x, val);
}

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  REP(i, n) {
    scanf("%d%d%d", &p[i].x, &p[i].r, &p[i].q);
    Bitne_Koor.push_back(p[i].x);
    Bitne_Koor.push_back(p[i].x - p[i].r);
    Bitne_Koor.push_back(p[i].x + p[i].r);
  }

  sort(Bitne_Koor.begin(), Bitne_Koor.end());
  REP(i, n) {
    p[i].lijevo = get_koor(p[i].x - p[i].r);
    p[i].desno = get_koor(p[i].x + p[i].r);
    p[i].x = get_koor(p[i].x);
  }

  sort(p, p + n);

  REP(i, n)
    M[p[i].q].push_back(i);

  ll sol = 0;
  FOR(raz, -k, k+1) { //veci ima 
    for (auto it = M.begin(); it != M.end(); it++) {
      if (M.find(it->X + raz) == M.end()) continue;

      vector <int> &L = it->Y;
      vector <int> &R = M[it->X + raz];

      for (int indl=0, indr=0; indl < (int) L.size() || indr < (int) R.size(); ) {
        if (indl == (int) L.size() || (indr != (int) R.size() && R[indr] <= L[indl]))
          sol += query(R[indr++]);
        else
          stavi(L[indl++], 1);
      }

      REP(indl, (int) L.size())
        stavi(L[indl], -1);
    }
  }

  printf("%lld\n", sol);

  return 0;
}