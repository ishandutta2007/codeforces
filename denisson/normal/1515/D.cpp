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

int a[200007];
int b[200007];

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  
  int res = 0;

  for (int i = 0; i < l; ++i) {
    int x; cin >> x;
    a[x]++;
  }

  for (int i = 0; i < r; ++i) {
    int x; cin >> x;
    b[x]++;
  }

  int w1 = 0, w2 = 0;
  int f1 = 0, f2 = 0;

  for (int i = 1; i <= n; ++i) {
    if (a[i] > b[i]) {
      w1 += a[i] - b[i];
      f1 += (a[i] - b[i]) % 2;
    } else if (b[i] > a[i]) {
      w2 += b[i] - a[i];
      f2 += (b[i] - a[i]) % 2;
    }
    a[i] = 0; b[i] = 0;
  }

  res += min(w1, w2);
  if (w1 < w2) swap(w1, w2), swap(f1, f2);
  if (w1 > w2) {
    int w = w1 - w2;
    f1 -= w2;
    res += w / 2;
    res += max(f1, 0) / 2;
  }

  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
}