#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1507;
const int M = 11;
pair<int, int> close[N][N][M];

int matrix[N][N];
int subt[N*N];
bool used[N*N];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> matrix[i][j];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      vector<pair<int, int> > arr;
      arr.pb(mp(1, matrix[i][j]));

      if (i - 1 >= 0) {
        for (int e = 0; e <= k; ++e) {
          if (close[i-1][j][e] == mp(0, 0)) break;
          arr.pb(close[i-1][j][e]);
          arr.back().x++;
        }
      }

      if (j - 1 >= 0) {
        for (int e = 0; e <= k; ++e) {
          if (close[i][j-1][e] == mp(0, 0)) break;
          arr.pb(close[i][j-1][e]);
          arr.back().x++;
        }
      }

      if (i-1 >= 0 && j-1 >= 0) {
        for (int e = 0; e <= k; ++e) {
          if (close[i-1][j-1][e] == mp(0, 0)) break;
          arr.pb(close[i-1][j-1][e]);
          arr.back().x++;
        }
      }

      sort(all(arr));
      int t = 0;

      for (auto el : arr) {
        if (used[el.y]) continue;
        used[el.y] = true;
        close[i][j][t++] = el;
        if (t > k) break;
      }

      for (auto el : arr) used[el.y] = false;
      int can = min(i, j) + 1;
      if (close[i][j][k] != mp(0, 0)) {
        can = min(can, close[i][j][k].x - 1);
      }

      subt[can+1]++;
    }
  }

  int cur = n*n;
  for (int i = 0; i < n; ++i) {
    cur -= subt[i + 1];
    cout << cur << " ";
  }

}