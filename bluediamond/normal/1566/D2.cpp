/**

48 -> 8:17
43 -> 8:33
42 -> 8:42
41 -> 8:47
39 -> 8:54
37 -> 9:06
36 -> 9:13
34 -> 9:21
33 -> 9:27
32 -> 9:34
31 -> 9:39
26 -> 10:03

**/

#include <bits/stdc++.h>

using namespace std;

int tt, n, m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    vector<int> a(n * m);
    for (auto &x : a) {
      cin >> x;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<vector<int>> matr(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matr[i][j] = b[i * m + j];
      }
    }

    vector<map<int, int>> cnt(n);
    map<int, int> last, first;
    map<int, vector<int>> unde;

    for (int i = 0; i < n * m; i++) {
      unde[a[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
      for (auto &x : matr[i]) {
        cnt[i][x]++;
        last[x] = i;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (auto &x : matr[i]) {
        first[x] = i;
      }
    }
    vector<vector<int>> indici(n);
    for (auto &it : first) {
      int x = it.first;
      int ff = first[x], ss = last[x];
      if (ff == ss) {
        for (auto &i : unde[x]) {
          indici[ff].push_back(i);
        }
        assert(cnt[ff][x] == (int) unde[x].size());
      } else {
        int cntff = cnt[ff][x];
        int cntss = cnt[ss][x];
        assert(cntff + cntss + (ss - ff - 1) * m == (int) unde[x].size());
        for (int it = 0; it < cntff; it++) {
          indici[ff].push_back(unde[x][it]);
        }
        for (int it = 0; it < cntss; it++) {
          indici[ss].push_back(unde[x][(int) unde[x].size() - 1 - it]);
        }
      }
    }
    int sol = 0;
    for (int i = 0; i < n; i++) {
      sort(indici[i].begin(), indici[i].end());
      for (int k1 = 0; k1 < (int) indici[i].size(); k1++) {
        for (int k2 = k1 + 1; k2 < (int) indici[i].size(); k2++) {
          sol += (a[indici[i][k1]] < a[indici[i][k2]]);
        }
      }
    }

    cout << sol << "\n";
  }

  return 0;
}