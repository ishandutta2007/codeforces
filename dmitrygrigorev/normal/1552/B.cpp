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

const int N = 50007;
int matrix[N][5];

int get(int x, int y) {
  int a = 0;
  for (int i = 0; i < 5; ++i) if (matrix[x][i] < matrix[y][i]) a++;
  if (a >= 3) return x;
  return y;
}

void solve() {

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) for (int j = 0; j < 5; ++j) cin >> matrix[i][j];

  int cur = 0;
  for (int i = 1; i < n; ++i) {
    cur = get(cur, i);
  }

  for (int i = 0; i < n; ++i) {
    if (i == cur) continue;
    if (get(i, cur) == i) {
      cout << "-1\n";
      return;
    }
  }

  cout << cur+1 << '\n';

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}