#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

bool home = 1;

const int N = (int) 2e5 + 7;
const int INF = (int) 1e18;
int n;
vector<int> g[N];
int combo[N];
int dp[N];
int sumofdps[N][2];

void dfs(int a) {

  /// inainte fac fara a
  sumofdps[a][1] = -INF;
  for (auto &b : g[a]) {
    dfs(b);
    int n0, n1;
    n0 = max(sumofdps[a][0] + sumofdps[b][0], sumofdps[a][1] + sumofdps[b][1]);
    n1 = max(sumofdps[a][0] + sumofdps[b][1], sumofdps[a][1] + sumofdps[b][0]);
    sumofdps[a][0] = n0;
    sumofdps[a][1] = n1;


  }

  dp[a] = sumofdps[a][0] + combo[a];

  /// dupa adauc si nodul a in ecuatie

  sumofdps[a][1] = max(sumofdps[a][1], dp[a]);
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p >> combo[i];
    if (i > 1) {
      g[p].push_back(i);
    }
  }
  dfs(1);
  /**cout << dp[4] << "\n";
  cout << dp[2] << "\n";
  ///return 0;
  for (int i = 1; i < n; i++) {
    for (auto &j : g[i]) {
      cout << i << "(" << combo[i] << ") " << j << "(" << combo[j] << ")\n";
    }
  }**/
  cout << max(sumofdps[1][0], sumofdps[1][1]) << "\n";

  return 0;
}
/**



**/