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
vector<int> g[222];
int cnk[555][555];
 
int dd[222][222];
 
int q1, q2; 
 
int dist(int v, int need, int le = 0, int p = -1) {
  if (v == need) return le;
  for (int to : g[v]) if (to != p) {
    int now = dist(to ,need, le + 1, v);
    if (now != -1) return now;
  }
  return -1;
}
 
int solve(int w1, int w2) {
  int now = 0;
  int st = bp(2, mod - 2);
  for (int v = 0; v < n; ++v) {
    q1 = dd[v][w1];
    q2 = dd[v][w2];
    // dfs(v, w1, w2);
    // cout << w1 << ' ' << w2 << ' ' << v << ' ' << q1 << ' ' << q2 << endl;
    if (dd[w1][w2] == q1 + q2 - 2 * dd[w2][v]) {
      add(now, 1);
    } else if (dd[w1][w2] == q1 + q2 - 2 * dd[w1][v]) {
    } else {
      int res = 0;
      int d = dd[w1][w2];
      while (q1 + q2 > d) q1--, q2--;
 
      int kek = bp(st, q2);
 
      for (int i = 0; i < q1; ++i) {
        add(res, mult(cnk[i + q2 - 1][i], kek));
        kek = mult(kek, st);
      }
 
   //   cout << "=====" << res << endl;
 
      add(now, res);
 
    }
  }
 
 // cout << now << endl;
 // cout << w1 + 1 << ' ' << w2 + 1 << ' ' << mult(now, bp(n, mod - 2)) << endl;
 
  return mult(now, bp(n, mod - 2));
}
 
int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  for (int i = 0; i < 555; ++i) {
    cnk[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      add(cnk[i][j], cnk[i - 1][j]);
      add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }
 
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int w1, w2;
    cin >> w1 >> w2; --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }
 
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dd[i][j] = dist(i, j);
 
  int ans = 0;
 
  for (int w1 = 0; w1 < n; ++w1) for (int w2 = w1 + 1; w2 < n; ++w2) {
    add(ans, solve(w1, w2));
  }
 
 
  cout << ans;
}