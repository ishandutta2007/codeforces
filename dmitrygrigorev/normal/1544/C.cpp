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

int get(vector<int> cnt) {

  int rem = 0;
  for (auto x : cnt) rem += x;
  rem -= rem / 4;

  int ans = 0;
  for (int i = cnt.size() - 1; i >= 0; --i) {
    ans += i * min(cnt[i], rem);
    rem -= min(cnt[i], rem);
  }

  return ans;

}

void solve() {
  int n;
  cin >> n;

  vector<int> we(101, 0), he(101, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    we[x]++;
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    he[x]++;
  }

  int L = -1, R = 1e6;
  while (R-L>1) {
    int M = (L+R)/2;
    we[100] += M;
    he[0] += M;

    if (get(we) >= get(he)) R = M;
    else L = M;

    we[100] -= M;
    he[0] -= M;
  }

  cout << R << '\n';

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