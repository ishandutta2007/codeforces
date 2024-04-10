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
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int ww = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i]; ww += a[i];
    }
    sort(all(a));
    if (x <= ww && (a[0] == a[n - 1] && x % a[0] == 0 || x == ww)) {cout << "NO\n"; continue; } else cout << "YES\n";
    int s = 0; int f=  0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      if (s == x && f == 0) f = 1, swap(a[i], a[n - 1]);
      cout << a[i] << ' ';
    }
    cout << "\n";
  }
}