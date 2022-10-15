#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

signed realMain();

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

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = (int) 2e3 + 7;
int dp[N][2 * N][2];
int n, m;
bool vis[N];
vector<int> g[N];
map<int, int> cnt;

vector<int> cycles;
int ultimul;

int get(int pos, int delta, int tot) {
  if (pos == (int) cycles.size()) {
    if (tot) {
      if (ultimul == 0) return delta == 0;
      return delta == ultimul - 1;
    } else {
      return delta < ultimul - 1;
    }
  }
  if (dp[pos][delta][tot] != -1) return dp[pos][delta][tot];
  dp[pos][delta][tot] = 0;
  dp[pos][delta][tot] = add(dp[pos][delta][tot], get(pos + 1, delta + cycles[pos], tot));
  dp[pos][delta][tot] = add(dp[pos][delta][tot], get(pos + 1, abs(delta - cycles[pos]), tot));
  if (!tot) {
    dp[pos][delta][tot] = add(dp[pos][delta][tot], get(pos + 1, delta, tot));
  }
  return dp[pos][delta][tot];
}

int calc(int lungime, int neaparat) {
  memset(dp, -1, sizeof(dp));
  cnt[lungime]--;
  cycles.clear();
  for (auto &it : cnt) {
    for (int j = 1; j <= it.second; j++) {
      cycles.push_back(it.first);
    }
  }
  cnt[lungime]++;
  ultimul = lungime;
  int ret = get(0, 0, 1);
  if (!neaparat) {
    ret = add(ret, get(0, 0, 0));
  }
  return ret;
}

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (auto &i : g[1]) {
    if (vis[i]) continue;
    if (g[i][0] == g[i][1]) {
      vis[i] = 1;
      cnt[2]++;
      continue;
    }
    int len = 0, j = i, last = 1;
    while (j != 1) {
      len++;
      vis[j] = 1;
      int new_j = g[j][0] ^ g[j][1] ^ last;
      last = j;
      j = new_j;
    }
    len++;
    cnt[len]++;
  }
  if (home) {
    for (auto &it : cnt) {
      for (int j = 1; j <= it.second; j++) {
        cout << " -> " << it.first << "\n";
      }
    }
  }
  int ret = 0;
  for (auto &it : cnt) {
    ret = add(ret, mul(2, mul(it.second, calc(it.first, 0))));
  }
  ret = add(ret, calc(0, 1));
  cout << ret << "\n";
  return 0;
}