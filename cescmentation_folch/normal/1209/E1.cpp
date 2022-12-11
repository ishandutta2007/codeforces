#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<pi> vpi;

vvi B;

int f(vi S, int ind) {
  if (ind == 0) {
    int res = 0;
    for (auto x : S) res += x;
    return res;
  }

  int res = 0;
  int n = S.size();
  for (int s = 0; s < n; ++s) {
    vi S1 = S;
    for (int i = 0; i < n; ++i) {
      S1[i] = max(S1[i], B[(i+s)%n][ind]);
    }
    res = max(res, f(S1, ind-1));
  }
  return res;
}

int main() {
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
    int extv;
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

    B = vvi(n, vi(newm));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < newm; ++j) {
        B[i][j] = A[i][M[j].second];
      }
    }
    vi S(n);
    for (int i = 0; i < n; ++i) {
      S[i] = B[i][0];
      if (extn) S[i] = max(S[i], extv);
    }

    cout << f(S, newm - 1) << '\n';
  }
}