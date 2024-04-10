#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

char matrix[50][50];
char ans[50][50];

void solve() {

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
    }
  }

  bool good = true;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i+j)%2 == 0) ans[i][j] = 'R';
      else ans[i][j] = 'W';

      if (matrix[i][j] != '.' && matrix[i][j] != ans[i][j]) good = false;

    }
  }

  if (good) {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << ans[i][j];
      cout << '\n';
    }
    return;
  }

  good = true;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i+j)%2 == 0) ans[i][j] = 'W';
      else ans[i][j] = 'R';

      if (matrix[i][j] != '.' && matrix[i][j] != ans[i][j]) good = false;

    }
  }

  if (good) {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << ans[i][j];
      cout << '\n';
    }
    return;
  }

  cout << "NO\n";



}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}