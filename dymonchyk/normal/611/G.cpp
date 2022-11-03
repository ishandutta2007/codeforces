#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int mod = 1000000007;
int x[500005], y[500005];

long long total = 0;

inline long long my(long long a) {
  return a > 0 ? a : -a;
}

void update(int &r, long long x) {
  r = ((r + x % mod) % mod + mod) % mod;
}

void update(long long &r, long long x) {
  r = ((r % mod + x % mod) % mod + mod) % mod;
}

int solve(int n, bool ls) {
  int ans = 0;

  int cur = 1;
  long long cs = 0, ss = 0, add = 0, cnt = 0;
  long long A = 0, B = 0, C = 0;
  for (int i = 0; i < n; ++i) {
    if (i == cur) {
      cur = (cur + 1) % n;
      cs = 0, ss = 0, add = 0, cnt = 0;
      A = 0, B = 0, C = 0;
    }
    long long last;
    while (true) {
      long long ns = cs;
      int pr = (cur + n - 1) % n;
      long long nw = 1LL * (x[cur] - x[pr]) * (0LL + y[cur] + y[pr]);
      ns += nw;
      last = 1LL * (x[i] - x[cur]) * (0LL + y[i] + y[cur]);
      ns += last;
      
      // cout << ns << endl;
      if (my(ns) < total / 2 || my(ns) == total / 2 && (ls || total % 2 == 1)) {
        update(add, nw);
        cs += nw;
        update(ss, add);
        update(A, x[cur]);
        update(B, 1LL * x[cur] * y[cur]);
        update(C, y[cur]);
        // cout << "Go:  " << ns << "  " << cur << " " << pr << endl;
        cur = (cur + 1) % n;
        ++cnt;
      } else {
        break;
      }
    }

    // cout << ss << endl;
    update(ans, (ss + (1LL * x[i] * y[i] % mod * cnt % mod - A % mod * y[i] % mod - B % mod + C % mod * x[i] % mod) % mod));
    // cout << "A: " << ans << "  " << (cur + n - 1) % n << "  " << cnt << endl;

    // update
    long long f = 1LL * (x[i + 1] - x[i]) * (0LL + y[i + 1] + y[i]);
    update(ss, -f % mod * cnt);
    update(add, -f);
    cs -= f;
    --cnt;
    update(A, -x[i + 1]);
    update(B, -1LL * x[i + 1] * y[i + 1] % mod);
    update(C, -y[i + 1]);
  }

  if (!ls) ans = mod - ans;

  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    x[i] += mod; y[i] += mod;
  }
  x[n] = x[0]; y[n] = y[0];

  for (int i = 0; i < n; ++i) {
    total += 1LL * (x[i + 1] - x[i]) * (0LL + y[i + 1] + y[i]);
  }
  total = my(total);
  // cout << total << endl;

  int ans = solve(n, true);

  reverse(x, x + n + 1);
  reverse(y, y + n + 1);
  ans = (ans + solve(n, false)) % mod;

  ans = (total % mod * (1LL * n * (n - 3) / 2 % mod) - ans) % mod;
  ans = (ans + mod) % mod;

  // ans = 0;
  // for (int i = 0; i < n; ++i) {
  //   long long s = 0;
  //   for (int j = 1; j + 1 < n; ++j) {
  //     int cur = (i + j) % n, pr = (cur + n - 1) % n;
  //     // int cur = (i - j + n) % n, pr = (cur + 1) % n;
  //     s += 1LL * (x[cur] - x[pr]) * (y[cur] + y[pr]);

  //     s += 1LL * (x[i] - x[cur]) * (y[i] + y[cur]);

  //     // cout << i << "  " << cur << "  " << pr << "  " << my(s) << "  " << total << endl;
  //     if (j > 1) {
  //       if (2 * my(s) <= total) {
  //         update(ans, total - 2 * my(s));
  //       } else {
  //         update(ans, 2 * my(s) - total);
  //       }
  //     }

  //     s -= 1LL * (x[i] - x[cur]) * (y[i] + y[cur]);
  //   }
  // }

  printf("%d\n", ans);

  return 0;
}