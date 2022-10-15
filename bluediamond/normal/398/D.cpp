#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
int m;
int q;
vector<vector<int>> op;
/// 1 = online
/// 2 = offline
/// 3 = add
/// 4 = del
/// 5 = count

void brute() {
  q = (int) op.size();
  vector<int> deg(n + 1, 0);
  vector<bool> is_heavy(n + 1, 0);
  int r = sqrt(q);
  for (auto &vec : op) {
    if (vec[0] == 3) {
      deg[vec[1]]++;
      deg[vec[2]]++;
    }
    if (vec[0] == 4) {
      deg[vec[1]]--;
      deg[vec[2]]--;
    }
    if (vec[0] == 5 && deg[vec[1]] >= r) {
      is_heavy[vec[1]] = 1;
    }
  }
  vector<int> heavy_nodes;
  vector<bool> online(n + 1);
  vector<unordered_set<int>> f(n + 1);
  vector<int> sol(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (is_heavy[i]) {
      heavy_nodes.push_back(i);
    }
  }
  for (auto &vec : op) {
    if (vec[0] == 1) {
      online[vec[1]] = 1;
      for (auto &node : heavy_nodes) {
        if (f[node].count(vec[1])) {
          sol[node]++;
        }
      }
      continue;
    }
    if (vec[0] == 2) {
      online[vec[1]] = 0;
      for (auto &node : heavy_nodes) {
        if (f[node].count(vec[1])) {
          sol[node]--;
        }
      }
      continue;
    }
    if (vec[0] == 3) {
      f[vec[1]].insert(vec[2]);
      f[vec[2]].insert(vec[1]);
      sol[vec[1]] += (is_heavy[vec[1]] && online[vec[2]]);
      sol[vec[2]] += (is_heavy[vec[2]] && online[vec[1]]);
    }
    if (vec[0] == 4) {
      sol[vec[1]] -= (is_heavy[vec[1]] && online[vec[2]]);
      sol[vec[2]] -= (is_heavy[vec[2]] && online[vec[1]]);
      f[vec[1]].erase(vec[2]);
      f[vec[2]].erase(vec[1]);
    }
    if (vec[0] == 5) {
      if (is_heavy[vec[1]]) {
        cout << sol[vec[1]] << "\n";
        continue;
      }
      int ret = 0;
      for (auto &y : f[vec[1]]) {
        ret += online[y];
      }
      cout << ret << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> q;
  int o;
  cin >> o;
  for (int i = 1; i <= o; i++) {
    int x;
    cin >> x;
    op.push_back({1, x});
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    op.push_back({3, x, y});
  }
  for (int i = 1; i <= q; i++) {
    string s;
    cin >> s;
    if (s == "O") {
      int x;
      cin >> x;
      op.push_back({1, x});
    }
    if (s == "F") {
      int x;
      cin >> x;
      op.push_back({2, x});
    }
    if (s == "A") {
      int x, y;
      cin >> x >> y;
      op.push_back({3, x, y});
    }
    if (s == "D") {
      int x, y;
      cin >> x >> y;
      op.push_back({4, x, y});
    }
    if (s == "C") {
      int x;
      cin >> x;
      op.push_back({5, x});
    }
  }
  brute();
}