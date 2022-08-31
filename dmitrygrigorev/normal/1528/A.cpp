#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;
vector<int> l, r;

pair<ll, ll> dfs(int vertex, int last) {

  ll A = 0, B = 0;
  for (auto x : gr[vertex]) {
    if (x == last) continue;
    auto p = dfs(x, vertex);

    A += max(p.x + abs(l[x] - l[vertex]), p.y + abs(r[x] - l[vertex]));
    B += max(p.x + abs(l[x] - r[vertex]), p.y + abs(r[x] - r[vertex]));

  }

  return mp(A, B);

}

void solve() {

  int n;
  cin >> n;

  gr.assign(n, {});
  l.assign(n, -1);
  r.assign(n, -1);

  for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    gr[u].pb(v);
    gr[v].pb(u);
  }

  pair<ll, ll> res = dfs(0, -1);
  cout << max(res.x, res.y) << '\n';

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}