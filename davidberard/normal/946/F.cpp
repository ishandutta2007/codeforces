#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

using Matrix = vector<vector<ll>>;
const ll MOD = 1e9+7;

Matrix mult(const Matrix& A, const Matrix& B) {
  assert(A[0].size() == B.size());
  Matrix M(A.size(), vector<ll>(B[0].size()));
  for (int i=0; i<A.size(); ++i) {
    for (int j=0; j<B[0].size(); ++j) {
      for (int k=0; k<B.size(); ++k) {
        M[i][j] += A[i][k]*B[k][j]%MOD;
      }
      M[i][j] %= MOD;
    }
  }
  return M;
}

Matrix ZERO, ONE;
Matrix F[110];
int n, x;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> x;
  string s;
  cin >> s;
  ONE = ZERO = vector<vector<ll>>(n+1, vector<ll>(n+1));
  ONE[n][n] = ZERO[n][n] = 2;
  for (int i=0; i<n; ++i) {
    {
      string t = s.substr(0, i);
      t += '0';
      int j = (i == n-1 && t == s ? 1 : 0);
      for (; j<=i+1; ++j) {
        if (s.substr(0, t.size()-j) == t.substr(j)) {
          //cerr << "! " << s.substr(0, t.size()-j) << " " << t.substr(j) << endl;
          break;
        }
      }
      ZERO[i][i]++;
      assert(j <= i+1);
      ZERO[i][i-j+1]++;
      if (t == s) {
        ZERO[i][n]++;
      }
    }
    {
      string t = s.substr(0, i);
      t += '1';
      int j = (i == n-1 && t == s ? 1 : 0);
      for (; j<=i+1; ++j) {
        if (s.substr(0, t.size()-j) == t.substr(j)) {
          //cerr << "! " << s.substr(0, t.size()-j) << " " << t.substr(j) << endl;
          break;
        }
      }
      ONE[i][i]++;
      assert(j <= i+1);
      ONE[i][i-j+1]++;
      if (t == s) {
        ONE[i][n]++;
      }
    }
  }
  F[0] = ZERO;
  F[1] = ONE;
  for (int i=2; i<=x; ++i) {
    F[i] = mult(F[i-1],F[i-2]);
  }
  Matrix vec(1, vector<ll>(n+1));
  vec[0][0] = 1;
  auto ans = mult(vec, F[x])[0][n];
  cout << ans << "\n";
  return 0;
}