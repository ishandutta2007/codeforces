#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n;
vector<pair<int, int>> g[666];

int cc[606][606];

int dist[606];
int was[606];

void dij() {
  for (int i = 0; i < n; ++i) was[i] = 0;
  for (int it = 0; it < n; ++it) {
    int v = -1;
    for (int i = 0; i < n; ++i) if (!was[i]) {
      if (v == -1 || v != -1 && dist[i] < dist[v]) v = i;
    }

    int sh = dist[v] % n;

//    cout << v << ' ' << dist[v] << endl;

    for (int to = 0; to < n; ++to) {
      dist[sh] = min(dist[sh], dist[v] + cc[v][to]);
   //   cout <<"++++++" << sh << ' ' << dist[v] << ' ' << cc[v][to] << endl;
      ++sh; if (sh == n) sh = 0;
    }
    was[v] = 1;
  }
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  int m;
  cin >> m;
  while (m--) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    g[w1].pb(mp(w2, w3));
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cc[i][j] = 2e9; // cc[i][i] = 0;
    for (auto [to, cost] : g[i]) {
      int nxt = to;
      for (int s = 0; s < n; ++s) {
        cc[i][nxt] = min(cc[i][nxt], cost + s);
        nxt++;
        if (nxt == n) nxt = 0;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) dist[j] = 2e9; dist[i] = 0;

    dij();

    for (int j = 0; j < n; ++j) {
      cout << dist[j] << ' ';
    }
    cout << "\n";
  }
}