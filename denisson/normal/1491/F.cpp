#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << ' = ' << (a) << endl; 

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

void solve() {
  cin >> n;
  int v = n;
  for (int i = 2; i < n; ++i) {
    cout << "? " << i - 1 << ' ' << 1 << endl;
    for (int j = 1; j < i; ++j) cout << j << ' ';
    cout << endl;
    cout << i << endl;
    int val;
    cin >> val;
    if (val != 0) {
      v = i;
      break;
    }
  }

  vector<int> res;

  for (int i = v + 1; i <= n; ++i) {
    cout << "? " << "1 1" << endl;
    cout << v << endl;
    cout << i << endl;
    int val;
    cin >> val;
    if (val == 0) {
      res.pb(i);
    }
  }

  int vl = 0, vr = v - 1;
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    cout << "? " << vm << ' ' << 1 << endl;
    for (int j = 1; j <= vm; ++j) cout << j << ' ';
    cout << endl << v << endl;
    int val;
    cin >> val;
    if (val != 0) vr = vm; else vl = vm;  
  }

  for (int i = 1; i < v; ++i) if (i != vr) res.pb(i);

  cout << "! " << res.size() << " ";
  for (int x : res) cout << x << ' ';
  cout << endl;
}

int main(){
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}