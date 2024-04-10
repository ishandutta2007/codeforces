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

const int TOUR = 1<<17;
const ll INF = 1e18;

int n;
ll sum;
ll p[TOUR];

struct node {
  ll mn1, mn2, mx3, dod; //3 je samo ako je veci od oba
} t[2*TOUR];

ll vrati(int pos) {
  pos += TOUR;
  ll ret = 0;

  for (; pos; pos /= 2)
    ret += t[pos].dod;

  return ret;
}

node get_sve(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return {INF, INF, -INF, 0};
  if (lo >= begin && hi <= end) return t[pos];

  node l = get_sve(2*pos+0, lo, (lo+hi)/2, begin, end);
  node r = get_sve(2*pos+1, (lo+hi)/2, hi, begin, end);
  return node{ min(l.mn1, r.mn1), min(l.mn2, r.mn2), max(l.mx3, r.mx3), 0};
}

void upd_pos(int pos) {
  if (pos <= 0 || pos >= n-1) return;

  ll ja = vrati(pos), a = vrati(pos-1), b = vrati(pos+1);
  if (a > b) swap(a, b);
  
  pos += TOUR;
  t[pos] = {INF, INF, -INF, t[pos].dod};

  if (ja >= b) t[pos].mx3 = 1;
  else if (ja >= a) t[pos].mn2 = b - ja;
  else t[pos].mn1 = b + a - ja - ja;

  for (pos /= 2; pos; pos /= 2) {
    int l = 2*pos, r = 2*pos+1;
    t[pos] = {min(t[l].mn1, t[r].mn1), min(t[l].mn2, t[r].mn2), max(t[l].mx3, t[r].mx3), t[pos].dod};
  }
}

ll val(int pos) {
  ll ret = 0, ja = vrati(pos);
  if (pos) ret += abs(vrati(pos-1) - ja);
  if (pos != n-1) ret += abs(vrati(pos+1) - ja);

  return ret;
}

ll check(int pos, ll x) {
  ll ret = -val(pos);
  t[pos+TOUR].dod += x;
  ret += val(pos);
  t[pos+TOUR].dod -= x;

  return ret;
}

ll ans(int l, int r, ll x) {
  ll ret = sum + max(check(l, x), check(r, x));
  if (l == r) return ret;

  node tmp = get_sve(1, 0, TOUR, l, r + 1);

  if (tmp.mx3 > 0) ret = sum + 2 * x;
  ret = max(ret, sum + 2*x - 2*tmp.mn2);
  ret = max(ret, sum + 2*x - 2*tmp.mn1);

  return ret;
}

void stavi(int pos, int lo, int hi, int begin, int end, ll val) {
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    t[pos].dod += val;
    return;
  }

  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
}

void upd(int l, int r, ll x) {
  vector <int> ppp = {l, l-1, r, r+1};
  sort(ppp.begin(), ppp.end());
  ppp.resize(unique(ppp.begin(), ppp.end()) - ppp.begin());

  if (l) sum -= abs(vrati(l) - vrati(l-1));
  if (r+1 < n) sum -= abs(vrati(r) - vrati(r+1));

  stavi(1, 0, TOUR, l, r+1, x);

  if (l) sum += abs(vrati(l) - vrati(l-1));
  if (r+1 < n) sum += abs(vrati(r) - vrati(r+1));


  for (auto it : ppp)
    if (it >= 0 && it < n) upd_pos(it);
}

int main()
{
  REP(i, 2*TOUR) t[i] = {INF, INF, -INF, 0};

  scanf("%d", &n);
  REP(i, n) scanf("%lld", &p[i]);
  REP(i, n) upd(i, i, p[i]);

  sum = 0;
  REP(i, n-1) sum += abs(p[i] - p[i+1]);

  int qq;
  scanf("%d", &qq);

  for (; qq--; ) {
    int st, l, r;
    ll x;
    scanf("%d%d%d%lld", &st, &l, &r, &x); l--; r--;
    if (st == 1) printf("%lld\n", ans(l, r, x));
    else upd(l, r, x);
  }

  return 0;
}