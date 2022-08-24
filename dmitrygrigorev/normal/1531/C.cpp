#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


const int N = 107;
int ans[107][107];

map<pair<int, int>, bool> Q;
bool get(int i, int j) {

  if (j < 0) return false;
  if (i == 0) return true;
  if (i == 2) return false;
  if (j == 0) return false;

  if (Q.count(mp(i, j))) return Q[mp(i, j)];

  for (int t = 1; t <= j; ++t) {

    if ((2*t-1) > i) {
      continue;
    }

    if (get(i - (2 * t - 1), t - 1)) {
      Q[mp(i, j)] = true;
      return Q[mp(i, j)];
    }
  }

  Q[mp(i, j)] = false;
  return Q[mp(i, j)];

}

void solve(int n, int lvl, int must) {
  int x = 1;
  while (!get(n, x)) x++;
  for (int i = 0; i < x; ++i) {
    ans[lvl][lvl+i] = 1;
    ans[lvl+i][lvl] = 1;
  }

  n -= (2*x - 1);
  if (n == 0) return;
  solve(n, lvl + 1, must);

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  if (n == 2) {
    cout << -1;
    exit(0);
  }
  
  int x = 1;
  while (!get(n, x)) x++;

  cout << x << endl;

  solve(n, 0, x);
  for (int i = x-1; i >= 0; --i) {
    for (int j = 0; j < x; ++j) {
      if (ans[i][j]) cout << 'o';
      else cout << '.';
    }
    cout << endl;
  }

}