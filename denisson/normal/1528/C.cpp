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
vector<int> g1[300007];
vector<int> g2[300007];

int tin[300007];
int tout[300007];

int tt;
void dfs1(int v) { 
  tin[v] = tt++;
  for (int to : g2[v]) dfs1(to);
  tout[v] = tt++;
}

set<pair<int, int> > se;
int ans;

void dfs(int v) {
  auto it = se.upper_bound(mp(tout[v], tin[v]));
  int need = 0;
  pair<int, int> kek;
  if (it != se.end()) {
    kek = *it;
    if (kek.y <= tin[v]) {
      need = 1;
      se.erase(it);
    }
  }
  se.insert(mp(tout[v], tin[v]));

  ans = max(ans, (int)se.size());

 // cout << v + 1 << ' ' << se.size() << endl;

  //cout << "===\n";
  //for (auto [w1, w2] : se) cout << w1 << ' ' << w2 << endl;
  //  cout << endl;

  for (int to : g1[v]) {
    dfs(to);
  }

  se.erase(mp(tout[v], tin[v]));
  if (need) {
    se.insert(kek);
  }
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int ttt;
  cin >> ttt;
  while (ttt--) {
    cin >> n; for (int i = 0; i < n; ++i) g1[i].clear(), g2[i].clear();
    for (int i = 2; i <= n; ++i) {
      int p; cin >> p; --p; g1[p].pb(i - 1);
    }
    for (int i = 2; i <= n; ++i) {
      int p; cin >> p; --p; g2[p].pb(i - 1);
    }

    dfs1(0);
    ans = 0;
    dfs(0);
    cout << ans << "\n";


  }
}