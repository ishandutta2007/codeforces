#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;
#define int ll


const int INF = (int) 1e9;
const int N = (int) 1e5 + 7;
int n, a[N], sol[N];

mt19937 rng((long long) (new char));

void pr(int i, int j) {
  sol[i] = a[j];
  sol[j] = -a[i];
}

signed main() {
  ///ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  vector<vector<int>> all;
  int l = 1, cnt = 0;
  for (int a1 = -l; a1 <= l; a1++) for (int b1 = -l; b1 <= l; b1++) for (int c1 = -l; c1 <= l; c1++)
  for (int a2 = -l; a2 <= l; a2++) for (int b2 = -l; b2 <= l; b2++) for (int c2 = -l; c2 <= l; c2++)
  for (int a3 = -l; a3 <= l; a3++) for (int b3 = -l; b3 <= l; b3++) for (int c3 = -l; c3 <= l; c3++)
  {

    bool ok = 1;
    for (int it = 1; it <= 10; it++) {
      int a = rng() % 100, b = rng() % 100, c = rng() % 100;
      int x1 = a * a1 + b * b1 + c * c1;
      int x2 = a * a2 + b * b2 + c * c2;
      int x3 = a * a3 + b * b3 + c * c3;

      if (x1 * a + x2 * b + x3 * c != 0) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      all.push_back({a1, b1, c1, a2, b2, c2, a3, b3, c3});
    }
  }

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sol[i] = 0;
    }

    if (n % 2 == 0) {
      for (int i = 1; i + 1 <= n; i += 2) pr(i, i + 1);
    } else {
      for (int i = 4; i + 1 <= n; i += 2) pr(i, i + 1);
      int x = a[1], y = a[2], z = a[3], best = INF;
      for (auto &v : all) {
        int coefx = x * v[0] + y * v[1] + z * v[2];
        int coefy = x * v[3] + y * v[4] + z * v[5];
        int coefz = x * v[6] + y * v[7] + z * v[8];
        if (coefx == 0 || coefy == 0 || coefz == 0) continue;
        best = min(best, abs(coefx) + abs(coefy) + abs(coefz));
      }
      if (best == INF) assert(0);
      for (auto &v : all) {
        int coefx = x * v[0] + y * v[1] + z * v[2];
        int coefy = x * v[3] + y * v[4] + z * v[5];
        int coefz = x * v[6] + y * v[7] + z * v[8];
        if (coefx == 0 || coefy == 0 || coefz == 0) continue;
        if (best == abs(coefx) + abs(coefy) + abs(coefz)) {
          sol[1] = coefx;
          sol[2] = coefy;
          sol[3] = coefz;
          break;
        }
      }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i] * sol[i];
      assert(sol[i] != 0);
      cout << sol[i] << " ";
    }
    cout << "\n";
    assert(sum == 0);
  }

  return 0;
}
/**



**/