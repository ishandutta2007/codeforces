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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  vector<int> l(n), r(n);
  l[0] = 1;

  for (int i = 1; i < n; ++i) {
    if (v[i-1] < v[i]) l[i] = l[i-1] + 1;
    else l[i] = 1;
  }

  r[n-1] = 1;
  for (int i = n-2; i >= 0; --i) {
    if (v[i+1] < v[i]) r[i] = r[i+1] + 1;
    else r[i] = 1;
  }

  int A = 0;
  for (auto x : l) A = max(A, x);
  for (auto x : r) A = max(A, x);

  bool can = true;
  int tl = -1, tr = -1;
  for (int i = 0; i < l.size(); ++i) {
    if (l[i] == A) {
      if (tl != -1) can = false;
      else tl = i;
    }
  }

  for (int i = 0; i < r.size(); ++i) {
    if (r[i] == A) {
      if (tr != -1) can = false;
      else tr = i;
    }
  }

  if (A % 2 == 0) can = false;
  if (tl != tr) can = false;

  if (can) cout << 1;
  else cout << 0;



}