#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int ll

const int N = 20;
int n, dp[1 << N], sumpe[N]; /// care sunt inca valide
vector<int> v[N];
map<int, vector<int>> positions[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  //freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int su = 0, indi = 0;
    for (auto &ch : s) {
      int cur;
      if (ch == '(') cur = +1;
      else cur = -1;
      su += cur;
      positions[i][su].push_back(indi);
      indi++;
      v[i].push_back(cur);
    }
    sumpe[i] = su;
  }

  for (int i = 1; i < (1 << n); i++) dp[i] = -(int) 1e9;

  int sol = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<int> pot;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) {
        pot.push_back(i);
      } else {
        sum += sumpe[i];
      }
    }
    for (auto &i : pot) {
      int cnt = dp[mask], cur = 0, stop;

      bool valid = (!positions[i].count(-1 - sum));
      if (valid) {
        stop = (int) v[i].size() - 1;
      } else {
        stop = positions[i][-1 - sum][0] - 1;
      }
      if (positions[i].count(-sum)) {
        int l = 0, r = (int) positions[i][-sum].size() - 1, inside = 0;
       // cout << "aici : " << l << " and " << r << " " << positions[i][-sum][0] << " " << stop << "\n";
        while (l <= r) {
          int m = (l + r) / 2;
          if (positions[i][-sum][m] <= stop) {
            inside = m + 1;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
        cnt += inside;
      }
      sol = max(sol, cnt);

      if (valid) {
        dp[mask + (1 << i)] = max(dp[mask + (1 << i)], cnt);
      }
    }
    sol = max(sol, dp[mask]);
  }
  cout << sol << "\n";

  return 0;
}