#include <bits/stdc++.h>

using namespace std;

const int N = 600 + 7;
const int INF = (int) 1e9 + (int) 1e5;
int n, m, Edge[N][N], dist[N];
bool done[N];

int calc(int a, int b, int t) {
  t %= n;
  b -= t;
  b %= n;
  if (b < 0) {
    b += n;
  }
  return Edge[a][b];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      Edge[i][j] = INF;
    }
  }

  for (int j = 0; j < m; j++) {
    int x, y, z;
    cin >> x >> y >> z;
    Edge[x][y] = z;
  }

  for (int go = 0; go < n; go++) {
    for (int i = 0; i < n; i++) {
      dist[i] = Edge[go][i];
      done[i] = 0;
    }

    while (1) {
      int node = -1;
      for (int i = 0; i < n; i++) {
        if (!done[i]) {
          if (node == -1 || dist[i] < dist[node]) {
            node = i;
          }
        }
      }
      if (node == -1) break;
      done[node] = 1;
      for (int i = 0; i < n; i++) {
        if (!done[i]) {
          dist[i] = min(dist[i], dist[node] + calc(node, i, dist[node]));
        }
      }
      for (int jump = 1; jump < n; jump++) {
        int j = (node + jump) % n;
        if (!done[j]) {
          dist[j] = min(dist[j], dist[node] + jump);
        }
      }
    }

    dist[go] = 0;
    for (int j = 0; j < n; j++) {
      cout << dist[j] << " ";
    }
    cout << "\n";
  }

  return 0;
}