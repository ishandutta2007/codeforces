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
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
    x--;
  }

  vector<int> ans(n, -1);
  vector<bool> used(n, false);

  int R = 0;

  for (int i = 0; i < n; ++i) {
    if (used[v[i]]) continue;
    R++;
    used[v[i]] = true;
    ans[i] = v[i];
  }

  if (R != n) {

    vector<pair<int, int> > chains;
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        int tut = i;
        while (ans[tut] != -1) tut = ans[tut];
        chains.pb(mp(i, tut));
      }
    }

    if (chains.size() == 1 && chains[0].x == chains[0].y) {
      int S = chains[0].x;
      for (int i = 0; i < n; ++i) if (ans[i] == v[S]) ans[i] = S;
      ans[S] = v[S];

    }

    else {

      for (int i = 0; i < chains.size(); ++i) {
        ans[chains[i].y] = chains[(i+1)%chains.size()].x;
      }

    }

  }

  cout << R << '\n';
  for (auto x : ans) cout << x+1 << " ";
  cout << '\n';

}

int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}