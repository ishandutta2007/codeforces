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
  
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
    x--;
  }

  vector<int> pos(n, -1);
  for (int i = 0; i < n; ++i) pos[v[i]] = i;
  vector<int> cnt(n, 0);

  for (int i = 0; i < n; ++i) {
    int delta = (pos[i] - i + n) % n;
    cnt[delta]++;
  }

  vector<int> ans;

  for (int i = 0; i < n; ++i) {
    if (cnt[i] >= n / 10) {
      vector<int> perm;
      for (int j = 0; j < n; ++j) {
        perm.pb((j - i + n) % n);
      }

      vector<int> pos_perm(n);
      for (int j = 0; j < n; ++j) pos_perm[perm[j]] = j;

      vector<int> ed(n);
      for (int j = 0; j < n; ++j) {
        ed[v[j]] = v[pos_perm[v[j]]];
      }

      int C = 0;
      vector<bool> used(n, false);

      for (int j = 0; j < n; ++j) {
        if (used[j]) continue;
        int cur = j;

        while (!used[cur]) {
          used[cur] = true;
          cur = ed[cur];
        }

        C++;
      }

      if (n - C <= m) ans.pb(i);

    }
  }

  cout << ans.size() << ' ';
  for (auto x : ans) cout << x << " ";
  cout << '\n';

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

  for (int i = 0; i < t; ++i) {
    
    solve();

  }

}