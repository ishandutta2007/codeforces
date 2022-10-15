#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC optimize("O3")
///#pragma GCC optimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int smart(vector<int> v) {
  int s1 = 0, s2 = 0, pw = 1;
  for (auto &a : v) {
    int new_s1 = add(mul(2, s1), mul(pw, a));
    int new_s2 = add(mul(2, s2), add(mul(pw, mul(a, a)), mul(2, mul(a, s1))));
    int new_pw = mul(2, pw);
    s1 = new_s1;
    s2 = new_s2;
    pw = new_pw;
  }
  return s2;
}

struct T {
  int x0;
  int x1;
  int x2;
};

T operator + (T a, T b) {
  T c;
  c.x0 = ((ll) a.x0 * b.x0) % M;
  c.x1 = ((ll) a.x1 * b.x0 + (ll) a.x0 * b.x1) % M;
  c.x2 = ((ll) 2 * a.x1 * b.x1 + (ll) a.x2 * b.x0 + (ll) a.x0 * b.x2) % M;

  return c;
}


const int N = (int) 1e6 + 7;
int n, f[N], digit[7], sol[N], mx;
T rep[N][7], gol = {1, 0, 0};

signed realMain() {

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    f[x]++;
    mx = max(mx, x);
  }
  ll ret = 0;

  for (int num = mx; num >= 1; num--) {
    rep[num][6] = gol;
    for (int j = 1; j <= f[num]; j++) {
      T acum = {2, num, mul(num, num)};
      rep[num][6] = rep[num][6] + acum;
    }
    int cop = num;
    for (int i = 6; i >= 1; i--) {
      digit[i] = cop % 10;
      cop /= 10;
    }
    int p10 = 1;
    for (int pre = 5; pre >= 0; pre--) {
      rep[num][pre] = rep[num][pre + 1];
      if (digit[pre + 1] < 9) {
        if (num + p10 <= mx) {
          rep[num][pre] = rep[num][pre] + rep[num + p10][pre];
        }
      }
      p10 *= 10;
    }
    sol[num] = rep[num][0].x2;
    int now = 0;
    for (int mask = 0; mask < (1 << 6); mask++) {
      int sgn = 1;
      int nr = 0;
      for (int i = 0; i < 6; i++) {
        if (mask & (1 << i)) {
          if (digit[i + 1] == 9) {
            sgn = 0;
            break;
          }
          sgn *= -1;
          nr = 10 * nr + digit[i + 1] + 1;
        } else {
          nr = 10 * nr + digit[i + 1];
        }
      }
      if (sgn == 0) continue;
      now = add(now, sol[nr] * sgn);
    }
    if (now) {
      ret ^= (ll) num * now;
    }
  }
  cout << ret << "\n";
  return 0;
}