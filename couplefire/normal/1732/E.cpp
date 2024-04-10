#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;

const uint N = 5e4, T = 223;
const uint inf = ~0U;
uint n, q;
uint a[N], b[N];
uint p[N / T + 7][N + 7];
bool has[N + 7];
uint ans[N / T + 7];
uint lz[N / T + 7];

uint gcd(uint a, uint b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

uint calc(uint x, uint y) {
  uint g = gcd(x, y);
  return (x * y) / (g * g);
}

void pushdown(uint c) {
  if (!lz[c]) return;
  uint R = min(n, c * T + T);
  for (uint i = c * T; i < R; ++i) {
    a[i] = lz[c];
  }
  lz[c] = 0;
}

void update(uint c) {
  uint L = c * T, R = min(n, L + T);
  ans[c] = calc(a[L], b[L]);
  for (uint i = L + 1; i < R; ++i) {
    ans[c] = min(ans[c], calc(a[i], b[i]));
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(false);
  cin >> n >> q;
  for (uint i = 0; i < n; ++i) cin >> a[i];
  for (uint i = 0; i < n; ++i) cin >> b[i];

  for (uint i = 0; i < n; i += T) {
    for (uint j = 1; j <= N; ++j) {
      p[i / T][j] = inf;
    }
  }
  has[N + 1] = true;
  for (uint L = 0; L < n; L += T) {
    uint c = L / T, R = min(n, L + T);
    for (uint i = L; i < R; ++i) {
      has[b[i]] = true;
    }
    for (uint x = 1; x <= N; ++x) {
      uint f;
      for (f = x; f <= N; f += x) {
        if (has[f]) break;
      }
      if (f > N) continue;
      for (uint j = x; j <= N; j += x) {
        p[c][j] = min(p[c][j], (f*j) / (x*x));
      }
    }
    for (uint i = L; i < R; ++i) {
      has[b[i]] = false;
    }
  }

  for (uint i = 0; i < n; i += T) {
    ans[i / T] = inf;
  }
  for (uint i = 0; i < n; ++i) {
    ans[i / T] = min(ans[i / T], calc(a[i], b[i]));
  }

  while (q--) {
    uint op, l, r, x;
    cin >> op >> l >> r;
    --l, --r;
    if (op == 1) {
      cin >> x;
      if (l / T == r / T) {
        pushdown(l / T);
        for (uint i = l; i <= r; ++i) {
          a[i] = x;
        }
        update(l / T);
      } else {
        pushdown(l / T);
        pushdown(r / T);
        for (uint i = l; i / T == l / T; ++i) {
          a[i] = x;
        }
        for (uint i = r; i / T == r / T; --i) {
          a[i] = x;
        }
        update(l / T);
        update(r / T);
        for (uint c = l / T + 1; c < r / T; ++c) {
          lz[c] = x;
          ans[c] = p[c][x];
        }
      }
    } else { // op == 2 {
      uint ans = inf;
      if (l / T == r / T) {
        pushdown(l / T);
        for (uint i = l; i <= r; ++i) {
          ans = min(ans, calc(a[i], b[i]));
        }
      } else {
        pushdown(l / T);
        pushdown(r / T);
        for (uint i = l; i / T == l / T; ++i) {
          ans = min(ans, calc(a[i], b[i]));
        }
        for (uint i = r; i / T == r / T; --i) {
          ans = min(ans, calc(a[i], b[i]));
        }
        for (uint c = l / T + 1; c < r / T; ++c) {
          ans = min(ans, ::ans[c]);
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}