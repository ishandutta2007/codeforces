#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 7;
int n, firstPar[N], l[N], r[N], aib[N], top, sol;

vector<int> g[N];

void build(int a) {
  l[a] = ++top;
  for (auto &b : g[a]) {
    build(b);
  }
  r[a] = top;
}

struct Info {
  vector<int> insAct;
  vector<int> insInact;
  vector<int> delAct;
  vector<int> delInact;
};

vector<Info> history;

set<pair<int, int>> activeNodes;
set<pair<int, int>> inactiveNodes;

void addNode(int a) {
  history.push_back({});
  auto it = activeNodes.lower_bound({l[a], 0});
  bool anythingUnderneath;
  if (it == activeNodes.end()) {
    anythingUnderneath = 0;
  } else {
    anythingUnderneath = (it->first <= r[a]);
  }
  if (anythingUnderneath) {
    inactiveNodes.insert({l[a], a});
    history.back().insInact.push_back(a);
    return;
  }
  int anc = -1;
  if (it != activeNodes.begin()) {
    it--;
    anc = it->second;
    bool good = (l[anc] <= l[a] && l[a] <= r[anc]);
    if (!good) {
      anc = -1;
    }
  }
  if (anc != -1) {
    activeNodes.erase({l[anc], anc});
    inactiveNodes.insert({l[anc], anc});

    history.back().delAct.push_back(anc);
    history.back().insInact.push_back(anc);
  }
  activeNodes.insert({l[a], a});
  history.back().insAct.push_back(a);
  /// find the ancestor which we are potentially deleting
}

void rollBack() {
  assert(!history.empty());
  for (auto &a : history.back().insAct) activeNodes.erase({l[a], a});
  for (auto &a : history.back().insInact) inactiveNodes.erase({l[a], a});

  for (auto &a : history.back().delAct) activeNodes.insert({l[a], a});
  for (auto &a : history.back().delInact) inactiveNodes.insert({l[a], a});
  history.pop_back();
}

void dfs(int a) {
  addNode(a);
  sol = max(sol, (int) activeNodes.size());

  for (auto &b : g[a]) {
    dfs(b);
  }

  rollBack();
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    cin >> n;
    activeNodes.clear();
    inactiveNodes.clear();
    history.clear();
    sol = 0;
    top = 0;
    for (int i = 1; i <= n; i++) g[i].clear(), aib[i] = 0;
    for (int i = 2; i <= n; i++) cin >> firstPar[i];
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      g[p].push_back(i);
    }
    build(1);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2; i <= n; i++) g[firstPar[i]].push_back(i);
    dfs(1);
    cout << sol << "\n";
  }
  return 0;
}