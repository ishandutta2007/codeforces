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

const int N = 5000007;
pair<int, int> a[N];
pair<int, int> b[N];
pair<int, int> c[N];
pair<int, int> d[N];

int used[N];

void check(pair<int, int> &a, pair<int, int> &b) {
  if (a.x == 0 || b.x == 0) return;
  if (a.x == b.x || a.x == b.y || a.y == b.x || a.y == b.y) return;
  cout << "YES\n";
  cout << a.x << " " << a.y << " " << b.x << " " << b.y << '\n';
  exit(0);
}

int main(){
#ifdef LOCAL
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  n = min(n, 2000);
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int S = v[i] + v[j];
      if (used[S] == i+1) continue;
      used[S] = i+1;
      if (a[S] == mp(0, 0)) a[S] = mp(i+1, j+1);
      else if (b[S] == mp(0, 0)) b[S] = mp(i+1, j+1);
      else if (c[S] == mp(0, 0)) c[S] = mp(i+1, j+1);
      else if (d[S] == mp(0, 0)) d[S] = mp(i+1, j+1);
    }
  }

  for (int i = 0; i < N; ++i) {
    if (b[i].x != 0) check(a[i], b[i]);
    if (c[i].x != 0) check(a[i], c[i]);
    if (d[i].x != 0) check(a[i], d[i]);
    if (c[i].x != 0) check(b[i], c[i]);
    if (d[i].x != 0) check(b[i], d[i]);
    if (d[i].x != 0) check(c[i], d[i]);
  }

  cout << "NO";

}