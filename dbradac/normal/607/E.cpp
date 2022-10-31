#include <cstdio>
#include <ctime>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long double llf;
typedef pair<llf, llf> P;
#define X first
#define Y second

const int MAX = 50005;
const llf EPS = 1e-6;

bool Jednak(llf a, llf b)
{
  return abs(a - b) < EPS;
}

inline llf Sq(llf x)
{
  return x * x;
}

P TocNaPrav(P prav, llf x)
{
  return P(x, prav.X * x + prav.Y);
}

pair <P, P> SjecKruz(P prav, llf r)
{
  llf disk = 4 * Sq(prav.X * prav.Y) - 4 * (Sq(prav.X) + 1) * (Sq(prav.Y) - Sq(r));
  if (disk < 0)
    return make_pair(P(0, 0), P(1, 1));
  return make_pair(TocNaPrav(prav, (-2 * prav.X * prav.Y + sqrt(disk)) / (2 * (Sq(prav.X) + 1))),
                   TocNaPrav(prav, (-2 * prav.X * prav.Y - sqrt(disk)) / (2 * (Sq(prav.X) + 1))));
}

P Sjec(P a, P b)
{
  llf x = (b.Y - a.Y) / (a.X - b.X);
  return P(x, a.X * x + a.Y);
}

llf Dist(P a)
{
  return sqrt(Sq(a.X) + Sq(a.Y));
}

P p[MAX];
int poz[MAX], ind[MAX];
int fen[MAX];
int n, m;
llf xpoc, ypoc;
set <int> S;

void Stavi(int pos, int val)
{
  for (pos++; pos < MAX; pos += pos & -pos)
    fen[pos] += val;
}

int Vrati(int pos)
{
  int ret=0;
  for (pos++; pos; pos -= pos & -pos)
    ret += fen[pos];
  return ret;
}

vector <int> Sjecista(llf r)
{
  vector <int> R;
  vector <pair<llf, int> > Tmp;

  for (int i=0; i<n; i++) {
    pair<P, P> tmp = SjecKruz(p[i], r);
    if (Jednak(tmp.X.X, 0) && Jednak(tmp.X.Y, 0) && Jednak(tmp.Y.X, 1) && Jednak(tmp.Y.Y, 1))
      continue;
    
    Tmp.push_back(make_pair(atan2((double) tmp.X.Y, (double) tmp.X.X), i));
    Tmp.push_back(make_pair(atan2((double) tmp.Y.Y, (double) tmp.Y.X), i));
  }

  R.resize(Tmp.size());
  sort(Tmp.begin(), Tmp.end());
  for (int i=0; i<(int) Tmp.size(); i++)
    R[i] = Tmp[i].Y;
  
  return R;
}

int BrojSjec(llf r)
{
  vector <int> V = Sjecista(r);

  memset(fen, 0, sizeof fen);
  memset(poz, -1, sizeof poz);  

  int ret = 0;
  int tpoz = MAX - 3;
  for (int i=0; i<(int) V.size(); i++) {
    if (poz[V[i]] == -1) {
      poz[V[i]] = tpoz--;
      Stavi(poz[V[i]], 1);
    }
    else {
      Stavi(poz[V[i]], -1);
      ret += Vrati(poz[V[i]]);
      if (ret > m)
        return ret;      
    }
  }

  return ret;
}

llf Suma(llf r)
{
  vector <int> V = Sjecista(r);
  
  memset(poz, -1, sizeof poz);

  llf ret = 0;
  int tpoz = 0;

  for (int i=0; i<(int) V.size(); i++) {
    if (poz[V[i]] == -1) {
      ind[tpoz] = V[i];
      poz[V[i]] = tpoz++;
      S.insert(poz[V[i]]);
    }
    else {
      for (set <int> :: iterator it = --S.end();; it--) {
        if (*it == poz[V[i]]) {
          S.erase(it);
          break;
        }
        ret += Dist(Sjec(p[V[i]], p[ind[*it]]));
      }
    }
  }

  return ret + (m - BrojSjec(r)) * r;
}

int main()
{
  cin >> n >> xpoc >> ypoc >> m;
  xpoc /= 1000, ypoc /= 1000;

  for (int i=0; i<n; i++) {
    cin >> p[i].X >> p[i].Y;
    p[i].X /= 1000, p[i].Y /= 1000;
    p[i].Y += p[i].X * xpoc - ypoc;
  }

  llf lo = 0, hi = 1e10;
  for (int i=0; i<70; i++) {
    llf mid = (lo + hi) / 2;
    int tmp = BrojSjec(mid);
    if (tmp == m) {
      lo = mid;
      break;
    }

    if (tmp > m)
      hi = mid;
    else
      lo = mid;
  }

  printf("%.10lf\n", (double) Suma(lo));

  return 0;
}