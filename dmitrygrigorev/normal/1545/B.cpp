#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

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

const int N = 200007;
int fact[N];
int rv[N];

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mult(fact[n], mult(rv[k], rv[n-k]));
}

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int sum = 0;
  int cnt = 0;
  int last = -1;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') continue;
    cnt++;

    if (last != -1) {
      if (i % 2 != last % 2) sum++;
      else sum += 2;
    }
    last = i;
  }

  if (cnt == 0) {
    cout << "1\n";
    return;
  }

  if (cnt == 1) {
    if (n % 2 == 0) {
      cout << n/2 << "\n";
      return;
    }
    if (last % 2 == 0) {
      cout << n-n/2 << "\n";
      return;
    }
    cout << n/2 << '\n';
    return;
  }

  cnt--;

  int ans = 0;

  for (int x = sum; x < n; x += 2) {
    int real_sum = (x - sum) / 2;
    int ways = C(real_sum + cnt - 1, cnt - 1);

    int can_be = n - x;
    if (can_be % 2 == 0) {
      add(ans, mult(ways, can_be / 2));
    }
    else {
      if (x % 2 == last % 2) {
        add(ans, mult(ways, can_be - can_be / 2));
      }
      else {
        add(ans, mult(ways, can_be / 2));
      }
    }

  }

  cout << ans << '\n';

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = mult(i, fact[i-1]);
  for (int i = 0; i < N; ++i) rv[i] = bp(fact[i], mod-2);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {

    solve();
  }

}