#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long double ld;

const ld eps = 1e-14;
const int N = (int) 1e5 + 7;
int n;
int x_int[N], y_int[N];

long long f(int i, int j) {
  long long x1 = x_int[i], y1 = y_int[i];
  long long x2 = x_int[j], y2 = y_int[j];
  return (x1 - x2) * (y1 + y2);
}

long long fcapete(int i, int j) {
  long long x1 = x_int[i], y1 = y_int[i];
  long long x2 = x_int[j], y2 = y_int[j];
  long long x = abs(x1 - x2);
  long long y = abs(y1 - y2);

  assert(x > 0 || y > 0);

  return __gcd(x, y) - 1;
}

const int BULAN = 60;

ld my_pw(ld x, int y) {
  ld r = 1;
  for (int i = 1; i <= y; i++) {
    r *= x;
  }
  return r;
}


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x_int[i] >> y_int[i];
  }

  long long total_dub_area = 0;
  for (int i = 0; i < n; i++) {
    total_dub_area += f(i, (i + 1) % n);
  }

  ld total_area = (ld) total_dub_area * 0.5;

  long long capete = n;

  for (int i = 0; i < n; i++) {
    capete += fcapete(i, (i + 1) % n);
  }

  ld ct = 1 + n + n * (long long) (n - 1) / 2;
  ld guy = 1;
  for (int i = 0; i < n; i++) {
    guy *= 2;
  }
  guy -= ct;

  ld b = capete;

  ld inside = total_area - b * 0.5 + 1;
  ld init;
  if (n <= BULAN) {
    init = my_pw(2, n - 1) / (my_pw(2, n) - ct);
  } else {
    init = (ld) 0.5;
  }
  ld sum = 0;

  for (int i = 0; i < n; i++) {
    ld prob = init;

    ld area_ij_total = 0, capete_total = 0;
    for (int jump = 1; jump < min(n, 50); jump++) {
      int j = (i + jump) % n;

      area_ij_total += f((i + jump - 1) % n, (i + jump) % n);
      capete_total += fcapete((i + jump - 1) % n, (i + jump) % n);


      ld coef = 0;
      ld area_ij = area_ij_total;

      area_ij += f(j, i);


      ld capete = capete_total;

      capete += jump + 1;
      capete += fcapete(j, i);


      prob *= 0.5;

      ld prob_h = prob;

      if (n <= BULAN) {
        prob_h -= (ld) 1 / guy;
      }

      sum += (area_ij * 0.5 - capete * 0.5 + 1 + fcapete(j, i)) * prob_h;
    }
  }


  cout << fixed << setprecision(9) << inside - sum << "\n";
}