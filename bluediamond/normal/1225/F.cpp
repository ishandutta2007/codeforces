#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

int realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
int n, p[N], dep[N], vertex, kids[N];
vector<int> g[N], sol;
set<int> nodes[N];

pair<int, int> add(pair<int, int> a) {
  return {a.first + 1, a.second};
}

pair<int, int> fnd(int a) {
  if (g[a].empty()) {
    return {1, a};
  }
  pair<int, int> ret = {1, a};
  for (auto &b : g[a]) {
    ret = max(ret, add(fnd(b)));
  }
  return ret;
}

void algo() {
  if (!vertex) {
    return;
  }
  if (kids[p[vertex]] == 1) {
    vertex = p[vertex];
    algo();
    return;
  }
  auto it = nodes[p[vertex]].begin();
  if (*it == vertex) {
    it++;
  }
  assert(*it != vertex);
  sol.push_back(vertex);
  int initp = p[vertex];
  p[vertex] = *it;
  nodes[initp].erase(vertex), kids[initp]--;
  nodes[p[vertex]].insert(vertex), kids[p[vertex]]++;
  algo();
}

int realMain() {
  cin >> n;
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    kids[p[i]]++;
    nodes[p[i]].insert(i);
    g[p[i]].push_back(i);
  }
  int remember = fnd(0).second;
  vertex = remember;
  algo();
  vector<int> ord;
  while (remember) {
    ord.push_back(remember);
    remember = p[remember];
  }
  ord.push_back(0);
  reverse(ord.begin(), ord.end());
  for (auto &i : ord) {
    cout << i << " ";
  }
  cout << "\n";
  cout << (int) sol.size() << "\n";
  reverse(sol.begin(), sol.end());
  for (auto &i : sol) {
    cout << i << " ";
  }
  cout << "\n";
}