#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
vector<pair<int, string>> sol;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  int formula = 2 * n * (m - 1) + 2 * m * (n - 1);
  if (formula < k) {
    cout << "NO\n";
    return 0;
  } else {
    cout << "YES\n";
  }
  if (m > 1) {
    sol.push_back({m - 1, "R"});
    sol.push_back({m - 1, "L"});
  }
  for (int i = 2; i <= n; i++) {
    sol.push_back({1, "D"});
    if (m > 1) {
      sol.push_back({m - 1, "RUD"});
      sol.push_back({m - 1, "L"});
    }
  }
  if (n > 1) {
    sol.push_back({n - 1, "U"});
  }
  int sum = 0;
  vector<pair<int, string>> print;
  for (auto &it : sol) {
    if (sum + it.first * (int) it.second.size() <= k) {
      print.push_back(it);
      sum += it.first * (int) it.second.size();
    } else {
      int need = k - sum;
      int full = need / (int) it.second.size();
      if (full) {
        print.push_back({full, it.second});
      }
      need %= (int) it.second.size();
      for (auto &ch : it.second) {
        if (need == 0) {
          break;
        }
        string lol;
        lol += ch;
        print.push_back({1, lol});
        need--;
      }
      break;
    }
  }
  cout << (int) print.size() << "\n";
  for (auto &it : print) {
    cout << it.first << " " << it.second << "\n";
  }
}