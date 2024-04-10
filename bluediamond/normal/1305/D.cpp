#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n;
bool act[N];
vector<int> g[N];
int dist[N];

void dfs(int a) {
  for (auto &b : g[a]) {
    if (act[b] && dist[b] == -1) {
      dist[b] = 1 + dist[a];
      dfs(b);
    }
  }
}

int fd(int a) {
  for (int i = 1; i <= n; i++) {
    dist[i] = -1;
  }
  dist[a] = 0;
  dfs(a);
  int b = a;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[b]) {
      b = i;
    }
  }
  return b;
}

int root;
int urm[N][N];

void build(int a, int p) {
  urm[a][root] = p;
  for (auto &b : g[a]) {
    if (b != p) {
      build(b, a);
    }
  }
}

void block(int a, int p) {
  act[a] = 0;
  for (auto &b : g[a]) {
    if (b != p && act[b]) {
      block(b, a);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    root = i;
    build(i, -1);
  }
  for (int i = 1; i <= n; i++) {
    act[i] = 1;
  }
  for (int it = 1; it <= n / 2; it++) {
    int who_ac = 0, cnt_ac = 0;
    for (int i = 1; i <= n; i++) {
      if (act[i]) {
        who_ac = i;
        cnt_ac++;
      }
    }
    if (cnt_ac == 1) {
      break;
    }
    int a = fd(who_ac);
    int b = fd(a);
    cout << "? " << a << " " << b << endl;
    int c;
    cin >> c;
    if (c != a) {
      block(urm[c][a], c);
    }
    if (c != b) {
      block(urm[c][b], c);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (act[i]) {
      cout << "! " << i << endl;
      return 0;
    }
  }
}