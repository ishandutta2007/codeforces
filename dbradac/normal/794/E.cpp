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

const int MAX = 1<<19, TOUR = MAX;

int p[MAX], f[MAX], g[MAX]; //f ako prvi igra onaj koji zeli veci, g inace
int parni_f[MAX], parni_g[MAX];
int n;

int t_f[2*TOUR], t_parni[2*TOUR];

void init() {
  REP(i, n) {
    t_f[i+TOUR] = f[i];
    t_parni[i+TOUR] = parni_f[i];
  }
  
  for (int i=TOUR-1; i; i--) {
    t_f[i] = max(t_f[2*i], t_f[2*i+1]);
    t_parni[i] = max(t_parni[2*i], t_parni[2*i+1]);
  }  
}

int vrati(int t[MAX], int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return 0;
  if (lo >= begin && hi <= end) return t[pos];
  return max(vrati(t, 2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati(t, 2*pos+1, (lo+hi)/2, hi, begin, end));
}

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &p[i]);

  REP(i, n) {
    if (!i || i + 1 == n) f[i] = g[i] = p[i];
    else {
      if (p[i] >= max(p[i-1], p[i+1])) f[i] = max(p[i-1], p[i+1]);
      else f[i] = p[i];
      
      if (p[i] <= min(p[i-1], p[i+1])) g[i] = min(p[i-1], p[i+1]);
      else g[i] = p[i];
    }
  }

  REP(i, n) {
    parni_f[i] = max(g[i], g[i+1]);
    parni_g[i] = min(f[i], f[i+1]);
  }
  
  init();

  int mx = 0;
  REP(i, n) mx = max(mx, p[i]);

  REP(k, n) {
    int parnost = (n - k) % 2, rje;
    int l = (0 + (n - 1 - k)) / 2;
    int r = (k + n - 1) / 2;

    if (n - k <= 2) rje = mx;
    else {
      if (parnost)
	rje = vrati(t_f, 1, 0, TOUR, l, r + 1);
      else
	rje = vrati(t_parni, 1, 0, TOUR, l, r + 1);
    }

    printf("%d ", rje);
  }  
  printf("\n");

  return 0;
}