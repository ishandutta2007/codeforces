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



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  vector<vector<int> > ans;
  for (int i = 0; i < n; ++i) {
    vector<int> tut;
    tut.assign(i+1, -1);

    ans.pb(tut);
  }

  int u = 0;

  while (v.size()) {

    for (int i = 0; i < v.size(); ++i) {
      ans[u+i][i] = v[i];
    }
    if (v.size() == 1) break;
    vector<bool> used(n, false);
    used[u] = true;

    vector<int> t;
    for (int j = 1; j < v.size(); ++j) {
      if (!used[v[j-1] - 1]) {
        used[v[j-1] - 1] = true;
        t.pb(v[j-1]);
      }
      else {
        used[v[j] - 1] = true;
        t.pb(v[j]);
      }
    }

    v = t;
    u++;

  }
  for (auto x : ans) {
    for (auto y : x) cout << y << " ";
    cout << '\n';
  }

}