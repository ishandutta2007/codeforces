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

const int MAX = 1<<19;

vector <int> V[MAX];
vector <P> Ciklus;
int bio[MAX], kad[MAX], par[MAX], vr = 1;
int n, m;
pair<P, int> q[MAX];
vector <int> Desne[MAX];
int dokle[MAX];
ll rje[MAX];

P cik(int node, int gor) {
  int mn = node, mx = node;
  for (;;) {
    assert(par[node] != -1);
    node = par[node];
    mn = min(mn, node);
    mx = max(mx, node);

    if (node == gor) break;
  }

  return P(mn, mx);
}

void dfs(int node, int pr) {
  bio[node] = 1;
  kad[node] = vr++;
  par[node] = pr;

  for (auto it : V[node]) {
    if (bio[it]) {
      if (it == pr || kad[it] > kad[node]) continue;      
      Ciklus.push_back(cik(node, it));
    }
    else
      dfs(it, node);
  }
}

void find_cycles() {
  REP(i, n) if (!bio[i]) dfs(i, -1);
}

void gen_dokle() {
  int td = n-1;
  for (int i=n-1; i>=0; i--) {
    for (auto it : Desne[i]) td = min(td, it - 1);
    dokle[i] = td;
  }
}

void stavi(ll fn[MAX], int pos, ll val) {
  for (pos+=3; pos<MAX; pos += pos & -pos)
    fn[pos] += val;
}

ll vrati(ll fn[MAX], int pos) {
  ll ret=0;
  for (pos+=3; pos; pos -= pos & -pos)
    ret += fn[pos];
  return ret;
}

ll fen_sum[MAX], fen_kol[MAX], sum_lev[MAX];

int main()
{
  scanf("%d%d", &n, &m);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  find_cycles();

  int brq;
  scanf("%d", &brq);

  REP(i, brq) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    q[i] = make_pair(P(a, b), i);
  }

  sort(q, q + brq, [] (pair<P, int> a, pair<P, int> b) {
      return a.X.Y < b.X.Y; });

  for (auto it : Ciklus)
    Desne[it.X].push_back(it.Y);

  gen_dokle();

  REP(i, n) stavi(sum_lev, i, i);
  REP(i, n) stavi(fen_kol, i, 1);

  int inddokle = 0;
  REP(i, brq) {
    for (; inddokle < n && dokle[inddokle] <= q[i].X.Y; inddokle++) {
      stavi(fen_sum, inddokle, dokle[inddokle] - inddokle + 1);
      stavi(fen_kol, inddokle, -1);
      stavi(sum_lev, inddokle, -inddokle);
    }

    ll mojval = vrati(fen_sum, q[i].X.Y) - vrati(fen_sum, q[i].X.X-1);
    mojval += ((ll) q[i].X.Y + 1) * (vrati(fen_kol, q[i].X.Y) - vrati(fen_kol, q[i].X.X-1))
              - (vrati(sum_lev, q[i].X.Y) - vrati(sum_lev, q[i].X.X-1));

    rje[q[i].Y] = mojval;
  }

  REP(i, brq) printf("%lld\n", rje[i]);

  return 0;
}