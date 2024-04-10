#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<pi> vpi;

int main() {
  vi pot3(20);
  pot3[0] = 1;
  for (int i = 1; i < 20; ++i) pot3[i] = 3*pot3[i-1];
  vpi rep3(pot3[12], pi(0,0));
  for (int mask = 1; mask < pot3[12]; ++mask) {
    int pott = 1;
    int mm = mask;
    while (mm) {
      int k = mm%3;
      if (k == 1) rep3[mask].first |= pott;
      else if (k == 2) rep3[mask].second |= pott;
      pott *= 2;
      mm /= 3;
    }
  }


  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vpi M(m);
    for (int i = 0; i < m; ++i) {
      M[i].first = 0;
      M[i].second = i;
    }
    vvi A(n, vi(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> A[i][j];
        M[j].first = max(M[j].first, A[i][j]);
      }
    }
    sort(M.rbegin(), M.rend());
    int extn = 0;
    int extv = 0;
    if (n <= m) {
      extn = 1;
      extv = M[n-1].first;
      int ind = n-2;
      while (ind >= 0 and M[ind].first == extv) {
        ++extn;
        --ind;
      }
    }
    int newm = min(m,n) - extn;

    if (newm == 0) {
      cout << n*extv << '\n';
      continue;
    }

    vvi B(n, vi(newm));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < newm; ++j) {
        B[i][j] = max(extv, A[i][M[j].second]);
      }
    }

    vvi D(newm + 1, vi((1<<n), 0));
    for (int i = 0; i < newm; ++i) {
      vi P((1<<n),0);
      for (int mask = 1; mask < (1<<n); ++mask) {
        for (int s = 0; s < n; ++s) {
          int val = 0;
          for (int j = 0; j < n; ++j) {
            int ind = (s+j)%n;
            if ((1<<ind)&mask) val += B[j][i];
          }
          P[mask] = max(P[mask], val);
        }
      }

      for (int mask = 1; mask < pot3[n]; ++mask) {
        int mask2 = rep3[mask].first | rep3[mask].second;
        D[i+1][mask2] = max(D[i+1][mask2], D[i][rep3[mask].first] + P[rep3[mask].second]);
      }
    }

    cout << D[newm][(1<<n) -1] << '\n';
  }
}