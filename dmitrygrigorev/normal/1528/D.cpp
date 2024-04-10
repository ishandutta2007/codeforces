#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 607;

int opt[N][N];
int gun[N][N];
const int INF = 2e9;

ll ans[N][N];

int n;

void dijkstra(int vertex) {
  vector<ll> d(n, 1e18);

  d[vertex] = 0;
  vector<bool> used(n, false);

  for (int i = 0; i < n; ++i) {
    ll best = 1e18;
    int wh = -1;

    for (int j = 0; j < n; ++j) {
      if (used[j]) continue;
      if (d[j] < best) {
        best = d[j];
        wh = j;
      }
    }

    used[wh] = true;
    for (int j = 0; j < n; ++j) {
      if (used[j]) continue;
      int rem = d[wh] % n;

      int rs = j - rem;
      if (rs < 0) rs += n;

      d[j] = min(d[j], d[wh] + opt[wh][rs]);
    }

  }

  for (int i = 0; i < n; ++i) ans[vertex][i] = d[i];

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      opt[i][j] = INF;
      gun[i][j] = INF;
    }
  }

  int m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    gun[a][b] = c;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (gun[i][k] == INF) continue;
        int wait = j - k;
        if (wait < 0) wait += n;

        opt[i][j] = min(opt[i][j], wait + gun[i][k]);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    dijkstra(i);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << ans[i][j] << " ";
    cout << '\n';
  }



  

}