#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

int matrix[1007][507];
bool used[507][507];
int cnt[507][507];
bool is_edge[1007][1007];

int n;
vector<int> color;
vector<bool> chosen;

void kill(int x, bool K) {
  for (int j = 0; j < n; ++j) {
    cnt[matrix[x][j]][j]--;
    if (K) used[matrix[x][j]][j] = true;
  }
}

void dfs(int vertex, int c) {
  color[vertex] = c;

  for (int i = 0; i < 2*n; ++i) {
    if (!is_edge[vertex][i] || color[i] != -1 || chosen[i]) continue;
    dfs(i, 1-c);
  }

}

void solve() {

  cin >> n;

  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    used[i][j] = false;
    cnt[i][j] = 0;
  }

  for (int i = 0; i < 2*n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
      matrix[i][j]--;
      cnt[matrix[i][j]][j]++;
    }
  }

  for (int i = 0; i < 2*n; ++i) for (int j = 0; j < 2*n; ++j) {
    is_edge[i][j] = false;
    for (int k = 0; k < n; ++k) if (matrix[i][k] == matrix[j][k]) {
      is_edge[i][j] = true;
      break;
    }
  }

  chosen.assign(2*n, false);
  vector<int> ans;

  for (int i = 0; i < n; ++i) {

    pair<int, int> spec = mp(-1, -1);
    for (int j = 0; j < n; ++j) for (int k = 0; k < n ; ++k) {
      if (!used[j][k] && cnt[j][k] <= 1) spec = mp(j, k);
    }

   // cout << spec.x << " " << spec.y << endl;

    if (spec == mp(-1, -1)) break;
    int W = -1;
    for (int j = 0; j < 2*n; ++j) {
      if (!chosen[j] && matrix[j][spec.y] == spec.x) {
        W = j;
        break;
      }
    }

    chosen[W] = true;
    ans.pb(W);
    kill(W, true);

    for (int j = 0; j < 2*n; ++j) if (!chosen[j] && is_edge[j][W]) {
      chosen[j] = true;
      kill(j, false);
    }

  }

  int res = 1;
  color.assign(2*n, -1);

  for (int i = 0; i < 2*n; ++i) {
    if (color[i] != -1 || chosen[i]) continue;
    res *= 2;
    res %= mod;
    dfs(i, 0);
  }

  cout << res << '\n';
  for (int i = 0; i < 2*n; ++i) if (color[i] == 0) ans.pb(i);
  sort(all(ans));

  for (auto x : ans) cout << x+1 << " ";
  cout << '\n';

  



}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}