#include <bits/stdc++.h>

using namespace std;

const int ELON_MUSK = 3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882;
bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else {
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 1000 + 7;
const int E = N * N * 2;
int n, m, a[N], b[N], ret, c[N][N][2], ff[N], ss[N];
vector<int> g[E], ginv[E];
string s, t;
int dp[E];

void add_edge(int x, int y) {
  g[y].push_back(x);
  ginv[x].push_back(y);
}

signed realMain() {
  cin >> s >> t;
  n = (int) s.size();
  m = (int) t.size();
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - 'a';
  }
  for (int i = 1; i <= m; i++) {
    b[i] = t[i - 1] - 'a';
  }
  int y = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < 2; k++) {
        c[i][j][k] = ++y;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i >= 1) {
        if (a[i] != a[i - 1]) add_edge(c[i][j][0], c[i - 1][j][0]);
        if (a[i] != b[j]) add_edge(c[i][j][0], c[i - 1][j][1]);
      }
      if (j >= 1) {
        if (b[j] != a[i]) add_edge(c[i][j][1], c[i][j - 1][0]);
        if (b[j] != b[j - 1]) add_edge(c[i][j][1], c[i][j - 1][1]);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      ff[i] = ss[j] = 1;
      if (i + 1 <= n && a[i] != a[i + 1]) ff[i] = ff[i + 1] + 1;
      if (j + 1 <= m && b[j] != b[j + 1]) ss[j] = ss[j + 1] + 1;
      ret = add(ret, -ff[i]);
      ret = add(ret, -ss[j]);
    }
  }
  for (int l1 = 1; l1 <= n; l1++) {
    for (int l2 = 1; l2 <= m; l2++) {
      dp[c[l1][l2 - 1][0]] = 1;
      dp[c[l1 - 1][l2][1]] = 1;
    }
  }
  for (int i = 1; i <= y; i++) {
    for (auto &j : g[i]) {
      dp[j] = add(dp[j], dp[i]);
    }
  }
  for (int i = 1; i <= y; i++) {
    ret = add(ret, dp[i]);
  }
  cout << ret << "\n";
  return 0;
}