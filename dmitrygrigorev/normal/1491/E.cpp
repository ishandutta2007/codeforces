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

vector<bool> used;

vector<vector<pair<int, int> > > gr;
set<int> fib;

vector<int> sz;

int A, B, F, S, E;

void dfs2(int vertex, int last, int ed) {
  sz[vertex] = 1;
  for (auto p : gr[vertex]) {
    if (used[p.y]) continue;
    if (p.x == last) continue;
    dfs2(p.x, vertex, p.y);
    sz[vertex] += sz[p.x];
  }

  if (sz[vertex] == F) {
    A = vertex, B = last, E = ed;
  }
  else if (sz[vertex] == S) {
    A = last, B = vertex, E = ed;
  }

}

void dfs(int vertex, int cnt) {
  if (cnt <= 3) {
    return;
  }

  auto it = fib.lower_bound(cnt);
  it--;

  int need = (*it);
  A = -1, B = -1, E = -1, F = need, S = cnt - need;
  dfs2(vertex, -1, -1);

  if (A == -1) {
    cout << "NO";
    exit(0);
  }

  used[E] = true;
  int ca = A, cb = B;

  dfs(ca, need);
  dfs(cb, cnt - need); 



}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  gr.assign(n, {});

  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u-1].pb(mp(v-1, i));
    gr[v-1].pb(mp(u-1, i));
  }

  fib.insert(1);
  int a = 1, b = 1;
  while (true) {
    a += b;
    swap(a, b);
    fib.insert(b);
    if (b > 1e6) break;
  }

  if (!fib.count(n)) {
    cout << "NO\n";
    exit(0);
  }

  used.assign(n, false);
  sz.assign(n, 0);
  dfs(0, n);

  cout << "YES\n";



}