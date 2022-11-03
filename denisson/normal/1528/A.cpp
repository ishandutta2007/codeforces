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
vector<int> g[100007];
ll l[100007];
ll r[100007];

ll dp[100007][2];

void dfs(int v, int p = -1) {
  dp[v][0] = dp[v][1] = 0;
  for (int to : g[v]) if (to != p) {
    dfs(to, v);
    dp[v][0] += max(dp[to][0] + abs(l[to] - l[v]), dp[to][1] + abs(r[to] - l[v]));
    dp[v][1] += max(dp[to][0] + abs(l[to] - r[v]), dp[to][1] + abs(r[to] - r[v])); 
  }
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt; cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i], g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int w1, w2;
      cin >> w1 >> w2;
      --w1; --w2;
      g[w1].pb(w2); g[w2].pb(w1);
    }
    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << "\n";
  }
}