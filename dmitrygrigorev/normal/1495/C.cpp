#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[507][507];
char ans[507][507];

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i % 3 == 0) {
        ans[i][j] = 'X';
      }
      else {
        if (j == 0) ans[i][j] = 'X';
        else ans[i][j] = '.';
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == 'X' && ans[i][j] == '.') {
        if (j == 1) {
          ans[i][j] = 'X';
          ans[i][j-1] = '.';

          if (i + 1 < n && (i+1)%3 != 0) {
            ans[i+1][j] = 'X';
            ans[i+1][j-1] = '.';
          }

          if (i - 1 >= 0 && (i-1)%3 != 0) {
            ans[i-1][j] = 'X';
            ans[i-1][j-1] = '.';
          }
        }

        else {
          ans[i][j] = 'X';
          if (i == n-1 && (i%3) == 2) {
            ans[i-1][j] = 'X';
          }
        }

      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j];
    }
    cout << '\n';
  }

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}