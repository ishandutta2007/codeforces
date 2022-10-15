#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int M = (int) 1e4 + 7;
int n;
int m;
int e[N];
int coef[N][M];
int lol[M];
pair<int, int> matters[M];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);


  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> e[i];
    }
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      assert((int) s.size() == m);
      for (int j = 1; j <= m; j++) {
        assert(s[j - 1] == '0' || s[j - 1] == '1');
        coef[i][j] = s[j - 1] - '0';
      }
    }
    int print = -(int) 2e9;
    vector<int> veve;
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int j = 1; j <= m; j++) {
        matters[j].first = 0;
        matters[j].second = j;
      }
      int sol = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {

          for (int j = 1; j <= m; j++) {
            matters[j].first -= coef[i][j];
          }

          sol += e[i];
          /// randul asta e cu minus
        } else {
          sol -= e[i];

          for (int j = 1; j <= m; j++) {
            matters[j].first += coef[i][j];
          }

          /// randul asta e cu plus
        }
      }

      /// baga greeeeeeedy!!!!!!!!!!!!!!!!!!!!!


      sort(matters + 1, matters + m + 1);
      for (int i = 1; i <= m; i++) {
        sol += i * matters[i].first;
      }

      if (sol > print) {
        print = sol;
        for (int i = 1; i <= m; i++) {
          lol[matters[i].second] = i;
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      cout << lol[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}