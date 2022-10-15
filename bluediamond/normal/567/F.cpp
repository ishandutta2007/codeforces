#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 70 + 7;
int n;
int k;
ll sol;
vector<int> egal[N];
vector<int> mic[N];
vector<int> mare[N];
vector<int> mic_strict[N];
vector<int> mare_strict[N];
ll dp[N][N][N];

ll get(int l, int r, int x) {
  if (dp[l][r][x] != -1) {
    return dp[l][r][x];
  }
  bool now = (l == 1 && r == 8); ///now = 0;
  ll sol = 0;
  bool ok;
  int new_l;
  int new_r;
  int p1;
  int p2;
  /// l, r
  ok = 1;
  new_l = l + 1;
  new_r = r - 1;
  p1 = l;
  p2 = r;

  for (auto &i : egal[p1]) ok &= (i == p1 || i == p2);
  for (auto &i : egal[p2]) ok &= (i == p1 || i == p2);
  for (auto &i : mic[p1]) ok &= ((new_l <= i && i <= new_r) || (i == p1) || (i == p2));
  for (auto &i : mic[p2]) ok &= ((new_l <= i && i <= new_r)  || (i == p1) || (i == p2));
  for (auto &i : mare[p1]) ok &= ((i < l || r < i) || (i == p1) || (i == p2));
  for (auto &i : mare[p2]) ok &= ((i < l || r < i) || (i == p1) || (i == p2));
  for (auto &i : mic_strict[p1]) ok &= (new_l <= i && i <= new_r);
  for (auto &i : mic_strict[p2]) ok &= (new_l <= i && i <= new_r);
  for (auto &i : mare_strict[p1]) ok &= (i < l || r < i);
  for (auto &i : mare_strict[p2]) ok &= (i < l || r < i);


  if (l + 1 == r) {
    return ok;
  }

  if (ok) sol += get(new_l, new_r, x + 1);
  if (l + 1 == r) return sol;
  /// r - 1, r
  ok = 1;
  new_l = l;
  new_r = r - 2;
  p1 = r - 1;
  p2 = r;

  for (auto &i : egal[p1]) ok &= (i == p1 || i == p2);
  for (auto &i : egal[p2]) ok &= (i == p1 || i == p2);
  for (auto &i : mic[p1]) ok &= ((new_l <= i && i <= new_r) || (i == p1) || (i == p2));
  for (auto &i : mic[p2]) ok &= ((new_l <= i && i <= new_r)  || (i == p1) || (i == p2));
  for (auto &i : mare[p1]) ok &= ((i < l || r < i) || (i == p1) || (i == p2));
  for (auto &i : mare[p2]) ok &= ((i < l || r < i) || (i == p1) || (i == p2));
  for (auto &i : mic_strict[p1]) ok &= (new_l <= i && i <= new_r);
  for (auto &i : mic_strict[p2]) ok &= (new_l <= i && i <= new_r);
  for (auto &i : mare_strict[p1]) ok &= (i < l || r < i);
  for (auto &i : mare_strict[p2]) ok &= (i < l || r < i);

  if (ok) sol += get(new_l, new_r, x + 1);
  /// l, l + 1
  ok = 1;
  new_l = l + 2;
  new_r = r;
  p1 = l;
  p2 = l + 1;

  for (auto &i : egal[p1]) ok &= (i == p1 || i == p2);
  for (auto &i : egal[p2]) ok &= (i == p1 || i == p2);
  for (auto &i : mic[p1]) ok &= ((new_l <= i && i <= new_r) || (i == p1) || (i == p2));
  for (auto &i : mic[p2]) ok &= ((new_l <= i && i <= new_r)  || (i == p1) || (i == p2));
  for (auto &i : mare[p1]) ok &= ((i < l || r < i) || (i == p1) || (i == p2));
  for (auto &i : mare[p2]) ok &= ((i < l || r < i) || (i == p1) || (i == p2));
  for (auto &i : mic_strict[p1]) ok &= (new_l <= i && i <= new_r);
  for (auto &i : mic_strict[p2]) ok &= (new_l <= i && i <= new_r);
  for (auto &i : mare_strict[p1]) ok &= (i < l || r < i);
  for (auto &i : mare_strict[p2]) ok &= (i < l || r < i);


  if (ok) sol += get(new_l, new_r, x + 1);
  dp[l][r][x] = sol;
  return sol;
}

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);


  memset(dp, -1, sizeof(dp));

  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int x, y;
    string s;
    cin >> x >> s >> y;
    if (s == "=") {
      egal[x].push_back(y);
      egal[y].push_back(x);
      continue;
    }
    if (s == "<") {
      swap(x, y);
      s = ">";
    }
    if (s == ">") {
      mare_strict[x].push_back(y);
      mic_strict[y].push_back(x);
      continue;
    }
    if (s == "<=") {
      swap(x, y);
      s = ">=";
    }
    if (s == ">=") {
      mare[x].push_back(y);
      mic[y].push_back(x);
      continue;
    }
    assert(0);
  }
  cout << get(1, 2 * n, 1) << "\n";
}