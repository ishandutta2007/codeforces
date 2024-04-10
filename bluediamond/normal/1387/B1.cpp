#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n, sol[N], cost;
vector<int> g[N];
bool vis[N];
bool vec[N];

bool dfs(int a) {
  vis[a] = 1;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (vis[b] == 0) {
      bool ok = dfs(b);
      if (ok) {
        kids.push_back(b);
      }
    }
  }
  int sz = (int) kids.size();
  if (sz % 2 == 0 && sz >= 2) {
    cost += 4;
    int x = kids[sz - 1], y = kids[sz - 2];
    sol[a] = y;
    sol[x] = a;
    sol[y] = x;
    sz -= 2;
    kids.pop_back();
    kids.pop_back();
  }
  while (sz >= 2) {
    int x = kids[sz - 1], y = kids[sz - 2];
    sol[x] = y;
    sol[y] = x;
    cost += 4;
    sz -= 2;
    kids.pop_back();
    kids.pop_back();
  }
  if (!kids.empty()) {
    cost += 2;
    sol[kids[0]] = a;
    sol[a] = kids[0];
    return 0;
  } else {
    return (sol[a] == 0);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (auto &x : g[1]) {
    vec[x] = 1;
  }
  bool ok = dfs(1);
  if (ok) {
    int who = -1;
    for (auto &b : g[1]) {
      if (vec[sol[b]]) {
        who = b;
      }
    }
    if (who != -1) {
      vector<int> elements;
      elements.push_back(1);
      elements.push_back(who);
      elements.push_back(sol[who]);
      sol[elements[0]] = elements[1];
      sol[elements[1]] = elements[2];
      sol[elements[2]] = elements[0];
    } else {
      if (sol[sol[g[1][0]]] == g[1][0]) {
        vector<int> elements;
        elements.push_back(1);
        elements.push_back(g[1][0]);
        elements.push_back(sol[g[1][0]]);
        cost += 2;
        sol[elements[0]] = elements[1];
        sol[elements[1]] = elements[2];
        sol[elements[2]] = elements[0];
      } else {
        int a = 1;
        int b = g[1][0];
        int c = sol[b];
        int d = sol[c];
        cost += 2;
        sol[a] = b;
        sol[b] = a;
        sol[c] = d;
        sol[d] = c;
      }
    }
  }
  cout << cost << "\n";
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
  return 0;
}