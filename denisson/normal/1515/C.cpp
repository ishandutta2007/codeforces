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


int m, n, x;
int a[100007];
int ans[100007];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt; cin >> tt;
  while (tt--) {

    cin >> m >> n >> x;
    vector<pair<int,int>> t;
    for (int i = 0; i < m; ++i) cin >> a[i], t.pb(mp(a[i], i));

    sort(all(t));
    reverse(all(t));

    set<pair<int, int>> se; for (int i = 0; i < n; ++i) se.insert(mp(0, i));

    for (auto [w, v] : t) {
      auto now = *se.begin(); se.erase(se.begin());
      ans[v] = now.y + 1;
      se.insert(mp(now.x + w, now.y));
    }

    cout << "YES\n";
    for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
    cout << "\n";
  }

}