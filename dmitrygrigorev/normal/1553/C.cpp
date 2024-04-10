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

int ans;

void gen(string &s, int strike, int x, int y) {
  if (strike == 10) return;

  int remaining_first = (10 - strike) / 2;
  int remaning_second = (10 - strike) - remaining_first;

  if (x + remaining_first < y || y + remaning_second < x) {
    ans = min(ans, strike);
    return;
  }

  if (strike % 2 == 0) {
    if (s[strike] != '0') gen(s, strike + 1, x + 1, y);
    if (s[strike] != '1') gen(s, strike + 1, x, y);
  }
  else {
    if (s[strike] != '0') gen(s, strike + 1, x, y + 1);
    if (s[strike] != '1') gen(s, strike + 1, x, y);
  }

}

void solve() {
  
  string s;
  cin >> s;
  ans = 10;
  gen(s, 0, 0, 0);
  cout << ans << '\n';

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