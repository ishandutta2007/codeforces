#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 200010, INF = 0x3f3f3f3f;
const int TOUR = 1<<20;

struct event {
  int st, t, ind; //0 dolazi, 2 mice se, 1 query
  event (int st, int t, int ind) : st(st), t(t), ind(ind) {}
  event () {}
};

bool operator < (event a, event b)
{
  if (a.t != b.t)
    return a.t < b.t;
  return a.st < b.st;
}

struct saz {
  int st, tip, val, ind;
  saz (int st, int tip, int val, int ind) : st(st), tip(tip), val(val), ind(ind) {}
  saz () {}
};

bool operator < (saz a, saz b)
{
  if (a.val != b.val)
    return a.val < b.val;
  if (!a.tip && b.tip) {
    if (b.st)
      return 1;
    return 0;
  }
  if (a.tip && !b.tip) {
    if (a.st)
      return 0;
    return 1;
  }
  return a.ind < b.ind;
}

int sl[MAX], sr[MAX], sa[MAX], sb[MAX];
int l[MAX], r[MAX];
int a[MAX], b[MAX], v[MAX];
int n, m;
ll rje=0;
int ind1, ind2;
set <P> S;
vector <event> E;
P t[2*TOUR];
int bio[TOUR];

void Stavi(int pos, P val)
{
  for (t[pos+TOUR] = val, pos = (pos + TOUR) / 2; pos; pos /= 2)
    t[pos] = max(t[2*pos], t[2*pos+1]);
}

P Vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return P(-1, -1);
  if (lo >= begin && hi <= end)
    return t[pos];
  return max(Vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
             Vrati(2*pos+1, (lo+hi)/2, hi, begin, end) );
}

void SweepJaLijevo()
{
  E.clear();
  S.clear();

  for (int i=0; i<n; i++) {
    E.push_back(event(0, l[i], i));
    E.push_back(event(2, r[i], i));
  }

  for (int i=0; i<m; i++)
    E.push_back(event(1, a[i], i));
  
  sort(E.begin(), E.end());

  for (int i=0; i<(int) E.size(); i++) {
    event ev = E[i];
    if (!ev.st)
      S.insert(P(-r[ev.ind], ev.ind));
    else if (ev.st == 2)
      S.erase(P(-r[ev.ind], ev.ind));
    else {
      if (!S.empty()) {
        P tmp = *(S.begin());
        ll nr = min((b[ev.ind] - ev.t), (-tmp.X - ev.t)) * (ll) v[ev.ind];        
        if (nr > rje) {
          rje = nr;
          ind1 = tmp.Y;
          ind2 = ev.ind;
        }
      }
    }
  }
}

void SweepJaVani()
{
  E.clear();

  for (int i=0; i<m; i++) {
    E.push_back(event(0, sa[i], i));
    E.push_back(event(2, sb[i], i));
  }

  for (int i=0; i<n; i++)
    E.push_back(event(1, sl[i], i));

  memset(t, -1, sizeof t);
  sort(E.begin(), E.end());

  for (int i=0; i<(int) E.size(); i++) {
    event ev = E[i];

    if (!ev.st)
      Stavi(sb[ev.ind], P(v[ev.ind], ev.ind));
    else if (ev.st == 2)
      Stavi(sb[ev.ind], P(-1, -1));
    else {
      P vr = Vrati(1, 0, TOUR, sr[ev.ind] + 1, TOUR);
      ll nr = (ll) vr.X * (r[ev.ind] - l[ev.ind]);      
      if (nr > rje) {
        rje = nr;
        ind1 = ev.ind;
        ind2 = vr.Y;
      }
    }
  }
}

void Okreni()
{
  for (int i=0; i<n; i++) {
    l[i] = INF - l[i];
    r[i] = INF - r[i];
    swap(l[i], r[i]);
  }

  for (int i=0; i<m; i++) {
    a[i] = INF - a[i];
    b[i] = INF - b[i];
    swap(a[i], b[i]);
  }
}

vector <saz> ZaS;

void Sazmi()
{
  for (int i=0; i<n; i++) {
    ZaS.push_back(saz(0, 0, l[i], i));
    ZaS.push_back(saz(1, 0, r[i], i));
  }

  for (int i=0; i<m; i++) {
    ZaS.push_back(saz(0, 1, a[i], i));
    ZaS.push_back(saz(1, 1, b[i], i));  
  }

  sort(ZaS.begin(), ZaS.end());
  for (int i=0; i<(int) ZaS.size(); i++) {
    saz tmp = ZaS[i];
    if (!tmp.tip) {
      if (!tmp.st)
        sl[tmp.ind] = i;
      else
        sr[tmp.ind] = i;
    }
    else {
      if (!tmp.st)
        sa[tmp.ind] = i;
      else
        sb[tmp.ind] = i;
    }
  }
}

int main()
{
  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++)
    scanf("%d%d", &l[i], &r[i]);
  
  for (int i=0; i<m; i++)
    scanf("%d%d%d", &a[i], &b[i], &v[i]);
  
  SweepJaLijevo();
  Okreni();
  SweepJaLijevo();
  Okreni();
  Sazmi();
  SweepJaVani();
  
  cout << rje << endl;
  if (rje)
    printf("%d %d\n", ind1 + 1, ind2 + 1);

  return 0;
}