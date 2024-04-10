#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 50 + 7;
int n, goal[N], whenWin[N], whenLose[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      goal[i] = s[i - 1] - '0';
      whenWin[i] = -1;
      whenLose[i] = -1;
    }
    vector<int> cycle;
    for (int i = 1; i <= n; i++) {
      if (goal[i] == 2) {
        cycle.push_back(i);
      }
    }
    if ((int) cycle.size() != 1 && (int) cycle.size() != 2) {
      if (!cycle.empty()) {
        cycle.push_back(cycle[0]);
        for (int i = 0; i + 1 < (int) cycle.size(); i++) {
          whenWin[cycle[i]] = cycle[i + 1];
          whenLose[cycle[i + 1]] = cycle[i];
        }
      }
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i == j) {
            cout << "X";
            continue;
          }
          if (min(goal[i], goal[j]) == 1) {
            cout << "=";
          } else {
            if (j == whenWin[i]) {
              cout << "+";
            } else {
              if (j == whenLose[i]) {
                cout << "-";
              } else {
                cout << "=";
              }
            }
          }
        }
        cout << "\n";
      }
    } else {
      cout << "NO\n";
    }
  }


}