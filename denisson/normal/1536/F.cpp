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

int n;
int fac[1000007];
int ifac[1000007];

int cnk(int n, int k) {
  if (k > n) return 0; 
  return mult(fac[n], mult(ifac[k], ifac[n - k]));
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fac[0] = 1;
  for (int i = 1; i < 1000007; ++i) fac[i] = mult(fac[i - 1], i);
  for (int i = 0; i < 1000007; ++i) ifac[i] = bp(fac[i], mod - 2);

  cin >> n;
  int res = 0;

  for (int i = 0; i < n; ++i) {
    if ((n - i) % 2 == 1) continue;
    if (!(2 * i <= n)) continue;
    int now = 0;
    if (i == 0) {
      now = 1;
    } else {
      add(now, cnk(n - 1 - (i), i - 1));
      add(now, cnk(n - i, i));
    }
    now = mult(now, fac[n - i]);
    add(res, now);
   // cout << i << ' ' << now << endl;
  }

  cout << mult(2, res);
}