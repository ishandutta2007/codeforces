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

  vector<int> a(n), b(n);
  for (auto &x : a) {
    cin >> x;
    x--;
  }

  for (auto &x : b) {
    cin >> x;
    x--;
  }

  vector<int> ed(n);
  for (int i = 0; i < n; ++i) ed[a[i]] = b[i];

  int cnt = 0;
  vector<bool> used(n, false);

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    int W = i, S = i;
    cnt++;

    while (true) {
      used[W] = true;
      W = ed[W];
      if (W == S) break;
    }
  }

  cout << bp(2, cnt) << '\n';

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