#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << ' = ' << (a) << endl; 

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
int was[200007];
vector<pair<int, int>> ed;
vector<pair<int, int>> g[200007];
int f[222];
int fib[200007];

int w[200007];

void dfs(int v, int p = -1) {
  w[v] = 1;
  for (auto [to, num] : g[v]) if (!was[num] && to != p) {
    dfs(to, v);
    w[v] += w[to];
  }
}

int findd(int v, int tot, int p = -1) {
  for (auto [to, num] : g[v]) if (!was[num] && to != p) {
    if (fib[w[to]] && fib[tot - w[to]]) return num;
    int now = findd(to, tot, v); 
    if (now != -1) return now;
  }
  return -1;
}

bool check(int v) {
  dfs(v);
  if (!fib[w[v]]) return 0;

  if (w[v] == 1) return 1;

  int ww = findd(v, w[v]);

  if (ww == -1) return 0;
  was[ww] = 1;
  return check(ed[ww].x) && check(ed[ww].y);
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n -1 ; ++i) {
    int w1, w2;
    cin >> w1 >> w2; --w1; --w2;
    ed.pb(mp(w1, w2));
    g[w1].pb(mp(w2, i)); g[w2].pb(mp(w1, i));
  }

  f[0] = f[1] = 1; fib[1] = 1;
  for (int i = 2; i < 40; ++i) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] <= n) fib[f[i]] = 1;
  }

  if (check(0)) cout << "YES\n"; else cout << "NO\n";
}