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

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> b, c;
    for (int j = 0; j < n; ++j) {
      if (j%2==0) b.pb(a[j]);
      else c.pb(a[j]);
    }

    sort(all(b));
    sort(all(c));

    vector<int> t;
    for (int j = 0; j < n; ++j) {
      if (j%2==0) t.pb(b[j/2]);
      else t.pb(c[j/2]);
    }

    vector<int> q = t;
    sort(all(q));
    if (q==t) cout << "YES\n";
    else cout << "NO\n";
  }

}