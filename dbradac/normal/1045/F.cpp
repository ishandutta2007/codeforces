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

const int MAX = 1<<18;

int sgn(ll x) {
  if (x < 0) return -1;
  return x > 0;
}

int ccw(P a, P b, P c) {
  ll tmp = (ll) a.X * (b.Y - c.Y) + (ll) b.X * (c.Y - a.Y) + (ll) c.X * (a.Y - b.Y);
  return sgn(tmp);
}

vector <P> Pt;

int cmp_angle(P a, P b) {
  ll tmp = (ll) a.Y * b.X - (ll) b.Y * a.X;
  return sgn(tmp);
}

bool manji_angle(P a, P b) {
  return cmp_angle(a, b) == 1;
}

bool manji(P a, P b) {
  if (!a.X) {
    if (!b.X) return a.Y > b.Y;
    return true;
  }
  if (!a.Y) {
    if (!b.Y) return a.X > b.X;
    return false;
  }

  ll tmp = cmp_angle(a, b);
  if (tmp) return tmp == 1;
  return a.Y+a.X > b.Y+b.X;
}

vector<P> hull(const vector <P> &V) {
  vector <P> H;

  int sz = (int) V.size();
  REP(i, sz) {
    if (!H.empty() && !cmp_angle(V[i], H.back())) continue;
    for (; H.size() >= 2 && ccw(H[H.size()-2], H.back(), V[i]) >= 0; ) H.pop_back();
    H.push_back(V[i]);
  }

  return H;
}

void yes() {
  printf("Ani\n");
  exit(0);
}

P p[MAX];
int n;

bool paran(P x) {
  return x.X % 2 == 0 && x.Y % 2 == 0;
}

void check(const vector <P> &T) {
  auto H = hull(T);
  for (auto it : H)
    if (!paran(it)) yes();
}

void solve() {
  sort(p, p + n, manji);
  vector <P> Hull = hull(vector<P>(p, p+n));

  check(vector<P>(p, p+n));

  for (auto rub : vector<int>{0, (int) Hull.size()-1}) {
    vector <P> T;
    REP(i, n) 
      if (p[i] != Hull[rub])
        T.push_back(p[i]);

    check(T);
  }

  FOR(i, 1, (int) Hull.size()-1) {
    auto poc = lower_bound(p, p + n, Hull[i-1], manji_angle);
    auto kraj = upper_bound(p, p + n, Hull[i+1], manji_angle);
    vector <P> T;
    for (auto it=poc; it<kraj; it++)
      if (*it != Hull[i])
        T.push_back(*it);

    check(T);
  }
}

void load() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d%d", &p[i].X, &p[i].Y);
    if (p[i] == P(0, 0)) {
      i--;
      n--;
    }
  }
}

int main()
{
  load();
  solve();
  printf("Borna\n");

  return 0;
}