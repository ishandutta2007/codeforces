#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld dv(ld a, ld b) {
  return a / b;
}

ld mul(ld a, ld b) {
  return a * b;
}


ld mul(ld a, ld b, ld c) {
  return a * b * c;
}

ld mul(ld a, ld b, ld c, ld d) {
  return a * b * c * d;
}

ld add(ld a, ld b) {
  return a + b;
}

ld add(ld a, ld b, ld c) {
  return a + b + c;
}

ld add(ld a, ld b, ld c, ld d) {
  return a + b + c + d;
}

void addup(ld &a, ld b) {
  a = add(a, b);
}

void maxup(ld &a, ld b) {
  a = max(a, b);
}

const int N = 400 + 7;
const int INF = (int) 1e9;
int n, m, dist[N][N], maxd[N];
vector<int> g[N], la[N][N];

ld p[N], lac[N];
bool seen[N];

ld secondDay(int c1, int d1) {
  vector<int> nodes;
  for (auto &n1 : la[c1][d1]) {
    for (auto &n2 : g[n1]) {
      addup(p[n2], dv(1, mul(n, g[n1].size())));
      if (!seen[n2]) {
        seen[n2] = 1;
        nodes.push_back(n2);
      }
    }
  }


  ld sol = 0;
  for (int c2 = 1; c2 <= n; c2++) {
    ld cur = 0;
    for (auto &b : nodes) {
      maxup(lac[dist[c2][b]], p[b]);
    }
    for (auto &b : nodes) {
      cur += lac[dist[c2][b]];
      lac[dist[c2][b]] = 0;
    }
    maxup(sol, cur);
  }

  for (auto &n2 : nodes) {
    seen[n2] = 0;
    p[n2] = 0;
  }

  return sol;
}

int main() {
  //ios::sync_with_stdio(0); cin.tie(0);
//  freopen ("input", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = INF;
    }
    dist[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    dist[a][b] = dist[b][a] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      maxd[i] = max(maxd[i], dist[i][j]);
      la[i][dist[i][j]].push_back(j);
    }
  }

  ld sol = 0;

  for (int c1 = 1; c1 <= n; c1++) {
    ld cur = 0;
    for (int d1 = 0; d1 <= maxd[c1]; d1++) {
      addup(cur, max(dv(1, n), secondDay(c1, d1)));
    }
    maxup(sol, cur);
  }

  cout << sol << "\n";



  return 0;
}