#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;

const int N = 200000 + 7;
const int INF = (int) 1e18;
int n, cost[N], independent[N], dependent[N], leafs;
bool take[N];
vector<int> g[N];

void dfs(int a, int p = -1) {
  ///cout << " = " << a << "\n";
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
      dfs(b, a);
    }
  }
  if (kids.empty()) {
    dependent[a] = 0;
    independent[a] = cost[a];
    return;
  }
  independent[a] = 0;
  for (auto &b : kids) {
    independent[a] += independent[b];
  }
  for (auto &b : kids) {
    dependent[a] = min(dependent[a], independent[a] - independent[b] + dependent[b]);
  }
  independent[a] = min(independent[a], dependent[a] + cost[a]);
}

void get_dependent(int a, int p);
void get_independent(int a, int p);

bool d1[N];
bool d2[N];

void get_dependent(int a, int p = -1) {
  if (d1[a]) return;
  d1[a] = 1;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
    }
  }
  if (kids.empty()) {
    return;
  }
  int sum = 0;
  for (auto &b : kids) {
    sum += independent[b];
  }
  int sumo = 0;
  for (auto &b : kids) {
    if (dependent[a] == sum - independent[b] + dependent[b]) {
      get_dependent(b, a);
      sumo++;
      if (sumo >= 3) continue;
      for (auto &c : kids) {
        if (b != c) {
          get_independent(c, a);
        }
      }
    }
  }
}

void get_independent(int a, int p = -1) {
  if (d2[a]) return;
  d2[a] = 1;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
    }
  }
  if (kids.empty()) {
    take[a] = 1;
    return;
  }
  int sum = 0;
  for (auto &b : kids) {
    sum += independent[b];
  }
  if (sum == independent[a]) {
    for (auto &b : kids) {
      get_independent(b, a);
    }
  }
  if (independent[a] == dependent[a] + cost[a]) {
    take[a] = 1;
    get_dependent(a, p);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
    dependent[i] = independent[i] = INF;
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  get_independent(1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += take[i];
  }
  cout << independent[1] << " " << cnt << "\n";
  for (int i = 1; i <= n; i++) {
    if (take[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}