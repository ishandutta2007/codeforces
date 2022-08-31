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

void solve() {

  int n, k;
  cin >> n >> k;

  vector<pair<int, int> > v(n);
  vector<bool> used(2*n, false);

  for (int i = 0; i < k; ++i) {
    cin >> v[i].x >> v[i].y;
    v[i].x--, v[i].y--;
    used[v[i].x] = true;
    used[v[i].y] = true;
  }

  vector<int> rem;
  for (int i = 0; i < 2*n; ++i) if (!used[i]) rem.pb(i);

  for (int i = 0; i < rem.size() / 2; ++i) {
    v[k + i] = mp(rem[i], rem[i + rem.size() / 2]);
  }

  int ans = 0;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i+1; j < v.size(); ++j) {
      if (v[i].x > v[i].y) swap(v[i].x, v[i].y);
      if (v[j].x > v[j].y) swap(v[j].x, v[j].y);

      if (v[j].x > v[i].x && v[j].y < v[i].y) continue;
      if (v[i].x > v[j].x && v[i].y < v[j].y) continue;
      if (v[j].x > v[i].y) continue;
      if (v[i].x > v[j].y) continue;

      //cout << v[i].x << " " << v[i].y << " " << v[j].x << " " << v[j].y << endl;
      ans++;

    }
  }

  cout << ans << '\n';

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