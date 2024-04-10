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

vector<vector<int> > gr;
vector<bool> used;
vector<int> path;

bool dfs(int vertex, int last, int finish) {

  if (vertex == finish) {
    used[vertex] = true;
    path.pb(vertex);
    return true;
  }

  for (auto to : gr[vertex]) {
    if (to == last) continue;
    bool R = dfs(to, vertex, finish);
    if (R) {
      used[vertex] = true;
      path.pb(vertex);
      return true;
    }
  }

  return false;

}

int S;

void dfs2(int vertex, int last) {
  S++;

  for (auto to : gr[vertex]) {
    if (used[to] || to == last) continue;
    dfs2(to, vertex);
  }

}

const int N = 207;
int dp[N][N];

void precalc() {

  for (int i = 0; i < N; ++i) {
    dp[0][i] = 1;
    dp[i][0] = 0;
  }

  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      add(dp[i][j], dp[i-1][j]);
      add(dp[i][j], dp[i][j-1]);

      dp[i][j] = mult(dp[i][j], (mod+1)/2);

    }
  }

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  precalc();

  int n;
  cin >> n;

  gr.assign(n, {});
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    gr[a].pb(b), gr[b].pb(a);
  }

  int ans = 0;
  int Q = bp(n, mod-2);

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      used.assign(n, false);
      path.clear();
      dfs(i, -1, j);

      for (int k = 0; k < path.size(); ++k) {
        S = 0;
        dfs2(path[k], -1);

        int A = k;
        int B = path.size() - 1 - k;

        add(ans, mult(mult(S, Q), dp[A][B]));

      }

    }
  }

  cout << ans;

}