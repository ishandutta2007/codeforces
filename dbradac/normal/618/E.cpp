#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<double, double> P;
#define X first
#define Y second

const int MAX = 301000, KOR = 1000;
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
const double EPS = 1e-6;

struct ev {
  int st, ind; //1 = rot, 2 = trans
  P prom;
};

bool operator < (const ev &a, const ev &b)
{
  return a.ind < b.ind;
}

vector <ev> E;
P poc[MAX], pros[MAX], p[MAX];
int n;
vector <int> Bit;
double cc[400], ss[400];

P Rot(P toc, int an)
{
  return P(toc.X * cc[an] - toc.Y * ss[an], 
           toc.Y * cc[an] + toc.X * ss[an]);
}

P Trans(P toc, P pom)
{
  return P(toc.X + pom.X, toc.Y + pom.Y);
}

P Toc(int prosli, int ja, int an, P polje[MAX])
{
  return Trans(p[prosli], Rot(P(polje[ja].X - polje[prosli].X, polje[ja].Y - polje[prosli].Y), an));
}

inline double Sq(double x)
{
  return x * x;
}

double Dist(P a, P b)
{
  return sqrt(Sq(a.X - b.X) + Sq(a.Y - b.Y));
}

void Event(ev tmp)
{
  for (int i=0; i<(int) Bit.size(); i++)
    pros[Bit[i]] = p[Bit[i]];

  for (int i=0; i<(int) Bit.size(); i++) {
    if (Bit[i] > tmp.ind) {        
      if (tmp.st == 1)
        p[Bit[i]] = Toc(tmp.ind, Bit[i], (int) (0.5 + tmp.prom.X), pros);
      else
        p[Bit[i]] = Trans(p[Bit[i]], tmp.prom);
    }
  }

  E.push_back(tmp);
}

void Rebuild()
{
  int zad = 0;
  int an = 0;

  sort(E.begin(), E.end());
  for (int i=0; i<(int) Bit.size(); i++)
    pros[Bit[i]] = p[Bit[i]];

  for (int i=0, j=0, k=0; i<n; i++) {
    for (; j<(int) E.size() && E[j].ind == i; j++)
      if (E[j].st == 1)
        an = ((int) (an + E[j].prom.X + 0.5)) % 360;

    if (k < (int) Bit.size() && Bit[k] == i) {
      zad = i;
      k++;
    }
    else
      p[i] = Toc(zad, i, an, poc);
  }

  memcpy(poc, p, sizeof p);
  E.clear();
}

int qst[MAX], qind[MAX], qval[MAX];

int main()
{
  for (int i=0; i<360; i++) {
    cc[i] = cos(-PI / 180 * i);
    ss[i] = sin(-PI / 180 * i);
  }

  int m;

  scanf("%d%d", &n, &m); n++;

  for (int i=0; i<n; i++)
    p[i] = P(i, 0);

  for (int i=0; i<m; i++) {
    scanf("%d%d%d", &qst[i], &qind[i], &qval[i]); qind[i]--;
    qst[i] = 3 - qst[i];
  }

  memcpy(poc, p, sizeof p);

  for (int i=0; i<m; i++) {
    if (!(i % KOR)) {
      TRACE(i);
      Bit.clear();

      for (int j=i; j<i+KOR+1; j++) {
        Bit.push_back(qind[j]);
        if (qst[j] == 2)
          Bit.push_back(qind[j]+1);
      }

      Bit.push_back(0);
      Bit.push_back(n-1);
      sort(Bit.begin(), Bit.end());
      Bit.resize(unique(Bit.begin(), Bit.end()) - Bit.begin());
      memcpy(pros, p, sizeof pros);
    }

    int st = qst[i], ind = qind[i];

    if (qst[i] == 1)
      Event(ev { st, ind, P(qval[i], -1) });
    else {
      P raz = P(p[ind+1].X - p[ind].X, p[ind+1].Y - p[ind].Y);
      double kut = atan2(raz.Y, raz.X);
      P smjer = P(cos(kut), sin(kut));
      Event(ev { st, ind, P(smjer.X * qval[i], smjer.Y * qval[i]) });
    }

    if (E.size() == KOR) {
      Rebuild();
      E.clear();
      memcpy(pros, p, sizeof pros);
    }

    printf("%.10lf %.10lf\n", p[n-1].X, p[n-1].Y);
  }

  return 0;
}