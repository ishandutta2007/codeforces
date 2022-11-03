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

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int w1 = 0, w2 = 0;
  for (int i = 0; i< n; ++i) cin >> a[i];
  for (int i = 0; i< n; ++i) {
    if (a[i] == 0) ++w1; else ++w2;
  }

  while (q--) {
    int t, v;
    cin >> t >> v;
    if (t == 1) {
      -- v;
      if (a[v] == 1) --w2;
       else --w1;
      a[v] = 1 - a[v];

      if (a[v] == 1) ++w2;
       else ++w1;
    } else {
      int k = v;
      if (k <= w2) cout << "1\n"; else cout << "0\n";
    }
  }

}