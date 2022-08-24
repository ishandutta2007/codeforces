#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 107;
int matrix[N][N];
int must[N][N];

void solve() {

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    must[i][j] = 0;
  }

  vector<pair<int, pair<int, int> > > cells;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
      cells.pb(mp(matrix[i][j], mp(i, j)));
    }
  }

  sort(all(cells));
  for (int i = 0; i < m; ++i) {
    int x = cells[i].y.x, y = cells[i].y.y;
    must[x][y] = i + 1;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool have = false;
      for (int e = 0; e < m; ++e) if (must[i][e] == j+1) {
        have = true;
        cout << matrix[i][e] << " ";
      }
      if (!have) {
        for (int e = 0; e < m; ++e) if (must[i][e] == 0) {
          must[i][e] = j + 1;
          cout << matrix[i][e] << " ";
          break;
        }
      }
    }
    cout << '\n';
  }
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