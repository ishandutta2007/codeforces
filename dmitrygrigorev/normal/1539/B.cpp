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

const int N = 100007;
int pref[N][26];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) pref[i+1][j] = pref[i][j];
    pref[i+1][s[i] - 'a']++;
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    ll ans = 0;
    for (int j = 0; j < 26; ++j) {
      ans += (ll) (j+1) * (pref[r][j] - pref[l-1][j]);
    }
    cout << ans << '\n';
  }



}