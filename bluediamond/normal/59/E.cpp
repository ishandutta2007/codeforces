#include <bits/stdc++.h>

using namespace std;

const int N = 3000 + 7;
const int INF = (int) 1e9;
int best[N][N];
pair<int, int> pap[N][N];

struct T {
  int a, b, c;
};

bool operator < (T f, T s) {
  if (f.a != s.a) return f.a < s.a;
  if (f.b != s.b) return f.b < s.b;
  return f.c < s.c;
}

int n, m, k;
vector<int> g[N];
set<T> so;

bool ok(int a, int b, int c) {
  return !so.count({a, b, c});
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    so.insert({a, b, c});
  }
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) best[i][j] = -1;
  queue<pair<int, int>> q;
  for (auto &j : g[1]) best[1][j] = 1, q.push({1, j});
  while (!q.empty()) {
    int a = q.front().first;
    int b = q.front().second;
    q.pop();
    for (auto &c : g[b]) {
      if (best[b][c] == -1 && ok(a, b, c)) {
        best[b][c] = 1 + best[a][b];
        q.push({b, c});
        pap[b][c] = {a, b};
      }
    }
  }
  int sol = INF, no, fofo = 0;
  for (auto &it : g[n]) {
    if (best[it][n] != -1) {
      fofo++;
      sol = min(sol, best[it][n]);
      if (sol == best[it][n]) no = it;
    }
  }
  if (!fofo) {
    cout << "-1\n";
    return 0;
  }
  cout << sol << "\n";
  int a = no, b = n;
  vector<int> oo = {b, a};
  while (a != 1) {
    pair<int, int> it = pap[a][b];
    a = it.first;
    b = it.second;
    oo.push_back(a);
  }
  reverse(oo.begin(), oo.end());
  for (auto &x : oo) cout << x << " ";
  cout << "\n";
}