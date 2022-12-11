#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

ld k[20];
ld p[20];
int ind[20];
ld res[20];

int main() {
  int n, ka;
  cin >> n >> ka;
  int tt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    if (p[i] > 0) {
      k[tt] = p[i];
      ind[tt] = i;
      ++tt;
    }
  }
  ka = min(ka, tt);
  ld m[(1<<tt)];
  memset(m, 0, sizeof m);
  m[0] = 1;
  for (int mask = 0; mask < (1<<tt); ++mask) {
    ld ss = 0;
    for (int i = 0; i < tt; ++i) {
      if (((1<<i)&mask) > 0) ss += k[i];
    }
    for (int i = 0; i < tt; ++i) {
      if (((1<<i)&mask) == 0) {
	m[mask|(1<<i)] += m[mask]*k[i]/(1.0 - ss);
      }
    }
  }
  for (int mask = 0; mask < (1<<tt); ++mask) {
    int cc = 0;
    for (int i = 0; i < tt; ++i) {
      if (((1<<i)&mask)) ++cc;
    }
    if (cc != ka) continue;
    for (int i = 0; i < tt; ++i) {
      if (((1<<i)&mask)) res[ind[i]] += m[mask];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << setprecision(10) << fixed << res[i];
  }
  cout << endl;
}